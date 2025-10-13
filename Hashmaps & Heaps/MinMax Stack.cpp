class MinStack {
public:
    stack<int> st, minVal, maxVal;
    MinStack() {
        
    }
    
    void push(int val) {
        //push new value in stack
        // update maxVal & minVal as per the new val
        int minSoFar = INT_MAX, maxSoFar = INT_MIN;
        if(!minVal.empty()){
            minSoFar = minVal.top();
        }
        if(!maxVal.empty()){
            maxSoFar = maxVal.top();
        }
        st.push(val);
        minVal.push(min(val, minSoFar));
        maxVal.push(max(val, maxSoFar));
    }
    
    void pop() {
        //pop the value from stack, from minValue & from maxVal to attain the previous state
        if(!st.empty()){
            st.pop();
            minVal.pop();
            maxVal.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal.top();
    }

    int getMax(){
        return maxVal.top();
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
