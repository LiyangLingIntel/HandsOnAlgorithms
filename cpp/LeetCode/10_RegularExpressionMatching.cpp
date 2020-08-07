// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.
// Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:

// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
// Example 5:

// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false

#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    //  DP Based Solution
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));

        // Empty pattern always matches an empty text!
        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            // dp[i][j] represents if p[:i] could match string s[:j] or not
            for (int j = 0; j <= m; ++j) {
                // start from 0 here means empty text can match a pattern like "a*b*"
                // convert length to index
                int ii = i - 1;
                int jj = j - 1;

                if (p[ii] == '*') {
                    dp[i][j] = dp[i - 2][j];    // BUGGY: * cannot be the first character

                    if (jj >= 0 && (p[ii - 1] == s[jj] || p[ii - 1] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                } else {
                    dp[i][j] = jj >= 0 && (p[ii] == s[jj] || p[ii] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};
