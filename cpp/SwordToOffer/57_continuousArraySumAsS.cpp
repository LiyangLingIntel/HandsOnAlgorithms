// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
// 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
// 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

#include "00_commonHeader.hpp"

// 思路还是双指针, 前后两指针分别递增, 确定window size.
// 如果当前sum大于目标, 就增加 small;
// 反之则增大 big.
class Solution {
public:
    vector<int> initRangedVector(int start, int end) {
        vector<int> res;
        for (int i=start; i<=end; i++)
            res.push_back(i);
        return res;
    }
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if (sum < 3)
            res;
        
        int small = 1;
        int big = 2;
        int bound = (1+sum) / 2;
        int currSum = small + big;
        
        while (small < bound) {
            if (currSum == sum) {
                vector<int> stageRes = initRangedVector(small, big);
                res.push_back(stageRes);
            }
            while (currSum > sum && small < bound) {
                currSum -= small;
                small++;
                if (currSum == sum) {
                    vector<int> stageRes = initRangedVector(small, big);
                    res.push_back(stageRes);
                }
            }
            big++;
            currSum += big;
        }
        return res;
    }
};