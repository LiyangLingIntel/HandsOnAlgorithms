
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。

#include "00_commonHeader.hpp"

// 思路: 双指针前后遍历
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int N = array.size();
        vector<int> res;
        if (N < 2)
            return res;
        int pb = 0;
        int pe = N-1;
        while(pb < pe) {
            int tmpSum = array[pb] + array[pe];
            if (tmpSum == sum) {
                res.push_back(array[pb]);
                res.push_back(array[pe]);
                break;
            }
            else if(tmpSum > sum)
                pe--;
            else
                pb++;
        }
        return res;
    }
};