// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include "00_commonHeader.hpp"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        list<TreeNode *> que;
        vector<int> res;

        if (root == nullptr)
            return res;

        que.push_back(root);
        while (!que.empty()) {

            TreeNode *currNode = que.front();
            res.push_back(currNode->val);
            que.pop_front();

            if (currNode->left != nullptr)
                que.push_back(currNode->left);
            if (currNode->right != nullptr)
                que.push_back(currNode->right);
        }
        return res;
    }
};