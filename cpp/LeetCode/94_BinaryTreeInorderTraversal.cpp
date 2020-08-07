// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?


#include <vector>
#include <stack>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

// Solution: recursive
class Solutio1 {
public:
  void inorderTraversal(TreeNode *node, vector<int> &output) {
    if (node == nullptr)
      return;
    inorderTraversal(node->left, output);
    output.push_back(node->val);
    inorderTraversal(node->right, output);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorderTraversal(root, res);
    return res;
  }
};

// Solution: iteractive
class Solution2 {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> nodes;
    auto curr = root;

    while (curr || !nodes.empty()) {
      if (curr) {
        nodes.push(curr);
        curr = curr->left;
      } else {
        curr = nodes.top();
        nodes.pop();
        res.push_back(curr->val);
        curr = curr->right;
      }
    }
    return res;
  }
};