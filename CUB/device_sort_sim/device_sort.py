import numpy as np
from radix_utils import RadixUtil, RadixPolicy
from histogram import HistogramSequential
from exclusive_sum import ExclusiveSumSequential
from onesweep import OneSweepSort


def invoke(input):

    # ========== initialization ===========
    max_bits = input.dtype.alighment * 8
    radix_bits = RadixPolicy.RADIX_BITS
    radix_status = RadixPolicy.RADIX_STATUS
    portion_size = 1 << 4 // RadixPolicy.OnesweepPolicy.TILE_ITEMS * \
        RadixPolicy.OnesweepPolicy.TILE_ITEMS
    num_passes = np.ceil(max_bits / radix_bits).astype(np.int32)
    num_portions = np.ceil(np.prod(input.shape) / portion_size)

    # example allocations (not necessary for python)
    d_bins = np.zeros([num_portions, num_passes, radix_status], np.int32)

    # ====== Upfront Histogram Kernel ======
    histogram_kernel = HistogramSequential(max_bits, radix_bits)
    d_bins = histogram_kernel(input)

    # ======== Exclusive Sum Kernel ========
    exclusive_sum_kernel = ExclusiveSumSequential(histogram_kernel)
    d_bins = exclusive_sum_kernel(d_bins)

    # === OneSweep - Chained Scan digit-binning Kernel ===
