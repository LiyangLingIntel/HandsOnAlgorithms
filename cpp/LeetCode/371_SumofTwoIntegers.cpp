/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1
*/

// 易错点： 没有考虑到负数
// 对于负数的处理需要把进位值转为 无符号的整形.
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        int res = a^b;
        int carry = (unsigned int)(a&b) << 1;
        return getSum(res, carry);
    }
};