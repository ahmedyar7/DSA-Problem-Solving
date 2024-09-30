#include <iostream>
using namespace std;

// Node structure for the stack
class StackNode {
 public:
  char data;
  StackNode* next;
  StackNode(char value) {
    data = value;
    next = nullptr;
  }
};

// Stack class to handle stack operations
class Stack {
 public:
  StackNode* top;

  Stack() { top = nullptr; }

  bool isEmpty() { return top == nullptr; }

  void push(char value) {
    StackNode* newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
  }

  char pop() {
    if (isEmpty()) {
      return '\0';
    }
    StackNode* temp = top;
    top = top->next;
    char poppedValue = temp->data;
    delete temp;
    return poppedValue;
  }

  char peek() {
    if (!isEmpty()) {
      return top->data;
    }
    return '\0';
  }
};

// Function to check if character is an operand (either letter or digit)
bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
         (ch >= '0' && ch <= '9');
}

// Function to check if character is an operator
bool isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get precedence of operators
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
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// Function to convert infix expression to prefix
void infixToPrefix(char infix[], char prefix[]) {
  int length = 0;
  while (infix[length] != '\0') {
    length++;
  }

  // Reverse the infix expression
  reverse(infix, length);

  Stack operators;
  Stack operands;

  // Iterate through the reversed infix expression
  for (int i = 0; i < length; i++) {
    char ch = infix[i];

    // If character is an operand, push to operand stack
    if (isOperand(ch)) {
      operands.push(ch);
    }
    // If character is ')', push to operator stack
    else if (ch == ')') {
      operators.push(ch);
    }
    // If character is '(', pop until ')' is found
    else if (ch == '(') {
      while (operators.peek() != ')' && !operators.isEmpty()) {
        char op = operators.pop();
        char operand1 = operands.pop();
        char operand2 = operands.pop();
        operands.push(operand1);  // Push operand1
        operands.push(operand2);  // Push operand2
        operands.push(op);        // Push operator
      }
      operators.pop();  // Pop ')'
    }
    // If the character is an operator
    else if (isOperator(ch)) {
      while (!operators.isEmpty() &&
             precedence(operators.peek()) >= precedence(ch)) {
        char op = operators.pop();
        char operand1 = operands.pop();
        char operand2 = operands.pop();
        operands.push(operand1);  // Push operand1
        operands.push(operand2);  // Push operand2
        operands.push(op);        // Push operator
      }
      operators.push(ch);
    }
  }

  // Pop remaining operators from the operator stack
  while (!operators.isEmpty()) {
    char op = operators.pop();
    char operand1 = operands.pop();
    char operand2 = operands.pop();
    operands.push(operand1);  // Push operand1
    operands.push(operand2);  // Push operand2
    operands.push(op);        // Push operator
  }

  // Now the operands stack contains the prefix expression in reverse order
  int i = 0;
  while (!operands.isEmpty()) {
    prefix[i++] = operands.pop();
  }
  prefix[i] = '\0';

  // Reverse the final result to get the correct prefix expression
  reverse(prefix, i);
}

int main() {
  char infix[] = "(A-B/C)*(A/K-L)";
  char prefix[100];

  cout << "Infix Expression: " << infix << endl;

  infixToPrefix(infix, prefix);

  cout << "Prefix Expression: " << prefix << endl;

  return 0;
}
