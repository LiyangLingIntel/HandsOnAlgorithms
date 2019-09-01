"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
"""


class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        li = [[] for i in range(numRows)]
        turn_num = numRows - 1
        mod = 2 * (numRows - 1)

        if turn_num == 0:
            return s

        for i in range(len(s)):
            # for j in range(numRows):
            num = i % mod
            if num <= turn_num:
                li[num].append(s[i])
            else:
                li[mod - num].append(s[i])

        output = ''.join([''.join(l) for l in li])
        return output


if __name__ == '__main__':

    s = 'PAYPALISHIRING'
    n = 15

    result = Solution().convert(s, n)
    print(result)