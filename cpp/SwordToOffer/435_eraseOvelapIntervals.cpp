// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

// 注意:
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

#include "00_commonHeader.hpp"

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(),
             [](vector<int> lhs, vector<int> rhs) { return lhs[1] < rhs[1]; });
        int rm_count = 0;
        auto pre_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < pre_end) {
                ++rm_count;
            } else {
                pre_end = intervals[i][1];
            }
        }
        return rm_count;
    }
};