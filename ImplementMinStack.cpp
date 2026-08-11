class MinStack {
    stack<int> st;
    stack<int> min;

public:
    MinStack() {}

    void push(int value) {
        st.push(value);
        if (min.empty()) {
            min.push(value);
        } else {
            min.push(std::min(value, min.top()));
        }
    }

    void pop() {
        st.pop();
        min.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//Approach 2: using modified value to push and pop, maths formula (revise it)
class MinStack {
public:
    stack<long long int> st;
    long long minValue;
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        } else {
            if (value < minValue) {
                st.push((long long)2 * value - minValue);
                minValue = value;
            } else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.top() < minValue) {
            minValue = 2 * minValue - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() < minValue) {
            return minValue;
        } else {
            return st.top();
        }
    }

    int getMin() { return minValue; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
