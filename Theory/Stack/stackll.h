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
    Node* temp = front;
    new_node->next = temp;
    front = new_node;
    return;
  }

  int pop() {
    if (front == nullptr) {
      cout << "List is empty\n";
      return -1;
    }
    if (front->next == nullptr) {
      delete front;
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

      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else if (ch == ')' || ch == '}' || ch == ']') {
        char upper = st.top();

        if ((ch == ')' && upper == '(') || (ch == '}' && upper == '{') ||
            (ch == ']' && upper == '['))
          st.pop();
        else
          return false;
      }
    }
  }
};