class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        num2roman = {
            0: ("", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"),
            1: ("", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"),
            2: ("", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"),
            3: ("", "M", "MM", "MMM")
        }
        roman = [
            num2roman[3][num // 1000 % 10],
            num2roman[2][num // 100 % 10],
            num2roman[1][num // 10 % 10],
            num2roman[0][num % 10]
        ]

        return ''.join(roman)