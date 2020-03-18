// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> permute;
        vector<bool> used(nums.size(), false);
        if(nums.empty())
            return res;
        permutation(res, nums, permute, used);
        return res;
    }
    
    void permutation(vector<vector<int> > &res, vector<int>& nums, vector<int>& permute, vector<bool>& used) {
        if(permute.size() == nums.size()) {
            res.push_back(permute);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i])
                continue;
            permute.push_back(nums[i]);
            used[i] = true;
            permutation(res, nums, permute, used);
            used[i] = false;
            permute.pop_back();
        }
    }
};
