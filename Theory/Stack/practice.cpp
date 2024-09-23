#include <iostream>
using namespace std;

class Stack {
 public:
  int size;
  int top;
  int* s;
};

void push(Stack* st, int value) {
  if (st->top == st->size - 1) {
    cout << "Stack Overflow\n";
    return;
  }
  st->top++;
  st->s[st->top] = value;
}

int pop(Stack* st) {
  if (st->top == -1) {
    cout << "Stack Underflow\n";
    return 0;
  }
  int value = st->s[st->top];
  st->top--;
  return value;
}

void create_stack(Stack& st) {
  cout << "Enter the size of Stack ";
  cin >> st.size;
  st.s = new int[st.size];
  st.top = -1;
}

void display(Stack st) {
  for (int i = st.top; i >= 0; i--) {
    cout << st.s[i] << " ";
  }
  cout << endl;
}

int peek(Stack* st, int position) {
  if (st->top - position + 1 < 0) {
    cout << "Invalid Position\n";
    return -1;
  }
  int value = st->s[st->top - position + 1];
  return value;
}

int main() {
  Stack st;
  create_stack(st);
  cout << "Pushing the element\n";
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);

  display(st);

  cout << "After Popping\n";
  pop(&st);
  pop(&st);
  display(st);

  cout << peek(&st, 2);
}