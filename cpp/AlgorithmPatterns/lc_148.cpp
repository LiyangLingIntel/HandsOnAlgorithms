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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // find middle of list
        ListNode *prev = nullptr;
        auto *middle = head;
        auto *end = head;
        while (end != nullptr) {
            prev = middle;
            middle = middle->next;
            if (end->next == nullptr)
                break;
            end = end->next->next;
        }
        prev->next = nullptr;

        auto *first = sortList(head);
        auto *second = sortList(middle);
        // merge 2 sub-list
        ListNode *res = new ListNode();
        auto *curr = res;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                curr->next = first;
                first = first->next;
            } else {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }
        if (first == nullptr) {
            curr->next = second;
        } else {
            curr->next = first;
        }
        return res->next;
    }
};