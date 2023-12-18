/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> nodeMap;

    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (nodeMap.count(head) == 0) {
            Node *newNode = new Node(head->val);
            nodeMap.insert({head, newNode});
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
            return newNode;
        }
        return nodeMap[head];
    }
};