/**
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode *root) {
        int maxPath = INT_MIN;
        traverseNodes(root, maxPath);
        return maxPath;
    }

    int traverseNodes(TreeNode *node, int &maxPath) {
        if (node == nullptr) {
            return 0;
        }
        auto leftSum = max(traverseNodes(node->left, maxPath), 0);
        auto rightSum = max(traverseNodes(node->right, maxPath), 0);
        maxPath = max(maxPath, leftSum + rightSum + node->val);

        auto childSum = max(leftSum, rightSum);
        return childSum + node->val;
    }
};