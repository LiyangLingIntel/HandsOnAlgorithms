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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head == nullptr) {
            return head;
        }
        ListNode *zero = new ListNode(0, head);
        auto *curr = zero;
        for (int i = 1; i < left; ++i) {
            curr = curr->next;
        }
        curr->next = reverseFirstN(curr->next, right - left + 1);

        return zero->next;
    }

    ListNode *reverseFirstN(ListNode *node, int n) {
        auto *first = node;
        auto *curr = node;
        ListNode *prev = nullptr;

        for (int i = 0; i < n; ++i) {
            auto *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first->next = curr;
        return prev;
    }
};