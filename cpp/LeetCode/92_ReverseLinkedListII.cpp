// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#include<iostream>
#include<string>

// 思路是先遍历一遍链表取出 m-n位置的链表, 记录前缀和后缀的节点, 完成翻转后再接回去
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return NULL;
        
        ListNode* currNode = head;
        ListNode* newHead = head;
        ListNode* prevNode = nullptr;
        
        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next;
            
            if (nextNode == nullptr)
                newHead = currNode;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return newHead;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (head == nullptr)
            return nullptr;
        if (m == n)
            return head;
        
        int count = 1;
        ListNode* prefixNode;
        ListNode* postfixNode;
        
        ListNode* myHead = head;
        ListNode* myEnd = head;
        while(count++ < m && myHead != nullptr) {
            prefixNode = myHead;
            myHead = myHead->next;
        }
        
        ListNode* myTail = myHead;
        while(count++ <= n && myTail != nullptr){
            myTail = myTail->next;
        }
        postfixNode = myTail->next;
        myTail->next = nullptr;

        if(myHead == head)
            head = reverseList(myHead);
        else
            prefixNode->next = reverseList(myHead);
        myHead->next = postfixNode;
        
        return head;
    }
};