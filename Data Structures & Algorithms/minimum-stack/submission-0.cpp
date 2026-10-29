class MinStack {
    vector<int> stk;
    vector<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push_back(value);
        if (minStk.empty()) {
            minStk.push_back(value);
        }
        else {
            minStk.push_back(value < minStk.back() ? value: minStk.back());
        }
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};
