/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
    // 思想还是二分查找, 通过二分去找到断层点, 达到O(logn)的效率
    int findMin(vector<int>& nums) {
        
        int N = nums.size();
        if (N == 0){
            return NULL;
        }
        
        int idStart = 0;
        int idEnd = N -1;
        int idMid = idStart;    // 保证如果数组是顺序的，能返回第一个元素 
        
        while (nums[idStart] > nums[idEnd]) {
            if (idEnd - idStart == 1){
                idMid = idEnd;
                break;
            }
            idMid = (idStart + idEnd) / 2;
            
            if (nums[idStart] > nums[idMid])
                idEnd = idMid;
            else if(nums[idEnd] < nums[idMid])
                idStart = idMid;
        }
        return nums[idMid];
    }
};