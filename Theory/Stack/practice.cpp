#include <iostream>
using namespace std;

class Node {
 private:
 public:
  char data;
  Node* next;

  Node(char value) {
    data = value;
    next = nullptr;
  }
};

class Stack {
 private:
 public:
  Node* top;

  Stack() { top = nullptr; }
  ~Stack() { delete top; }

  bool is_empty() {
    if (top == nullptr) return true;
    return false;
  }

  void push(char value) {
    Node* new_node = new Node(value);
    if (is_empty()) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  char pop() {
    if (is_empty()) return '\0';
    Node* temp = top;
    top = top->next;
    char value = temp->data;
    delete temp;
    return value;
  }

  char peek() {
    if (is_empty()) return '\0';
    return top->data;
  }
};

bool is_operand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9'))
    return true;
  return false;
}

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '^')
    return 3;
  return -1;
}

string reverse_str(string s) {
  int n = s.length();

  for (int i = 0; i < n / 2; i++) {
    char temp = s[n - i - 1];
    s = s[n - i - 1];
    s[n - i - 1] = temp;
  }
}

string infix_to_postfix(string s) {
  Stack st;
  string ans;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    if (is_operand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        ans += st.pop();
      }
      st.pop();
    } else {
      while (!st.is_empty() && precedence(ch) <= precedence(st.peek())) {
        ans += st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.is_empty()) {
    ans += st.pop();
  }

  return ans;
}

string infix_to_prefix(string s) {
  Stack st;
  string ans;

  reverse_str(s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] == '(';
  }

  ans = infix_to_postfix(s);
  reverse_str(ans);

  return ans;
}

bool valid_parenthesis(string s) {
  Stack st;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.is_empty())
        return false;

      else if (st.peek() == '(' || st.peek() == '{' || st.peek() == '[')
        st.pop();
    }
  }

  return st.is_empty();
}

int main() {
  string exp = "(A-B/C)*(A/K-L)";
  cout << "Infix expression: " << exp << endl;

  cout << "Prefix Expression: ";
  cout << infix_to_prefix(exp);

  cout << "\nPostfix Expression: ";
  cout << infix_to_postfix(exp);

  cout << "\n Is valid " << valid_parenthesis(exp);
  return 0;
}
