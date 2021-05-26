// 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/”
// 四则运算符号。

#include "00_commonHeader.hpp"

class Solution {
public:
  int add(int a, int b) {
    while (b != 0) {
      auto temp = a ^ b;
      // c++不支持负数移位, 所以先强制类型转换为无符号数(unsigned int)
      b = static_cast<unsigned>(a & b) << 1;
      a = temp;
    }
    return a;
  }
};