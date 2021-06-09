// 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

#include "00_commonHeader.hpp"

class Solution {
  public:
    bool isPalindrome(string s, int &i, int &j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        if (isPalindrome(s, i, j)) {
            return true;
        } else {
            return isPalindrome(s, ++i, j) || isPalindrome(s, --i, --j);
        }
    }
};