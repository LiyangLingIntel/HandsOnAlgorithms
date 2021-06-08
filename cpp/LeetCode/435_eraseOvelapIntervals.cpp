// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

// 注意:
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

#include "00_commonHeader.hpp"

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(),
             [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
        int arrows = 1;
        int prev_end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (prev_end >= points[i][0]) {
                continue;
            }
            prev_end = points[i][1];
            arrows++;
        }
        return arrows;
    }
};