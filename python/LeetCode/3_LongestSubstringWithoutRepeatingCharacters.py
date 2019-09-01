"""
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        s_dic = {}
        length = 0
        start = -1
        for i in range(len(s)):
            if s_dic.get(s[i], -1) > start:
                start = s_dic[s[i]]
            s_dic[s[i]] = i
            length = max(length, i - start)
        return length


if __name__ == '__main__':

    inputs = ["abcabcbb", "bbbbb", "pwwkew"]
    s = Solution()
    for string in inputs:
        print(s.lengthOfLongestSubstring(string))