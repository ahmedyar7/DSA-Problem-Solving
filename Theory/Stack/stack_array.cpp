#include <iostream>
using namespace std;

class Stack {
 private:
  int size;
  int top;
  char* arr;

 public:
  Stack(int size) {
    this->size = size;
    top = -1;
    arr = new char[size];
  }

  bool empty() { return top == -1; }
  bool full() { return top == size - 1; }

  void push(char value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    top++;
    arr[top] = value;
  }

  char pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    char value = arr[top];
    top--;
    return value;
  }

  char peek() { return arr[top]; }
};

bool valid_parenthesis(char arr[]) {
  int i = 0;
  Stack st(100);
  while (arr[i] != '\0') {
    char ch = arr[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.empty()) return false;
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
  return st.empty();
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;

  return -1;
}

void reverse_string(char arr[]) {
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

void infix_to_postfix(char infix[], char postfix[]) {
  Stack st(100);
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    char ch = infix[i];
    if (is_operand(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.peek() != '(') {
        postfix[j++] = st.pop();
      }
      if (!st.empty()) {
        st.pop();  // Pop the '('
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
  postfix[j] = '\0';  // Null terminate the postfix expression
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
  prefix[j] = '\0';  // Null terminate the prefix expression
}

int main() {
  char exp[] = "(A-B/C)*(A/K-L)";
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
