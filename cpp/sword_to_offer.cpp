#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	/*
	Q5
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
	*/
	void replaceSpace(char *str, int length)
	{
		if (str == nullptr || length <= 0)
		{
			return;
		}
		int originalLength = 0;
		int blankNumber = 0;

		int i = 0;
		while (str[i] != '\0')
		{
			originalLength++;
			if (str[i] == ' ')
			{
				blankNumber++;
			}
			i++;
		}

		int newLength = originalLength + blankNumber * 2;
		if (newLength > length)
		{
			return;
		}

		while (originalLength >= 0 && newLength > originalLength)
		{
			if (str[originalLength] == ' ')
			{
				str[newLength--] = '0';
				str[newLength--] = '2';
				str[newLength--] = '%';
			}
			else
			{
				str[newLength--] = str[originalLength];
			}
			originalLength--;
		}
	}

	/*
	* Q6
	* 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
	*/
	vector<int> printListFromTailToHead(ListNode *head)
	{
		// 这是常用方法
		vector<int> nodes;
		if (head != nullptr)
		{
			ListNode *pNode = head;
			nodes.insert(nodes.begin(), pNode->val);
			while (pNode->next != nullptr)
			{
				nodes.insert(nodes.begin(), pNode->next->val);
				pNode = pNode->next;
			}
		}
		return nodes;
	}
	// //下面尝试使用递归
	//         vector<int> nodes;
	//         reversing_recursively(head, nodes);
	//         return nodes;
	//     }
	//     void reversing_recursively(ListNode* head, vector<int> &vec){
	//         if(head != nullptr){
	//             if(head->next != nullptr){
	//                 reversing_recursively(head->next, vec);
	//             }
	//             vec.push_back(head->val);
	//         }

	/*
	* Q7
	* 
	* 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	* 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
	*/
	TreeNode *constructCore(vector<int> pre, int pStart, int pEnd, vector<int> vin, int vStart, int vEnd)
	{
		// 在前序遍历找到根节点
		TreeNode *root = new TreeNode(pre[pStart]);
		if (pStart == pEnd)
		{
			return root;
		}
		//在中序遍历找到根节点
		int vRoot = vStart;
		while (vin[vRoot] != root->val && vRoot < vEnd)
		{
			vRoot++;
		}
		int leftLength = vRoot - vStart;
		int rightLength = vEnd - vRoot;
		// 左子树
		if (leftLength > 0)
		{
			root->left = constructCore(pre, pStart + 1, pStart + leftLength, vin, vStart, vRoot - 1);
		}
		// 右子树
		if (rightLength > 0)
		{
			root->right = constructCore(pre, pStart + leftLength + 1, pEnd, vin, vRoot + 1, vEnd);
		}
		return root;
	}
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() == 0 || vin.size() == 0)
		{
			return nullptr;
		}
		return constructCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}

	/*
	Q8
	给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
	*/
	TreeLinkNode *GetNext(TreeLinkNode *pNode)
	{
		if (pNode == nullptr)
		{
			return nullptr;
		}

		TreeLinkNode *pNext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode *pRight = pNode->right;
			while (pRight->left != nullptr)
			{
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		else if (pNode->next != nullptr)
		{
			TreeLinkNode *currNode = pNode;
			TreeLinkNode *pParent = pNode->next;
			while (pParent != nullptr && currNode == pParent->right)
			{
				currNode = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;
		}
		return pNext;
	}

	/*
	Q9
	用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。 
	*/
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int result;
        if(stack2.empty()){
            while(!stack1.empty()){
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        result = stack2.top();
        stack2.pop();
        return result;
    }

	/*
	Q10
	现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
	*/
    int Fibonacci(int n) {
        vector<int> fiboArray;
        fiboArray.push_back(0);
        fiboArray.push_back(1);

        if(n < 2)
            return fiboArray[n];
        for(int i=1; i<=n-1; i++){
            int num = fiboArray[i] + fiboArray[i-1];
            fiboArray.push_back(num);
        }
        return fiboArray[n];
    }

	/*
	Q10
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
	NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
	*/
    int minNumberInRotateArray(vector<int> rotateArray) {
        int N = rotateArray.size();
        
        if(N == 0)
            return 0;
        
        int start = 0;
        int end = N-1;
        while(start < end){
            
            if(end-start == 1){
                start = end;
                break;
            }
            int mid = (start+end) / 2;
            if(rotateArray[start] <= rotateArray[mid])
                start = mid;
            else
                end = mid;
        }
        return rotateArray[start];
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
