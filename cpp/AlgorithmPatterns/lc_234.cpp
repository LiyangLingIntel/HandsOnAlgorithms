/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        vector<int> stupid;
        auto* curr = head;
        while (curr != nullptr) {
            stupid.push_back(curr->val);
            curr = curr->next;
        }

        auto listSize = stupid.size();
        for(int i = 0; i < listSize / 2; i++) {
            if (stupid[i] != stupid[listSize-i-1]) {
                return false;
            }
        }
        return true;
    }
};