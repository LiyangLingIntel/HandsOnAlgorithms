/**
 * https://leetcode.cn/problems/balanced-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return traverseNodes(root) != -1;
    }

    int traverseNodes(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        auto depthLeft = traverseNodes(node->left);
        auto depthRight = traverseNodes(node->right);
        if (depthLeft < 0 || depthRight < 0 || depthLeft - depthRight > 1 || depthRight - depthLeft > 1)
            return -1;
        auto depth = depthLeft > depthRight ? depthLeft : depthRight;
        return depth + 1;
    }
};
