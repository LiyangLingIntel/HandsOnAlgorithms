// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
 

#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        if (leftNode == nullptr || rightNode == nullptr) {
            return false;
        }
        if (leftNode->val == rightNode->val)
            return isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
        else
            return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
};