// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include "00_commonHeader.hpp"

class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int N = numbers.size();
        if (N <= 0)
            return 0;
        int res = numbers[0];
        int count = 1;

        for (int i = 1; i < N; i++) {
            if (count == 0) {
                res = numbers[i];
            }
            count += (numbers[i] == res ? 1 : -1);
        }
        count = 0;
        for (auto x : numbers) {
            if (x == res)
                count++;
        }
        if (count > (N / 2))
            return res;
        else
            return 0;
    }
};