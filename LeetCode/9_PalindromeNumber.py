"""
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
"""


class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        l = len(x) - 1
        for i in range(len(x) // 2):
            if x[i] != x[l - i]:
                return False
        return True


if __name__ == '__main__':
    x = -11
    print(Solution().isPalindrome(x))