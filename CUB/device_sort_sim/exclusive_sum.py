# Upfront exclusive_sum kernel
# This Kernel computes a separate exclusive prefix sum across each of the global digit histograms, one per binning iteration.
#
# This file provice 2 implementations for exclusive_sum:
# 1. single thread for providing corrent result
# 2. parallel impl for validating understanding

import numpy as np


class ExclusiveSumSequential:
    def __init__(self):
        pass

    def prefix_sum(histogram):
        
