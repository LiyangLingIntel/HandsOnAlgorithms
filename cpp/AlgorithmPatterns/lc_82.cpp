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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *preHead = new ListNode(0, head);
        ListNode *prev = preHead;
        ListNode *curr = head;
        ListNode *next = curr->next;
        int rmVal = -101;

        while (next != nullptr) {
            if (curr->val == next->val) {
                rmVal = curr->val;
                if (next->next == nullptr) {
                    prev->next = nullptr;
                    return preHead->next;
                }
                while (next->next != nullptr) {
                    if (rmVal == next->next->val) {
                        curr = next;
                        next = next->next;
                    } else {
                        prev->next = next->next;
                        curr = next->next;
                        next = curr->next;
                        break;
                    }
                }
            } else {
                prev = curr;
                curr = curr->next;
                next = curr->next;
            }
        }
        return preHead->next;
    }
};