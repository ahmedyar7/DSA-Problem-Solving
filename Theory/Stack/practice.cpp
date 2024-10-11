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
 public:
  Node* head;
  Stack() { head = nullptr; }

  bool empty() { return head == nullptr; }

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
    Node* temp = head;
    char value = temp->data;
    head = head->next;
    return value;
  }

  char peek() { return head->data; }
};

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;

  return -1;
}

void reverse_string(string& s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    char temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;
  }
}

bool operand(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
          (ch >= '0' && ch <= '9'));
}

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
          (ch == ']' && top == '['))
        st.pop();
      else {
        return false;
      }
    }
  }
  return st.empty();
}

string infix_to_postfix(string s) {
  Stack st;
  string ans;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    if (operand(ch)) {
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
  reverse_string(s);
  cout << "String go revrsed\n";

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      s[i] = ')';
    } else if (s[i] == ')') {
      s[i] = '(';
    }
  }

  cout << "parnenthesis got changed\n";

  string ans = infix_to_postfix(s);
  reverse_string(ans);
  cout << "go the aans wer string\n";
  return ans;
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
