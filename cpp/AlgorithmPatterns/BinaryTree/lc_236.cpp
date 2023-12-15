/**
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        auto *left = lowestCommonAncestor(root->left, p, q);
        auto *right = lowestCommonAncestor(root->right, p, q);
        bool isSelf = root->val == p->val || root->val == q->val;
        bool inLeft = left != nullptr;
        bool inRight = right != nullptr;

        if (isSelf || (inLeft && inRight)) {
            return root;
        } else if (inLeft) {
            // return left means p/q in left child nodes, relative to nullptr
            return left;
        } else if (inRight) {
            // return right means p/q in right child nodes, relative to nullptr
            return right;
        }
        return nullptr;
    }
};