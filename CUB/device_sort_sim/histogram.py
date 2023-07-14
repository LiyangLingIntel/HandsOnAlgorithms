# Upfront histogram kernel
# This Kernel computes global digit histogram fot all digit places.
#
# This file provice 2 implementations for histogram:
# 1. single thread for providing corrent result
# 2. parallel impl for validating understanding

import numpy as np
from radix_utils import RadixUtil


class HistogramSequential:
    def __init__(self, max_bits, radix_bit):
        self.max_bits = max_bits
        self.radix_bits = radix_bits
        self.radix_status = 1 << self.radix_bits
        self.passes = self.max_bits / self.radix_bits
        self.bins = np.zeros([self.passes, self.radix_status], np.int32)
        self.radix = RadixUtil(self.max_bits, self.radix_bits)

    def __call__(self, keys):
        curr_bits = 0
        for p in range(self.passes):
            if curr_bits >= self.max_bits:
                break
            for key in keys:
                bits = self.radix.extract_bits(key, p)
                self.bins[p][bits] += 1
            curr_bits += self.radix_bits
        return self.bins


class HistogramParallel:

    def __init__(self, max_bits=32, radix_bits=8):
        self.max_bits = max_bits
        self.radix_bits = radix_bits
        self.radix_status = 1 << self.radix_bits
        self.passes = self.max_bits / self.radix_bits
        self.bins = np.zeros([self.passes, self.radix_status], np.int32)
        self.radix = RadixUtil(self.max_bits, self.radix_bits)
