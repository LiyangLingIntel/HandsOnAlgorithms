/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *cloneGraph(Node *node) {
        unordered_map < Node * , Node * > nodeMap;
        auto *cloned = cloneNode(node, nodeMap);
        return cloned;
    }

    Node *cloneNode(Node *node, unordered_map<Node *, Node *> &nodeMap) {
        if (node == nullptr) {
            return nullptr;
        }
        if (nodeMap.count(node) == 0) {
            nodeMap[node] = new Node(node->val);
        } else {
            return nodeMap[node];
        }

        auto neighbors = node->neighbors;
        vector < Node * > newNeighbors;
        newNeighbors.reserve(neighbors.size());

        for (auto *nb: neighbors) {
            if (nodeMap.count(nb) == 0) {
                auto *newBb = cloneNode(nb, nodeMap);
                newNeighbors.push_back(newBb);
            } else {
                newNeighbors.push_back(nodeMap[nb]);
            }
        }
        nodeMap[node]->neighbors = newNeighbors;
        return nodeMap[node];
    }
};