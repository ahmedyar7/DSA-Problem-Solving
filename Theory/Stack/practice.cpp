#include <iostream>
using namespace std;

class Node {
 private:
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
  Node* top;

 public:
  Stack() { top = nullptr; }

  bool empty() { return top == nullptr; }

  void push(char value) {
    Node* new_node = new Node(value);
    if (empty()) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  char pop() {
    Node* temp = top;
    top = top->next;
    char value = temp->data;
    delete temp;
    return value;
  }

  char peek() { return top->data; }
};

bool valid_parenthesis(char str[]) {
  Stack st;
  int i = 0;

  while (str[i] != '\0') {
    char ch = str[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.empty()) return false;
      char top = st.peek();
      if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
          (ch == '}' && top == '{')) {
        st.pop();
      } else {
        return false;
      }
    }

    i++;
  }
  return st.empty();
}

void reverse_string(char arr[]) {
  int len = 0;
  while (arr[len] != '\0') len++;

  for (int i = 0; i < len / 2; i++) {
    char temp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;

  return -1;
}

bool is_operand(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
          (ch >= '0' && ch <= '9'));
}

void infix_to_postfix(char infix[], char postfix[]) {
  Stack st;
  int i = 0;
  int j = 0;

  while (infix[i] != '\0') {
    char ch = infix[i];
    if (is_operand(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() & st.peek() != '(') {
        postfix[j++] = st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    } else {
      while (!st.empty() && precedence(ch) <= precedence(st.peek())) {
        postfix[j++] = st.pop();
      }
      st.push(ch);
    }
    i++;
  }
  while (!st.empty()) {
    postfix[j++] = st.pop();
  }
  postfix[j] = '\0';
}

void infix_to_prefix(char infix[], char prefix[]) {
  reverse_string(infix);

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
  reverse_string(postfix);

  int j = 0;
  while (postfix[j] != '\0') {
    prefix[j] = postfix[j];
    j++;
  }
  prefix[j] = '\0';
}

int main() {
  char exp[] = "(A-B/C)*(A/K-L)";
  cout << "Infix expression: " << exp << endl;

  cout << "Postfix Expression \n\n";
  char ans[100];
  infix_to_postfix(exp, ans);
  cout << ans << endl;

  cout << "Prefix  Expression \n\n";
  char ans1[100];
  infix_to_prefix(exp, ans1);
  cout << ans1 << endl;

  cout << "Is valid: " << (valid_parenthesis(exp) ? "Yes" : "No") << endl;

  return 0;
}