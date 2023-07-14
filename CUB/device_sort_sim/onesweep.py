import numpy as np
from radix_utils import RadixUtil, RadixPolicy


class SharedStorage:

    def __init__(self, tile_items, radix_digits, datatype):
        # keys_out, values_out, rank_temp_storage share the same memory space
        self.keys_out = np.zeros([tile_items], dtype=datatype)
        # global_offsets[0] is block_idx
        self.global_offsets = np.zeros([radix_digits], np.int32)


class BlockScan:
    pass


class BlockRadixSort:

    def __init__(self, ):
        pass

    def rank_keys():
        pass


class OneSweepSort:

    def __init__(self, pass_id, portion_id, num_blocks, num_block_threads, items_per_thread, num_portion_items, max_bits, curr_bit, num_bits):
        self.pass_id = pass_id
        self.portion_id = portion_id
        self.num_blocks = num_blocks
        self.num_block_threads = num_block_threads
        self.items_per_thread = items_per_thread
        self.tile_items = num_block_threads * items_per_thread
        self.bins_per_thread = np.ceil(
            RadixPolicy.RADIX_STATUS / num_block_threads)

        self.num_items = num_portion_items
        self.max_bits = max_bits
        self.curr_bit = curr_bit
        self.num_bits = num_bits

        self.lookback_partial_mask = 1 << (
            np.dtype(np.int32).alignment * 8 - 2)
        self.lookback_global_mask = 1 << (np.dtype(np.int32).alignment * 8 - 1)
        self.lookback_kind_mask = self.lookback_partial_mask | self.lookback_global_mask
        self.lookback_value_mask = ~self.lookback_kind_mask

        self.radix_util = RadixUtil(max_bits, num_bits)

    def __call__(self, d_keys, d_bins, d_lookback, d_counters):
        self.d_keys = d_keys
        self.d_bins = d_bins
        self.d_lookback = d_lookback
        self.d_counters = d_counters
        self.s = SharedStorage(
            self.tile_items, RadixPolicy.RADIX_STATUS, d_keys.dtype)

        for bid in range(self.num_blocks):
            for tid in range(self.num_block_threads):
                self.thread_run(tid, bid)

    def thread_run(self, thread_id, block_id):
        # ======== Initialization =========
        if thread_id == 0:
            self.d_counters[self.portion_id][self.pass_id] += 1
            self.s.global_offsets[0] = self.d_counters[self.portion_id][self.pass_id]
        self.block_idx = self.s.global_offsets[0]
        self.is_full_block = ((self.block_idx + 1) *
                              self.tile_items) <= self.num_items

        # ======== Load keys =========
        block_offset = self.block_idx * self.tile_items
        thread_offset = thread_id * self.items_per_thread
        keys = self.d_keys[block_offset + thread_offset: block_offset +
                           thread_offset + self.items_per_thread]
        keys = [self.radix_util.extract_bits(x, self.curr_bit) for x in keys]

        # ======== Rank keys =========
        ranks = np.zeros([self.items_per_thread])
        exclusive_digit_prefix = np.zeros([self.bins_per_thread])
        bins = np.zeros([self.bins_per_thread])

        # ======== Scatter keys in shared ========

        # ======== Compute global offset =========

        # ======== Scatter keys in global ========

        # ======== Scatter values(index) =========
