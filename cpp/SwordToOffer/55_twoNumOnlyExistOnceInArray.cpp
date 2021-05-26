// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。

#include "00_commonHeader.hpp"

// 要求时间复杂度为 O(n)， 空间复杂度为 O(1)

// 这题本身考察的是对二进制和位运算的理解
// 主要运用到 异或的操作: 任何数字异或自己都等于0, 所以整个数组逐个异或的结果等于这两个不同的数字异或的结果(相同的被抵消)
// 为了得到这两个数字, 需要通过异或结果的关键位(2个不同的数字数值不同的位)把数组分为两个子数组, 然后在分别进行异或得到两个数字.
class Solution {
public:
    int countShifts(int flag) {
        int count = 0;
        while(((flag & 1)== 0) && (count++ < 8*(sizeof(int))))
            flag = flag >> 1;
        return count;
    }
    int judge(int num, int shift) {
        num = num >> shift;
        return (num & 1);
    }

    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() == 0)
            return;
        
        int resXOR = 0;
        for(auto num: data){
            resXOR ^= num;
        }
        int shifts = countShifts(resXOR);
        
        *num1 = *num2 = 0;
        for(auto num: data) {
            if(judge(num, shifts))
                *num1 ^= num;
            else
                *num2 ^= num;
        }
    }
};