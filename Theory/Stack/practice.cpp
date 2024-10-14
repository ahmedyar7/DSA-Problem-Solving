#include <iostream>
using namespace std;

class Stack {
 private:
  int size;
  int top_element;
  int* arr;

 public:
  Stack(int size) {
    this->size = size;
    top_element = -1;
    arr = new int[size];
  }

  bool empty() { return top_element == -1; }
  bool full() { return top_element == size - 1; }

  void push(int value) {
    if (full()) {
      return;
    }
    top_element++;
    arr[top_element] = value;
    return;
  }

  int pop() {
    if (empty()) {
      return -1;
    }
    int value = arr[top_element];
    top_element--;
    return value;
  }

  int top() { return arr[top_element]; }
};

bool operand(char ch) {
  return ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ||
          (ch >= 'a' && ch <= 'z'));
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;
  return -1;
}

void string_reverse(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}

string infix_to_postfix(string str) {
  string ans;
  Stack st(str.length());

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (operand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.top() == '(') {  // Fix: Corrected condition
        ans += st.pop();
      }
      st.pop();  // Pop the '(' from the stack
    } else {
      while (!st.empty() && precedence(ch) <= precedence(st.top())) {
        ans += st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.empty()) {
    ans += st.pop();
  }
  return ans;
}

string infix_to_prefix(string str) {
  string_reverse(str);
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(') {
      str[i] = ')';
    } else if (str[i] == ')') {
      str[i] = '(';
    }
  }

  string ans = infix_to_postfix(str);
  string_reverse(ans);

  return ans;
}

bool valid_parenthesis(string str) {
  Stack st(str.length());
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.empty()) return false;
      char top = st.top();
      if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
          (ch == '}' && top == '{')) {
        st.pop();
      } else {
        return false;
      }
    }
  }
  return st.empty();
}

int main() {
  string exp = "(A-B/C)*(A/K-L)";
  cout << "Infix expression: " << exp << endl;

  cout << "Prefix Expression: " << infix_to_prefix(exp) << endl;

  cout << "Postfix Expression: " << infix_to_postfix(exp) << endl;

  cout << "Is valid: " << (valid_parenthesis(exp) ? "true" : "false") << endl;
  return 0;
}
