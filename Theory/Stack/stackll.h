#include <cstring>
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
  Node* front;

 public:
  Stack() { front = nullptr; }

  void push(char data) {
    Node* new_node = new Node(data);
    if (front == nullptr) {
      front = new_node;
      return;
    }
    new_node->next = front;
    front = new_node;
  }

  char pop() {
    if (front == nullptr) {
      cout << "List is empty\n";
      return '\0';
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    delete temp;
    return value;
  }

  bool empty() { return front == nullptr; }
  char top() {
    if (front == nullptr) {
      cout << "List is empty\n";
      return '\0';
    }
    return front->data;
  }

  void display() {
    if (front == nullptr) {
      cout << "Stack is empty\n";
      return;
    }
    Node* temp = front;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "END-STACK\n";
  }

  bool valid_parenthesis(const char* exp) {
    int i = 0;
    Stack st;
    while (exp[i] != '\0') {
      char ch = exp[i];
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);
      } else if (ch == ']' || ch == '}' || ch == ')') {
        if (st.empty()) {
          return false;
        }
        char peek = st.top();
        if ((ch == ')' && peek == '(') || (ch == '}' && peek == '{') ||
            (ch == ']' && peek == '['))
          st.pop();
        else {
          return false;
        }
      }
      i++;
    }
    return st.empty();
  }

  int precedence(char exp) {
    if (exp == '+' || exp == '-') return 1;
    if (exp == '*' || exp == '/') return 2;
    if (exp == '^') return 3;
    return -1;
  }

  bool is_operand(const char exp) {
    return ((exp >= 'a' && exp <= 'z') || (exp >= 'A' && exp <= 'Z') ||
            (exp >= '0' && exp <= '9'));
  }

  void reverse_string(char* arr) {
    int length = 0;
    while (arr[length] != '\0') {
      length++;
    }

    for (int i = 0; i < length / 2; i++) {
      char temp = arr[i];
      arr[i] = arr[length - i - 1];
      arr[length - i - 1] = temp;
    }
  }

  // Infix to Postfix Conversion
  void infix_to_postfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    Stack st;

    // Iterate through the infix expression
    while (infix[i] != '\0') {
      char ch = infix[i];

      // If the character is an operand, add it to the postfix expression
      if (is_operand(ch)) {
        postfix[j++] = ch;
      }
      // If it's an opening parenthesis, push to stack
      else if (ch == '(') {
        st.push(ch);
      }
      // If it's a closing parenthesis, pop from stack until opening parenthesis
      else if (ch == ')') {
        while (!st.empty() && st.top() != '(') {
          postfix[j++] = st.pop();
        }
        if (!st.empty()) {
          st.pop();  // Pop the '('
        }
      }
      // If it's an operator
      else {
        while (!st.empty() && precedence(ch) <= precedence(st.top())) {
          postfix[j++] = st.pop();
        }
        st.push(ch);
      }
      i++;
    }

    // Pop remaining operators from stack
    while (!st.empty()) {
      postfix[j++] = st.pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
  }

  void infix_to_prefix(char* infix, char* prefix) {
    // Reverse the infix expression
    reverse_string(infix);

    int i = 0;
    // Change '(' to ')' and vice versa
    while (infix[i] != '\0') {
      if (infix[i] == '(') {
        infix[i] = ')';
      } else if (infix[i] == ')') {
        infix[i] = '(';
      }
      i++;
    }

    // Create a new postfix array to store result
    char postfix[100];  // Ensure the size is sufficient for the expression
    infix_to_postfix(infix, postfix);  // Convert the reversed infix to postfix

    // Reverse the postfix to get the prefix expression
    reverse_string(postfix);

    // Copy the result to prefix
    int j = 0;
    while (postfix[j] != '\0') {
      prefix[j] = postfix[j];
      j++;
    }
    prefix[j] = '\0';  // Null-terminate the prefix expression
  }
};

/*
  Algorithm For Infix to Postfix:
  1. Check if operand add to postfix array
  2. If opening bracket add to the stack
  3. If closing bracket then empty the stack untill you find the opening of the
  close bracket
  4. Check precedence if precedence is less than pop

*/