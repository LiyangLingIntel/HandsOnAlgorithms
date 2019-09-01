/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 相比 153, 这题的难点在于如果首尾以及中点都一样, 那么就无法判断断点在前后哪一部分, 
// 所以对这种情况只能采用 顺序查找的方法. 
class Solution {
public:
    
    int seqSearchMin(vector<int>& nums, int idS, int idE) {
        int res = nums[idS];
        
        for (int i=idS+1; i<=idE; i++) {
            if (nums[i] >= res)
                res = nums[i];
            else
                return nums[i];
        }
        return res;
    }
    
    int findMin(vector<int>& nums) {
        int N = nums.size();
        if (N == 0){
            return NULL;
        }
        
        int idStart = 0;
        int idEnd = N -1;
        int idMid = idStart;    // 保证如果数组是顺序的，能返回第一个元素 
        
        while (nums[idStart] >= nums[idEnd]) {
            if (idEnd - idStart == 1){
                idMid = idEnd;
                break;
            }
            idMid = (idStart + idEnd) / 2;
            
            if (nums[idStart] > nums[idMid])
                idEnd = idMid;
            else if(nums[idEnd] < nums[idMid])
                idStart = idMid;
            else if (nums[idStart]==nums[idMid] && nums[idEnd]==nums[idMid])
                return seqSearchMin(nums, idStart, idEnd);
        }
        return nums[idMid];
    }
};