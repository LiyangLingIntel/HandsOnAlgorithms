/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array 
to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. Return the max sliding window.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        list<int> maxWindow; // 只存当前window最大的值 & 新来的一个值
        vector<int> res;
        
        if (k == 0)
            return res;
        
        for(int i=0; i < N; i++){
            // 移除maxWindows中 较小的值
            while(!maxWindow.empty() && nums[i] > nums[*maxWindow.rbegin()]){
                maxWindow.pop_back();
            }
            
            maxWindow.push_back(i);
            
            while(!maxWindow.empty() && *maxWindow.begin() <= i-k){
                maxWindow.pop_front();
            }
            if(i >= (k - 1))
                res.push_back(nums[*maxWindow.begin()]);
        }
        return res;
    }
};