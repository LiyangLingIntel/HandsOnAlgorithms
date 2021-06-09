// 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

#include "00_commonHeader.hpp"

class Solution {
  public:
    bool judgeSquareSum(int c) {
        long i = 0;
        long j = static_cast<long>(std::sqrt(c));
        while (i <= j) {
            long res = i * i + j * j;
            if (res == c)
                return true;
            if (res < c)
                ++i;
            else
                --j;
        }
        return false;
    }
};