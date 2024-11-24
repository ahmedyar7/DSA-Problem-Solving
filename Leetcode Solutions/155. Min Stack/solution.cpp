class MinStack {
 private:
  stack<pair<int, int>> st;  // Member stack to store {value, current_min}

 public:
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.push({val, val});  // First element's min is itself
    } else {
      st.push({val, min(val, st.top().second)});
    }
  }

  void pop() {
    if (!st.empty()) {
      st.pop();
    }
  }

  int top() {
    return st.top().first;  // Access the value only
  }

  int getMin() {
    return st.top().second;  // Access the current minimum
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