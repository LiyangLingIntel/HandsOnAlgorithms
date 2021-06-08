// 给定一个已按照 升序排列 
// 的整数数组 numbers，请你从数组中找出两个数满足相加之和等于目标数 target 。
// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1
// 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <=
// numbers.length。
// 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

#include "00_commonHeader.hpp"

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            auto sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            }
            if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};