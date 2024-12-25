#include <cstring>
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class Stack {
 private:
  Node* front;

 public:
  Stack() { front = nullptr; }

  void push(int data) {
    Node* new_node = new Node(data);
    if (front == nullptr) {
      front = new_node;
      return;
    }
    new_node->next = front;
    front = new_node;
  }

  int pop() {
    if (front == nullptr) {
      cout << "List is empty\n";
      return -1;
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    delete temp;
    return value;
  }

  bool empty() { return front == nullptr; }
  int top() {
    if (front == nullptr) {
      cout << "List is empty\n";
      return -1;
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
  void infix_to_postfix(const char* exp, char* result) {
    Stack st;
    int k = 0;  // Index for result string
    for (int i = 0; exp[i] != '\0'; i++) {
      char ch = exp[i];

      if (is_operand(ch)) {
        result[k++] = ch;  // Append operand to result
      } else if (ch == '(') {
        st.push(ch);  // Push '(' to stack
      } else if (ch == ')') {
        // Pop until '(' is encountered
        while (!st.empty() && st.top() != '(') {
          result[k++] = st.pop();
        }
        st.pop();  // Remove '(' from stack
      } else {
        // Operator
        while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
          result[k++] = st.pop();  // Pop higher precedence operators
        }
        st.push(ch);  // Push current operator to stack
      }
    }

    // Pop remaining operators from stack
    while (!st.empty()) {
      result[k++] = st.pop();
    }
    result[k] = '\0';  // Null-terminate the result string
  }

  // Infix to Prefix Conversion
  void infix_to_prefix(const char* exp, char* result) {
    // Reverse the expression
    char reversed_exp[100];
    strcpy(reversed_exp, exp);
    reverse_string(reversed_exp);

    // Reverse parentheses
    for (int i = 0; reversed_exp[i] != '\0'; i++) {
      if (reversed_exp[i] == '(')
        reversed_exp[i] = ')';
      else if (reversed_exp[i] == ')')
        reversed_exp[i] = '(';
    }

    // Get postfix of the reversed expression
    char reversed_postfix[100];
    infix_to_postfix(reversed_exp, reversed_postfix);

    // Reverse the postfix result to get prefix
    reverse_string(reversed_postfix);
    strcpy(result, reversed_postfix);
  }
};
