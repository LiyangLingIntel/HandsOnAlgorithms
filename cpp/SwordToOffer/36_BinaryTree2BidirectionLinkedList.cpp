// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

#include "00_commonHeader.hpp"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void ReconnectTree(TreeNode *node, TreeNode **lastNode) {
        if (node == nullptr)
            return;

        TreeNode *currNode = node;
        if (currNode->left != nullptr)
            ReconnectTree(currNode->left, lastNode);

        currNode->left = *lastNode;
        if (*lastNode != nullptr)
            (*lastNode)->right = currNode;

        *lastNode = currNode;
        if (currNode->right != nullptr)
            ReconnectTree(currNode->right, lastNode);
    }
    TreeNode *Convert(TreeNode *pRootOfTree) {
        TreeNode *lastNode = nullptr;
        ReconnectTree(pRootOfTree, &lastNode);

        TreeNode *headNode = lastNode;
        while (headNode != nullptr && headNode->left != nullptr)
            headNode = headNode->left;
        return headNode;
    }
};