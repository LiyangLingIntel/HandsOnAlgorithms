import numpy as numpy


class RadixUtil:
    def __init__(self, max_bits, num_bits):
        self.max_bits = max_bits
        self.radix_bits = radix_bits

    def extract_bits(self, key, curr_bit):
        target_bits = self.radix_bits
        if self.max_bits - curr_bit > self.radix_bits:
            target_bits = self.max_bits - curr_bit
        offset = curr_bit
        mask = (1 << (offset + target_bits)) - 1
        extracted = (key >> offset) & mask
        return extracted

    def twiddle_in(self, key):
        pass

    def twiddle_out(self, key):
        pass


class RadixPolicy:
    RADIX_BITS = 8
    RADIX_STATUS = 1 << RADIX_BITS
    HistogramPolicy = {}
    ExculisveSumPolicy = {}

    class OnesweepPolicy:
        ITEMS_PER_THREAD = 2
        BLOCK_THREADS = 2
