# Upfront exclusive_sum kernel
# This Kernel computes a separate exclusive prefix sum across
# each of the global digit histograms, one per binning iteration.
#
# This file provice 2 implementations for exclusive_sum:
# 1. single thread for providing corrent result
# 2. parallel impl for validating understanding

import numpy as np


class ExclusiveSumSequential:
    def __init__(self, histogram):
        self.passes = histogram.passes
        self.radix_bits = histogram.radix_bits
        self.radix_status = histogram.radix_status

    # exclusive prefix sum
    def __call__(bins):
        dtype = bins.dtype
        res_sum = np.zeros([self.passes, self.radix_status], dtype)
        for p in range(self.passes):
            for r in range(1, self.radix_status):
                res_sum[p][r] = res_sum[p][r-1] + bins[p][r-1]

        return res_sum
