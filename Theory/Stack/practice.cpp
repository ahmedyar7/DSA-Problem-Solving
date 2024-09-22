#include <iostream>
using namespace std;

class Node {
 public:
  char data;
  Node* next;
  Node(char value) {
    data = value;
    next = nullptr;
  }
};

void push(Node*& head, char value) {
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

char pop(Node*& head) {
  if (head == nullptr) {
    return '_';
  }
  Node* current = head;
  head = head->next;
  char value = current->data;
  delete current;
  return value;
}

bool valid_parenthesis(char exp[]) {
  Node* stack = nullptr;
  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(') {
      push(stack, '(');
    }

    else if (exp[i] == ')') {
      if (stack == nullptr || pop(stack) != '(') {
        return false;
      }
    }
  }
  return stack == nullptr;
}

int main() {
  char exp[] = "((a+b)*(c-d))";

  if (valid_parenthesis(exp)) {
    cout << "Parentheses are valid." << endl;
  } else {
    cout << "Parentheses are invalid." << endl;
  }

  return 0;
}