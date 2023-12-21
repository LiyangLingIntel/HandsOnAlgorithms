class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (auto& t : tokens) {
            int res;
            if (t == "+") {
                auto rhs = numbers.top();
                numbers.pop();
                auto lhs = numbers.top();
                numbers.pop();
                res = lhs + rhs;
            } else if (t == "-") {
                auto rhs = numbers.top();
                numbers.pop();
                auto lhs = numbers.top();
                numbers.pop();
                res = lhs - rhs;
            } else if (t == "*") {
                auto rhs = numbers.top();
                numbers.pop();
                auto lhs = numbers.top();
                numbers.pop();
                res = lhs * rhs;
            } else if (t == "/") {
                auto rhs = numbers.top();
                numbers.pop();
                auto lhs = numbers.top();
                numbers.pop();
                res = lhs / rhs;
            } else {
                res = stoi(t);
            }
            numbers.push(res);
        }
        return numbers.top();
    }
};
