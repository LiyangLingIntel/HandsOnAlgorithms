// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

#include "00_commonHeader.hpp"
#include <multiset>

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

        // // Solution 1: O(nlogn)
        // vector<int> res;
        // if(input.empty()||k>input.size())
        //     return res;
        
        // sort(input.begin(), input.end());
        // for(int i=0; i<k; i++){
        //     res.push_back(input[i]);
        // }
        // return res;

        vector<int> res;
        if(input.empty() || k < 1 || input.size() < k)
            return res;
        
        multiset<int, greater<int> > least_nums;
        for(vector<int>::iterator iter = input.begin(); iter<input.end(); iter++){
            if(least_nums.size() < k)
                least_nums.insert(*iter);
            else {
                int max_num = *least_nums.begin();
                if(*iter < max_num){
                    least_nums.erase(least_nums.begin());
                    least_nums.insert(*iter);
                }
            }
        }
        return vector<int>(least_nums.begin(), least_nums.end());
    }
};