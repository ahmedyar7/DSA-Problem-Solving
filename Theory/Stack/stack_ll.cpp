#include <iostream>

class Node {
 public:
  char data;
  Node* next;

  Node(char value) : data(value), next(nullptr) {}
};

class Stack {
 private:
  Node* top;

 public:
  Stack() : top(nullptr) {}

  ~Stack() {
    while (!is_empty()) {
      pop();
    }
  }

  bool is_empty() { return top == nullptr; }

  void push(char value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
  }

  char pop() {
    if (is_empty()) return '\0';
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
  }

  char peek() {
    if (is_empty()) return '\0';
    return top->data;
  }
};

void reverse_str(std::string& s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    std::swap(s[i], s[n - i - 1]);
  }
}

bool is_operand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
         (ch >= '0' && ch <= '9');
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;
  return -1;
}

std::string infix_to_postfix(const std::string& s) {
  Stack st;
  std::string ans;

  for (char ch : s) {
    if (is_operand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        ans += st.pop();
      }
      if (!st.is_empty()) st.pop();
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

std::string infix_to_prefix(std::string s) {
  reverse_str(s);
  for (char& ch : s) {
    if (ch == '(')
      ch = ')';
    else if (ch == ')')
      ch = '(';
  }

  std::string ans = infix_to_postfix(s);
  reverse_str(ans);
  return ans;
}

bool valid_parenthesis(const std::string& s) {
  Stack st;

  for (char ch : s) {
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.is_empty()) return false;
      char top = st.pop();
      if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
          (ch == ']' && top != '[')) {
        return false;
      }
    }
  }

  return st.is_empty();
}

int main() {
  std::string exp = "{{[(A-B/C)]}}*((A/K-L))";
  std::cout << "Infix expression: " << exp << std::endl;

  std::cout << "Prefix Expression: " << infix_to_prefix(exp) << std::endl;
  std::cout << "Postfix Expression: " << infix_to_postfix(exp) << std::endl;
  std::cout << "Is valid: " << (valid_parenthesis(exp) ? "True" : "False")
            << std::endl;

  return 0;
}