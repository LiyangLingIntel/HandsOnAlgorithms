import numpy as numpy


class RadixUtil:
    def __init__(self, max_bits=32, radix_bits=8):
        self.max_bits = max_bits
        self.radix_bits = radix_bits

    def extract_bits(self, key, curr_pos):
        offset = curr_pos * self.radix_bits
        mask = 1 << (offset + 1) - 1
        extracted = key >> offset & mask
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
