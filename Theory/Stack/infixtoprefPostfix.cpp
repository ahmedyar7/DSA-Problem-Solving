#include <iostream>
using namespace std;

class StackNode {
 private:
 public:
  char data;
  StackNode* next;

  StackNode(int value) {
    data = value;
    next = nullptr;
  }
  ~StackNode() { delete next; }
};

class Stack {
 private:
 public:
  StackNode* top;

  Stack() { top = nullptr; };
  ~Stack() { delete top; }

  bool is_empty() {
    if (top == nullptr) return true;
    return false;
  }
  void push(StackNode*& head, char value) {
    StackNode* new_node = new StackNode(value);
    if (is_empty()) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head = new_node;
    return;
  }

  char pop(StackNode*& head) {
    if (is_empty()) {
      return '\0';
    }
    StackNode* temp = head;
    head = head->next;
    int value = temp->data;
    delete temp;
    return value;
  }

  char peek(StackNode* head) {
    if (is_empty()) return '\0';
    return head->data;
  }
};

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '^')
    return 3;
  return 0;
}

string infix_to_postfix(string exp) {
  int i = 0;
  Stack st;
  StackNode* head;
  string ans = "";

  while (i < exp.length()) {
    // check operand
    if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') ||
        (exp[i] >= '0' && exp[i] <= '9')) {
      ans += exp[i];
    }
    // Condition for opening bracket
    else if (exp[i] == '(')
      st.push(head, exp[i]);
    // Condition for closing bracket
    else if (exp[i] == ')') {
      while (!st.is_empty() && st.peek(head) != '(') {
        ans += st.pop(head);
      }
      st.pop(head);
    }
    // condtion for operator
    else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*') {
      while (!st.is_empty() &&
             precedence(exp[i]) <= precedence(st.peek(head))) {
        ans += st.pop(head);
      }
      st.push(head, exp[i]);
    }
  }

  while (st.is_empty()) {
    if (st.) }
}
