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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *zero = new ListNode(0);
        auto *curr = zero;
        auto *currL1 = list1;
        auto *currL2 = list2;

        while (currL1 != nullptr && currL2 != nullptr) {
            if (currL1->val < currL2->val) {
                curr->next = currL1;
                currL1 = currL1->next;
            } else {
                curr->next = currL2;
                currL2 = currL2->next;
            }
            curr = curr->next;
        }
        if (currL1 == nullptr) {
            curr->next = currL2;
        } else {
            curr->next = currL1;
        }

        return zero->next;
    }
};