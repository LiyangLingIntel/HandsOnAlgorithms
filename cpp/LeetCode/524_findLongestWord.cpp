// 给你一个字符串 s 和一个字符串数组 dictionary
// 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s
// 中的某些字符得到。
// 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
// 示例 1：
// 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// 输出："apple"
// 示例 2：
// 输入：s = "abpcplea", dictionary = ["a","b","c"]
// 输出："a"

#include "00_commonHeader.hpp"

class Solution {
  public:
    bool isSubString(string s, string d) {
        int i = 0, j = 0;
        while (i < s.size() && j < d.size()) {
            if (s[i++] == d[j]) {
                ++j;
            }
        }
        if (j == d.size()) {
            return true;
        } else {
            return false;
        }
    }

    string findLongestWord(string s, vector<string> &dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string lhs, string rhs) {
            if (lhs.size() == rhs.size()) {
                return lhs < rhs;
            }
            return lhs.size() > rhs.size();
        });
        for (auto candidate : dictionary) {
            if (isSubString(s, candidate))
                return candidate;
        }
        return "";
    }
};