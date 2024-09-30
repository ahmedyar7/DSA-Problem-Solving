#include <iostream>
using namespace std;

class StackNode {
 private:
 public:
  char data;
  StackNode* next;
  StackNode(char value) {
    data = value;
    next = nullptr;
  }

  ~StackNode() { delete next; }
};

class Stack {
 private:
 public:
  StackNode* top;
  Stack() { top == nullptr; }
  ~Stack() { delete top; }

  // Methods
  void push(char value) {
    StackNode* new_node = new StackNode(value);
    if (top == nullptr) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  char pop() {
    if (top == nullptr) {
      cout << "Stack is Empty\n";
      return '\0';
    }
    StackNode* temp = top;
    top = top->next;
    char popped_value = temp->data;
    delete temp;
    return popped_value;
  }

  char peek() {
    if (top == nullptr) {
      cout << "Stack Is empty\n";
      return '\0';
    }
    return top->data;
  }

  bool is_empty() {
    if (top == nullptr) {
      return true;
    }
    return false;
  }
};

bool is_operator(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

bool is_operand(char ch) {
  if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^') {
    return true;
  }
  return false;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;

  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++, end--;
  }

  return;
}

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '^')
    return 3;
  else
    return 0;
}

void infix_to_prefix(char infix[], char prefix[]) {
  int length = 0;
  while (infix[length] != '\0') length++;
  reverse(infix, length);

  Stack operator_stack, operand_stack;

  for (int i = 0; i < length; i++) {
    char ch = infix[i];

    if (is_operand(ch)) {
      operand_stack.push(ch);
    } else if (is_operator(ch)) {
      operator_stack.push(ch);
    } else if (ch == ')') {
      operator_stack.push(ch);
    }

    else if (ch == '(') {
      while (operator_stack.peek() != ')' && !operator_stack.is_empty()) {
        char op = operator_stack.pop();
        char operand2 = operand_stack.pop();
        char operand1 = operand_stack.pop();

        operand_stack.push(operand2);
        operand_stack.push(operand1);
        operator_stack.push(op);
      }

      operator_stack.pop();
    }

    else if (is_operator(ch)) {
      while (!operator_stack.is_empty() &&
             precedence(operator_stack.peek()) > precedence(ch)) {
        char op = operator_stack.pop();
        char operand2 = operand_stack.pop();
        char operand1 = operand_stack.pop();

        operand_stack.push(operand2);
        operand_stack.push(operand1);
        operand_stack.push(op);
      }

      operator_stack.push(ch);
    }
  }

  while (!operator_stack.is_empty()) {
    char op = operator_stack.pop();
    char operand2 = operand_stack.pop();
    char operand1 = operand_stack.pop();
  }

  int i = 0;
  while (!operand_stack.is_empty()) {
    prefix[i++] = operand_stack.pop();
  }
  prefix[i] = '\0';
  reverse(prefix, i);
}
