import numpy as np
from radix_utils import RadixUtil, RadixPolicy
from histogram import HistogramSequential
from exclusive_sum import ExclusiveSumSequential
from onesweep import OneSweepSort


def invoke(input):

    # ========== initialization ===========
    num_items = np.prod(input.shape)
    max_bits = input.dtype.alighment * 8
    radix_bits = RadixPolicy.RADIX_BITS
    radix_status = RadixPolicy.RADIX_STATUS
    tile_items = RadixPolicy.OnesweepPolicy.ITEMS_PER_THREAD * \
        RadixPolicy.OneSweepSort.BLOCK_THREADS
    portion_size = 1 << 4 // tile_items * tile_items
    num_passes = np.ceil(max_bits / radix_bits).astype(np.int32)
    num_portions = np.ceil(num_items / portion_size)
    max_num_blocks = np.ceil(np.minimum(num_items, portion_size) / tile_items)

    # example allocations (not necessary for python)
    d_bins = np.zeros([num_portions, num_passes, radix_status], np.int32)
    d_lookback = np.zeros([max_num_blocks, radix_status], np.int32)
    d_counters = np.zeros([num_portions, num_passes], np.int32)
    d_keys_out = np.zeros([num_items], input.dtype)
    d_values_out = np.zeros([num_items], input.dtype)

    # ====== Upfront Histogram Kernel ======
    histogram_kernel = HistogramSequential(max_bits, radix_bits)
    d_bins = histogram_kernel(input)

    # ======== Exclusive Sum Kernel ========
    exclusive_sum_kernel = ExclusiveSumSequential(histogram_kernel)
    d_bins = exclusive_sum_kernel(d_bins)

    # === OneSweep - Chained Scan digit-binning Kernel ===
    curr_bit = 0
    for p in range(num_passes):
        if curr_bit >= max_bits:
            break
        num_bits = np.minimum(max_bits - curr_bit, radix_bits)
        for portion in range(num_portions):
            num_portion_items = np.minimum(
                num_items-portion*portion_size, portion_size)
            num_blocks = np.ceil(num_portion_items, tile_items)

            onesweep_kernel = OneSweepSort(
                p,
                portion,
                num_blocks,
                RadixPolicy.OnesweepPolicy.BLOCK_THREADS,
                RadixPolicy.OnesweepPolicy.ITEMS_PER_THREAD,
                num_portion_items,
                max_bits,
                curr_bit,
                num_bits
            )
            d_keys_out, d_values_out = onesweep_kernel(
                input,
                d_bins,
                d_lookback,
                d_counters,
            )
        curr_bit += num_bits

    return d_keys_out, d_values_out


if __name__ == '__main__':
    np.random.seed(2023)
    input = np.random.randint(low=0, high=100, size=64, dtype=np.int32)
    sorted_val, sorted_idx = invoke(input)
    print("# RadixSort result:")
    print(sorted_val)
    print(sorted_idx)
    