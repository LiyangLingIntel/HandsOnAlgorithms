// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct ListNodeGreater
    {
        bool operator()(const ListNode *ln1, const ListNode *ln2)
        {
            return ln1->val > ln2->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, ListNodeGreater> min_heap;

        for (auto node : lists)
            if (node != nullptr)
                min_heap.push(node);

        ListNode res(0);
        auto curr = &res;

        while (!min_heap.empty())
        {
            auto node = min_heap.top();
            curr->next = node;
            curr = curr->next;

            min_heap.pop();
            if (node->next != nullptr)
            {
                min_heap.push(node->next);
            }
        }
        return res.next;
    }
};