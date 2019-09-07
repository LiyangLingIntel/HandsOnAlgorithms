// Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

// Example 1:

// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Explanation: We might do the following sequence:
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// Example 2:

// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false
// Explanation: 1 cannot be popped before 2.
 
#include<iostream>
#include<vector>
using namespace std;

// 思路是用辅助栈来模拟存储和弹出的过程.
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        if(pushed.size() != popped.size())
            return false;
        
        int N = pushed.size();
        int iterPush = 0, iterPop = 0;
        
        while(iterPush <= N && iterPop < N) {
            if (stack.empty() || stack.back() != popped[iterPop]) {
                if (iterPush == N)
                    return false;
                stack.push_back(pushed[iterPush++]);
            }
            if (stack.back() == popped[iterPop]) {
                iterPop++;
                stack.pop_back();
            }
        }
        return true;
    }
};