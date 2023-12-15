/**
 * https://leetcode.cn/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        auto isValid = traverseNode(root, prev);
        return isValid;
    }
    
    bool traverseNode(TreeNode* node, long& prev) {
        if (node == nullptr) return true;
        if (!traverseNode(node->left, prev)) {
            return false;
        }
        if (prev >= node->val) {
            return false;
        }
        prev = node->val;
        return traverseNode(node->right, prev);
    }
};