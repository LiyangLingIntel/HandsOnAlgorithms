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
    ListNode *partition(ListNode *head, int x) {
        ListNode *sm = new ListNode(0, head);
        ListNode *gt = new ListNode(0);
        auto *smCurr = sm;
        auto *gtCurr = gt;
        auto *curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                smCurr->next = curr;
                smCurr = smCurr->next;
                curr = curr->next;
            } else {
                gtCurr->next = curr;
                gtCurr = gtCurr->next;
                curr = curr->next;
            }
        }
        gtCurr->next = nullptr;
        smCurr->next = gt->next;
        return sm->next;
    }
};