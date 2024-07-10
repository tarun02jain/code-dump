class MinStack {
public:
    stack<int>st;
    stack<int>minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!minStack.size() || minStack.top()>=val){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(st.size() == 0) return ;
        if(st.top() == minStack.top()){
            st.pop();
            minStack.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.size() == 0) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minStack.size() == 0) return -1;
        return minStack.top();
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