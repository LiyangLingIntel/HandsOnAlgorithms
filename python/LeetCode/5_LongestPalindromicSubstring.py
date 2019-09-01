"""
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
"""


class Solution:
    def get_palindrome(self, s, left, right):
        """
        left & right are indexs of potential palindrome string
        """
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1: right]

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        pld = ''
        for i in range(len(s)):
            # length is odd
            potent = self.get_palindrome(s, i, i)
            pld = potent if len(potent) > len(pld) else pld
            # length is even
            potent = self.get_palindrome(s, i, i + 1)
            pld = potent if len(potent) > len(pld) else pld

        return pld


if __name__ == '__main__':

    s = ''
    pld = Solution().longestPalindrome(s)
    print(pld)
