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

  Stack() { top = nullptr; }
  ~Stack() { delete top; }

  bool is_empty() {
    if (top == nullptr) {
      return true;
    }
    return false;
  }

  void push(char value) {
    StackNode* new_node = new StackNode(value);
    if (is_empty()) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  char pop() {
    if (is_empty()) {
      cout << "Empty List\n";
      return '\0';
    }
    StackNode* temp = top;
    top = top->next;
    char value = temp->data;
    delete temp;
    return value;
  }

  char peek() {
    if (is_empty()) {
      return '\0';
    }
    return top->data;
  }
};

bool is_operand(char ch) {
  if ((ch >= '0' && ch <= '9') || (ch > 'a' && ch <= 'z') ||
      (ch >= 'A' && ch <= 'Z')) {
    return true;
  }
  return false;
}

bool is_operator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
    return true;
  }
  return false;
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '/' || ch == '*') {
    return 2;
  } else if (ch == '^') {
    return 3;
  }
  return 0;
}

void reverse(char str[], int length) {
  int start = 0, end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++, end--;
  }
}

void infix_to_prefix(char infix[], char prefix[]) {
  int length = 0;
  while (infix[length] != '\0') length++;
  reverse(infix, length);

  Stack operators_stack, operands_stack;

  for (int i = 0; i < length; i++) {
    char ch = infix[i];

    if (is_operand(ch)) {
      operands_stack.push(ch);
    } else if (ch == ')') {
      operators_stack.push(ch);
    }

    else if (ch == '(') {
      while (operators_stack.peek() != ')' && !operators_stack.is_empty()) {
        char op = operators_stack.pop();
        char operand2 = operands_stack.pop();
        char operand1 = operands_stack.pop();

        operands_stack.push(operand2);
        operands_stack.push(operand1);
        operands_stack.push(op);
      }
      operators_stack.pop();
    } else if (is_operator(ch)) {
      if (!operators_stack.is_empty() &&
          precedence(operators_stack.peek()) > precedence(ch)) {
        char op = operators_stack.pop();
        char operand2 = operands_stack.pop();
        char operand1 = operands_stack.pop();

        operands_stack.push(operand2);
        operands_stack.push(operand1);
        operands_stack.push(op);
      }
      operators_stack.pop();
    }
  }

  while (!operators_stack.is_empty()) {
    char op = operators_stack.pop();
    char operand2 = operands_stack.pop();
    char operand1 = operands_stack.pop();

    operands_stack.push(operand2);
    operands_stack.push(operand1);
    operands_stack.push(op);
  }

  int i = 0;
  while (!operands_stack.is_empty()) {
    prefix[i++] = operands_stack.pop();
  }
  prefix[i] = '\0';
  reverse(prefix, i);
}

int main() {
  char infix[] = "(A-B/C)*(A/K-L)";
  char prefix[100];

  cout << "Infix Expression: " << infix << endl;

  infix_to_prefix(infix, prefix);

  cout << "Prefix Expression: " << prefix << endl;

  return 0;
}
