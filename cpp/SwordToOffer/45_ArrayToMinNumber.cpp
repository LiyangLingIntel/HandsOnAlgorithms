// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#include "00_commonHeader.hpp"

// 思路就是通过重新定义排序比较的规则来对数组重新排序, 然后按序拼接字符串.
class Solution {
  public:
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        if (numbers.empty())
            return res;
        sort(numbers.begin(), numbers.end(), [](int x, int y) {
            return to_string(x) + to_string(y) < to_string(y) + to_string(x);
        });
        for (auto i : numbers) {
            res += to_string(i);
        }
        return res;
    }
};