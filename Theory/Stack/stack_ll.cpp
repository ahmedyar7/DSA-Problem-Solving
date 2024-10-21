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

class Stack {
 public:
  Node* top;
  Stack() { top = nullptr; }

  void push(char value) {
    Node* new_node = new Node(value);
    new_node->next = top;
    top = new_node;
  }

  char pop() {
    if (top == nullptr) return '\0';
    char value = top->data;
    Node* head = top;
    top = top->next;
    delete head;
    return value;
  }

  char peek() {
    if (top == nullptr) return '\0';
    return top->data;
  }

  bool is_empty() { return top == nullptr; }
};

void reverse_str(char arr[]) {
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

bool is_operand(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
          (ch >= '0' && ch <= '9'));
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;
  return -1;
}

void infix_to_postfix(char infix[], char postfix[]) {
  Stack st;
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    char ch = infix[i];

    if (is_operand(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        postfix[j++] = st.pop();
      }
      if (!st.is_empty()) {
        st.pop();  // Pop the '('
      }
    } else {
      while (!st.is_empty() && precedence(ch) <= precedence(st.peek())) {
        postfix[j++] = st.pop();
      }
      st.push(ch);
    }
    i++;
  }

  while (!st.is_empty()) {
    postfix[j++] = st.pop();
  }
  postfix[j] = '\0';  // Null terminate the postfix expression
}

void infix_to_prefix(char infix[], char prefix[]) {
  reverse_str(infix);

  int i = 0;
  while (infix[i] != '\0') {
    if (infix[i] == '(') {
      infix[i] = ')';
    } else if (infix[i] == ')') {
      infix[i] = '(';
    }
    i++;
  }

  char postfix[100];
  infix_to_postfix(infix, postfix);
  reverse_str(postfix);

  int j = 0;
  while (postfix[j] != '\0') {
    prefix[j] = postfix[j];
    j++;
  }
  prefix[j] = '\0';  // Null terminate the prefix expression
}

bool valid_parenthesis(char arr[]) {
  Stack st;
  int i = 0;

  while (arr[i] != '\0') {
    char ch = arr[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.is_empty()) return false;
      char top = st.peek();
      if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
          (ch == ']' && top == '[')) {
        st.pop();
      } else {
        return false;
      }
    }
    i++;
  }

  return st.is_empty();
}

int main() {
  char exp[] = "{{[(A-B/C)]}}*((A/K-L))";
  cout << "Infix expression: " << exp << endl;

  char postfix[100];
  infix_to_postfix(exp, postfix);
  cout << "Postfix Expression: " << postfix << endl;

  char prefix[100];
  infix_to_prefix(exp, prefix);
  cout << "Prefix Expression: " << prefix << endl;

  cout << "Is valid: " << (valid_parenthesis(exp) ? "Yes" : "No") << endl;

  return 0;
}
