class MinStack {
public:
    stack<int>st;
    multiset<int>stm;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        stm.insert(val);
    }
    
    void pop() {
        int t=st.top();
        stm.erase(stm.find(t));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *stm.begin();
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