// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if (nums.size() == 0)
            return -1;
        
        auto n = nums.size();
        int count = 0;
        auto candi = nums[0];
        for(auto i : nums) {
            if(i==candi)
                count++;
            else if (i!=candi) {
                if(count!=0)
                    count--;
                else{
                    count++;
                    candi = i;
                }
            }
        }
        if (count > 0)
            return candi;
        return -1;
    }
};