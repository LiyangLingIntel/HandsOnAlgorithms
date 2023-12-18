/**
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode *root) {
        return traverseNodes(root, 0);
    }

    int traverseNodes(TreeNode *node, int depth) {
        if (node == nullptr) {
            return depth;
        }
        auto depth_left = traverseNodes(node->left, depth + 1);
        auto depth_right = traverseNodes(node->right, depth + 1);
        depth = depth_left > depth_right ? depth_left : detph_right;
        return depth;
    }
};