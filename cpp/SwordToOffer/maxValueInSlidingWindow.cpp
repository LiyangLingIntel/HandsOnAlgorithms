/*
滑动窗口中的最大值
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

#include "00_commonHeader.hpp"

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int N = num.size();
        std::list<int> maxWindow; // 只存当前window最大的值 & 新来的一个值
        std::vector<int> res;
        
        for(int i=0; i < N; i++){
            // 移除maxWindows中 较小的值
            while(!maxWindow.empty() && num[i] > num[*maxWindow.rbegin()]){
                maxWindow.pop_back();
            }
            
            maxWindow.push_back(i);
            
            while(!maxWindow.empty() && *maxWindow.begin() <= i-size){
                maxWindow.pop_front();
            }
            if(i >= (size - 1))
                res.push_back(num[*maxWindow.begin()]);
        }
        return res;
    }
};