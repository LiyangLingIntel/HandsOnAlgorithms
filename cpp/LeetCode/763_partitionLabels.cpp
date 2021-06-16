// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
// 同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

#include "00_commonHeader.hpp"

class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> partition;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastPos[s[i] - 'a']);
            if (end == i) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};