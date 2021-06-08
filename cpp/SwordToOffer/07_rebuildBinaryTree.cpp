
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

//  

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
//  

// 限制：

// 0 <= 节点个数 <= 5000

#include "00_commonHeader.hpp"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    TreeNode *buildSubTree(vector<int> &preorder, int pre_s, int pre_e,
                           vector<int> &inorder, int in_s, int in_e) {
        if (pre_s > pre_e || in_s > in_e)
            return nullptr;

        int root_val = preorder[pre_s];
        TreeNode *root = new TreeNode(root_val);

        int root_id;
        for (int i = in_s; i <= in_e; i++) {
            if (inorder[i] == root_val) {
                root_id = i;
                break;
            }
        }
        int left_size = root_id - in_s;

        root->left = buildSubTree(preorder, pre_s + 1, pre_s + left_size,
                                  inorder, in_s, root_id - 1);
        root->right = buildSubTree(preorder, pre_s + left_size + 1, pre_e,
                                   inorder, root_id + 1, in_e);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        TreeNode *res = buildSubTree(preorder, 0, n - 1, inorder, 0, n - 1);
        return res;
    }
};