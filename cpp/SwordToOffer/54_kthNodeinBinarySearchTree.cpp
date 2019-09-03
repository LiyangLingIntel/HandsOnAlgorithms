/*
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 核心思想还是中序遍历二叉搜索树，得到第k个节点。
// 值得注意的是，传参的时候拿的时k的引用，保证递归调用时栈之间修改的是同样一个k。

class Solution {
public:
    TreeNode* findKthNode(TreeNode* pRoot, int& k) {
        TreeNode* res = nullptr;
        if (pRoot->left != nullptr) {
            res = findKthNode(pRoot->left, k);
        }
        if (res == nullptr) {
            if (k == 1)
                res = pRoot;
            k--;
        }
        if (res == nullptr && pRoot->right != nullptr) {
            res = findKthNode(pRoot->right, k);
        }
        return res;
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == nullptr || k == 0){
            return nullptr;
        }
        return findKthNode(pRoot, k);
    }
};