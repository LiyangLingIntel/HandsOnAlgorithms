
// 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)


#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
    // 构造函数
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 思路还是递归的方法, 知道某条路径能满足加起来之和为 expectNumber, 就把当前路径放到结果集合中.
// 需要注意的是在构建路径的时候, 完成某条路之后需要在递归弹栈时同时把路径中的节点也弹出去.
class Solution {
public:
    void FindPath(TreeNode* node, int expectNumber, vector<vector<int> >&res, vector<int>& path) {

        bool isLeaf = node->left==nullptr && node->right==nullptr;
        if(isLeaf){
            if(node->val == expectNumber){
                path.push_back(node->val);
                res.push_back(path);
                path.pop_back();
            }
        }
        else {
            path.push_back(node->val);
            if(node->left != nullptr)
                FindPath(node->left, expectNumber-node->val, res, path);
            if(node->right != nullptr)
                FindPath(node->right, expectNumber-node->val, res, path);
            path.pop_back();
        }

    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> path;
        if(root == nullptr)
            return res;
        
        FindPath(root, expectNumber, res, path);
        return res;
    }
};