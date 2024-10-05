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

  ~Node() { delete next; }
};

class Stack {
 private:
 public:
  Node* head;

  Stack() { head = nullptr; }
  ~Stack() { delete head; }

  bool empty() {
    if (head == nullptr) {
      return true;
    } else {
      return false;
    }
  }

  void push(char value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      return;
    }

    new_node->next = head;
    head = new_node;
    return;
  }

  char pop() {
    if (head == nullptr) {
      return '\0';
    }

    char value = head->data;
    head = head->next;
    // delete head;
    return value;
  }

  char peek() {
    if (head == nullptr) {
      return '\0';
    }
    return head->data;
  }
};

bool valid_parenthesis(string s) {
  Stack st;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.empty()) return false;
      char top = st.peek();
      if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
          (ch == ']' && top == '[')) {
        st.pop();
      } else {
        return false;
      }
    }
  }

  return st.empty();
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
  if (ch == '/' || ch == '*') return 2;
  if (ch == '^') return 3;

  return -1;
}

void reverse_str(string s) {
  int n = s.length();

  for (int i = 0; i < n / 2; i++) {
    char temp = s[n - i - 1];
    s[i] = s[n - i - 1];
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
      while (!st.empty() && st.peek() != '(') {
        ans += st.pop();
      }
      st.pop();
    } else {
      while (!st.empty() && precedence(ch) <= precedence(st.peek())) {
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

int main() {
  string exp = "{(A-B/C)*(A/K-L)";
  cout << "Infix expression: " << exp << endl;

  cout << "Prefix Expression: ";
  cout << infix_to_prefix(exp);

  cout << "\nPostfix Expression: ";
  cout << infix_to_postfix(exp);

  cout << "\n Is valid " << valid_parenthesis(exp);
  return 0;
}
