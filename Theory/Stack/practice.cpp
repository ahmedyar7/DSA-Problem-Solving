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
      cout << "Stack is Full\n";
      return;
    }
    top++;
    arr[top] = value;
    return;
  }

  char pop() {
    if (empty()) {
      cout << "Stack is Empty\n";
      return '\0';
    }
    int value = arr[top];
    top--;
    return value;
  }

  char peek() { return arr[top]; }
};

bool valid_parenthesis(char arr[]) {
  int i = 0;
  int len = 0;
  while (arr[len] != '\0') {
    len++;
  }
  Stack st(len);
  while (arr[i] != '\0') {
    char ch = arr[i];

    if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
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

void reverse_string(char arr[]) {
  int len = 0;
  while (arr[len] != '\0') {
    len++;
  }

  for (int i = 0; i < len / 2; i++) {
    char temp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '/' || ch == '*') return 2;
  if (ch == '^') return 3;

  return -1;
}

bool is_operand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9'))
    return true;
  return false;
}

void infix_to_postfix(char infix[], char ans[]) {
  Stack st(100);

  int i = 0;
  int j = 0;

  while (infix[i] != '\0') {
    char ch = infix[i];

    if (is_operand(ch)) {
      ans[j++] = ch;
    }

    else if (ch == '(') {
      st.push(ch);
    }

    else if (ch == ')') {
      while (!st.empty() && st.peek() != '(') {
        ans[j++] = st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    }

    else {
      while (!st.empty() && precedence(ch) <= precedence(st.peek())) {
        ans[j++] = st.pop();
      }
      st.push(ch);
    }
    i++;
  }

  while (!st.empty()) {
    ans[j++] = st.pop();
  }

  ans[j] = '\0';
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

  cout << "Postfix Expression \n\n";
  char ans[100];
  infix_to_postfix(exp, ans);
  cout << ans << endl;

  // cout << "Prefix  Expression \n\n";
  // char ans1[100];
  // infix_to_prefix(exp, ans1);
  // cout << ans1 << endl;

  cout << "Is valid: " << (valid_parenthesis(exp) ? "Yes" : "No") << endl;

  return 0;
}