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

  void push(char value) {
    Node* new_node = new Node(value);
    if (top == nullptr) {
      top = new_node;
      return;
    }

    new_node->next = top;
    top = new_node;
    return;
  }

  char pop() {
    if (top == nullptr) return '\0';
    char value = top->data;
    Node* head = top;
    top = top->next;
    delete head;
    return value;
  }

  char peek() {
    if (top == nullptr) return '\0';
    return top->data;
  }

  bool is_empty() {
    if (top == nullptr) return true;
    return false;
  }
};

void reverse_str(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    char temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;
  }
}

bool is_operand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;

  return -1;
}

string infix_to_postfix(string s) {
  Stack st;
  string ans;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (is_operand(ch)) {
      ans += ch;
    }

    else if (ch == '(') {
      st.push(ch);
    }

    else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        ans += st.pop();
      }
      st.pop();
    }

    else {
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
  reverse_str(s);
  string ans;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      s[i] = ')';
    } else if (s[i] == ')') {
      s[i] = '(';
    }
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
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.is_empty())
        return false;
      else if (st.peek() == '(' || st.peek() == '{' || st.peek() == '[') {
        st.pop();
      }
    }
  }

  return st.is_empty();
}

int main() {
  std::string exp = "{{(A-B/C)]}}*((A/K-L))";
  std::cout << "Infix expression: " << exp << std::endl;

  std::cout << "Prefix Expression: " << infix_to_prefix(exp) << std::endl;
  std::cout << "Postfix Expression: " << infix_to_postfix(exp) << std::endl;
  std::cout << "Is valid: " << (valid_parenthesis(exp) ? "True" : "False")
            << std::endl;

  return 0;
}