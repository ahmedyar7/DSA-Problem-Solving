#include <iostream>
using namespace std;

class Node {
 public:
  char data;
  Node* next;

  Node(char data) {
    this->data = data;
    next = nullptr;
  }
};

class Stack {
 private:
  Node* top_node;

 public:
  Stack() { top_node = nullptr; }

  bool empty() {
    if (top_node == nullptr)
      return true;
    else
      return false;
  }

  void push(char value) {
    Node* new_node = new Node(value);
    new_node->next = top_node;
    top_node = new_node;  // ! ERROR GOT FIXED
    return;
  }

  int pop() {
    if (empty()) return -1;
    Node* temp = top_node;
    int value = temp->data;
    top_node = top_node->next;
    delete temp;
    return value;
  }

  int top() { return top_node->data; }
};

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;

  return -1;
}

bool operand(char ch) {
  return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
          (ch >= '0' && ch <= '9'));
}

void string_reverse(string str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) {
    char temp = str[n - i - 1];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}

string infix_to_postfix(string str) {
  string ans;
  Stack st;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (operand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.pop();
      }
      st.pop();
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

bool valid_parenthesis(string s) {
  Stack st;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.empty()) return false;

      char top = st.top();
      if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
          (ch == '}' && top == '{')) {
        st.pop();
      } else
        return false;
    }
  }

  return st.empty();
}

int main() {
  string exp = "{{[(A-B/C)]}}*((A/K-L))";
  cout << "Infix expression: " << exp << endl;

  cout << "Infix Expression: ";
  cout << infix_to_prefix(exp);

  cout << "\nPostfix Expression: ";
  cout << infix_to_postfix(exp);

  cout << "\n Is valid " << valid_parenthesis(exp);
}
