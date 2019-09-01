"""
7. Reverse Integer
Easy

1853

2658

Favorite

Share
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
"""

class Solution:

    # Note: 32-bit signed integer
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = '-' if x < 0 else ''
        res = int(sign + str(abs(x))[::-1])
        return res if abs(res) < 2**31 else 0

if __name__ == '__main__':

    x = 153423

    res = Solution().reverse(x)
    print(res)