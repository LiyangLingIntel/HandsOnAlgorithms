/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        auto *slow = head;
        auto *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                slow = head;
                fast = fast->next;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};
