class MinStack {
public:

    stack <pair<int, int>> data;

    MinStack() {}

    void push(int val) {
        if (data.empty()) {
            data.push({val, val});
        } else {
            int smaller = min(val, getMin());
            data.push({val, smaller});
        }
    }

    void pop() {
        data.pop();
    }

    int top() {
        return data.top().first;
    }

    int getMin() {
        return data.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
