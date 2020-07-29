// In a row of trees, the i-th tree produces fruit with type tree[i].

// You start at any tree of your choice, then repeatedly perform the following steps:

// Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
// Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
// Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

// You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

// What is the total amount of fruit you can collect with this procedure?


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& tree) {
        auto len = tree.size();
        int max_size = 0, i=0, j = 0;
        vector<int> bracket;
        
        while(j < len) {
            if(bracket.size() != 2) {
                if(bracket.size()==0 || tree[j] != bracket[0]){
                    bracket.push_back(tree[j]);                    
                }
                j++;
                max_size++;
            } 
            else {
                if (tree[j] == bracket[0] || tree[j] == bracket[1]){
                    j++;
                    max_size = max(j-i, max_size);
                }
                else {
                    if (tree[j-1] == bracket[0])
                        bracket[1] = tree[j];
                    else
                        bracket[0] = tree[j];
                    auto temp_id = j-1;
                    while(temp_id-- >= i) {
                        if(tree[temp_id] != tree[j-1])
                            break;
                    }
                    i = temp_id+1;
                }
            }
        }
        return max_size;
    }
};