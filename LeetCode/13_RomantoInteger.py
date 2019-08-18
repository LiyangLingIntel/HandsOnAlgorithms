class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman2num = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

        num = 0
        for i in range(len(s) - 1):
            if roman2num[s[i]] < roman2num[s[i + 1]]:
                num -= roman2num[s[i]]
            else:
                num += roman2num[s[i]]
        num += roman2num[s[-1]]

        return num