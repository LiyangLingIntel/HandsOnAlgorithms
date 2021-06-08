// 给你一个长度为 n 的整数数组，请你判断在 最多 改变 1
// 个元素的情况下，该数组能否变成一个非递减数列。

// 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足
// nums[i] <= nums[i + 1]。

#include "00_commonHeader.hpp"

class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        if (nums.empty()) {
            return true;
        }
        bool modified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (modified) {
                    return false;
                }
                modified = true;
                if (i > 1 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};