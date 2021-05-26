
/*
题目描述
统计一个数字在排序数组中出现的次数。
*/

#include "00_commonHeader.hpp"

class Solution {
public:
    int getFirstK(vector<int> data, int k, int n) {
        int start = 0;
        int end = n-1;
        int mid = (start + end) / 2;
        
        while (end >= start) {
            if (data[mid] < k)
                start = mid + 1;
            else
                end = mid -1;
            mid = (start + end) / 2;
        }
        return start;
    }
    
    int getLastK(vector<int> data, int k, int n) {
        int start = 0;
        int end = n-1;
        int mid = (start + end) / 2;
        
        while (end >= start) {
            if (data[mid] > k)
                end = mid - 1;
            else
                start = mid + 1;
            mid = (start + end) / 2;
        }
        return end;
    }
    
    int GetNumberOfK(vector<int> data ,int k) {
        int N = data.size();
        int number = 0;

        if (N > 0) {
            int firstIdx = getFirstK(data, k, N);
            int lastIdx = getLastK(data, k, N);
            number = lastIdx - firstIdx + 1;
        }
        return number;
    }
};