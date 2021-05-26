// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

#include "00_commonHeader.hpp"

// 思路也比较简单, 根据后序遍历和二叉搜索树的特点
// 确定当前判断层级的根节点, 只要遍历完这个序列, 然后满足前半部分都小于根节点, 后半部分都小于根节点
// 通过递归或者循环个子树完成上述过程.
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int N = sequence.size();
        if(N == 0)
            return false;
        
        while(--N) {
            int i = 0;
            while(sequence[i++] < sequence[N]);
            while(sequence[i++] > sequence[N]);
            
            if(i<N)
                return false;
        }
        return true;
    }
};