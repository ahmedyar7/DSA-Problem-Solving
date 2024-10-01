#include <iostream>
using namespace std;

class Stack {
 private:
  int top;
  int capacity;
  char* array;

 public:
  Stack(int size) {
    capacity = size;
    array = new char[capacity];
    top = -1;
  }

  ~Stack() { delete[] array; }

  bool is_empty() { return top == -1; }

  bool is_full() { return top == capacity - 1; }

  void push(char value) {
    if (is_full()) {
      cout << "Stack overflow" << endl;
      return;
    }
    array[++top] = value;
  }

  char pop() {
    if (is_empty()) {
      cout << "Stack underflow" << endl;
      return '\0';
    }
    return array[top--];
  }

  char peek() {
    if (is_empty()) {
      return '\0';
    }
    return array[top];
  }
};

// Function to return precedence of operators
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string s) {
  Stack st(
      s.length());  // Manual stack creation with size based on input length
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is an operand, add it to the output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
      result += c;
    }
    // If the scanned character is an ‘(‘, push it to the stack.
    else if (c == '(') {
      st.push(c);
    }
    // If the scanned character is a ‘)’, pop and output from the stack until an
    // ‘(‘ is encountered.
    else if (c == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        result += st.pop();
      }
      st.pop();  // Popping the '(' from the stack
    }
    // If an operator is scanned
    else {
      while (!st.is_empty() && prec(c) <= prec(st.peek())) {
        result += st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.is_empty()) {
    result += st.pop();
  }

  cout << "Postfix expression: " << result << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}
