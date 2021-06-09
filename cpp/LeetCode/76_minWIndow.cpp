// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
// 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

#include "00_commonHeader.hpp"

class Solution {
  public:
    string minWindow(string S, string T) {
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);
        // 先统计T中的字符情况
        for (int i = 0; i < T.size(); ++i) {
            flag[T[i]] = true;
            ++chars[T[i]];
        }
        // 移动滑动窗口，不断更改统计数据
        int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
        for (int r = 0; r < S.size(); ++r) {
            if (flag[S[r]]) {
                if (--chars[S[r]] >= 0) {
                    ++cnt;
                }
                // 若目前滑动窗口已包含T中全部字符，
                // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
                while (cnt == T.size()) {
                    if (r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    if (flag[S[l]] && ++chars[S[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > S.size() ? "" : S.substr(min_l, min_size);
    }
};