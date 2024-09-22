#include <iostream>
using namespace std;

class Stack {
 public:
  int size;
  int top;
  int* s;
};

// Time Complexity O(1)
void push(Stack* st, int value) {
  if (st->top == st->size - 1) {
    cout << "Stack Overflow!\n";
    return;
  }
  st->top++;
  st->s[st->top] = value;
  return;
}

// Time Complexity O(1)
int pop(Stack* st) {
  int x = -1;
  if (st->top == -1) {
    cout << "Stack Underflow\n";
    return -1;
  }
  x = st->s[st->top];
  st->top--;
  return x;
}

// Time Complexity O(1)
int peek(Stack st, int position) {
  int x = -1;
  if (st.top - position + 1 < 0) {
    cout << "Invalid Position!\n";
    return -1;
  }
  x = st.s[st.top - position + 1];
  return x;
}

int stack_top(Stack st) {
  if (st.top == -1) {
    cout << "Stack Underflow!\n";
    return -1;
  }
  return st.s[st.top];
}

int is_empty(Stack st) { return st.top == -1; }

int is_full(Stack st) { return st.top == st.size - 1; }

void display(Stack st) {
  for (int i = st.top; i >= 0; i--) {
    cout << st.s[i] << " ";
  }
  cout << "\n";
}

void create_stack(Stack& st) {
  cout << "Enter the size of Array: ";
  cin >> st.size;
  st.s = new int[st.size];
  st.top = -1;
}

int main() {
  Stack st;
  create_stack(st);
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);

  display(st);

  return 0;
}
