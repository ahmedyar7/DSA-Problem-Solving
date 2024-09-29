#include <iostream>
using namespace std;

class StackNode {
 public:
  char data;
  StackNode* next;
  StackNode(char value) {
    data = value;
    next = nullptr;
  }
};

class Stack {
 public:
  StackNode* top;
  Stack() { top = nullptr; }

  bool is_empty() { return top == nullptr; }

  void push(char value) {
    StackNode* new_node = new StackNode(value);
    new_node->next = top;
    top = new_node;
  }

  char pop() {
    if (is_empty()) {
      return '\0';  // Return null character for empty stack
    }
    StackNode* temp = top;
    top = top->next;
    char popped_value = temp->data;
    delete temp;
    return popped_value;
  }

  char peek() {
    if (is_empty()) {
      return '\0';
    }
    return top->data;
  }
};

// Check if a character is an operand (a letter or digit)
bool is_operand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
         (ch >= '0' && ch <= '9');
}

// Check if a character is an operator (+, -, *, /, ^)
bool is_operator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Get precedence of an operator
int precedence(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '^') {
    return 3;
  }
  return 0;
}

// Function to reverse a string
void reverse(char str[], int length) {
  int start = 0, end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// Function to convert infix expression to prefix
void infix_to_prefix(char infix[], char prefix[]) {
  int length = 0;
  while (infix[length] != '\0')
    length++;  // Get the length of the infix expression

  reverse(infix, length);  // Reverse the infix expression

  Stack operators;
  Stack operands;

  for (int i = 0; i < length; i++) {
    char ch = infix[i];

    // If the character is an operand, push it to the operands stack
    if (is_operand(ch)) {
      operands.push(ch);
    }
    // If the character is a closing parenthesis ')', push to operators stack
    else if (ch == ')') {
      operators.push(ch);
    }
    // If the character is an opening parenthesis '(', process until ')' is
    // found
    else if (ch == '(') {
      while (operators.peek() != ')' && !operators.is_empty()) {
        char op = operators.pop();
        char operand2 = operands.pop();
        char operand1 = operands.pop();
        operands.push(op);
        operands.push(operand1);
        operands.push(operand2);
      }
      operators.pop();  // Pop ')'
    }
    // If the character is an operator, process it
    else if (is_operator(ch)) {
      while (!operators.is_empty() &&
             precedence(operators.peek()) >= precedence(ch)) {
        char op = operators.pop();
        char operand2 = operands.pop();
        char operand1 = operands.pop();
        operands.push(op);
        operands.push(operand1);
        operands.push(operand2);
      }
      operators.push(ch);
    }
  }

  // Pop all remaining operators from the operators stack
  while (!operators.is_empty()) {
    char op = operators.pop();
    char operand2 = operands.pop();
    char operand1 = operands.pop();
    operands.push(op);
    operands.push(operand1);
    operands.push(operand2);
  }

  // Collect the result in the prefix array
  int i = 0;
  while (!operands.is_empty()) {
    prefix[i++] = operands.pop();
  }
  prefix[i] = '\0';

  // Reverse the prefix expression to get the correct output
  reverse(prefix, i);
}

// Main function
int main() {
  char infix[] = "(A-B/C)*(A/K-L)";
  char prefix[100];

  cout << "Infix Expression: " << infix << endl;

  infix_to_prefix(infix, prefix);

  cout << "Prefix Expression: " << prefix << endl;

  return 0;
}
