#include <iostream>
using namespace std;

/*
    ? IMPLEMENTATION OF STACK USING ARRAY
*/

class Stack {
 public:
  int size;
  int top;
  int *s;
};

void create(Stack &st) {
  cout << "Enter the size of the Stack: ";
  cin >> st.size;
  st.s = new int[st.size];
  st.top = -1;
}

void push(Stack *st, int value) {
  if (st->top == st->size - 1) {
    cout << "Stack Overflow!\n";
    return;
  }
  st->top++;
  st->s[st->top] = value;
}

int pop(Stack *st) {
  int x = -1;
  if (st->top == -1) {
    cout << "Stack Underflow!\n";
    return -1;
  }
  x = st->s[st->top];
  st->top--;
  return x;
}

void display(Stack st) {
  for (int i = st.top; i >= 0; i--) cout << st.s[i] << " ";
  cout << "\n";
}

int is_empty(Stack st) {
  if (st.top == -1) return 1;
  return 0;
}

int is_full(Stack st) {
  if (st.top == st.size - 1) return 1;
  return 0;
}

int peek(Stack st, int position) {
  if (st.top - position + 1 < 0) return -1;  // invalid position
  return st.s[st.top - position + 1];
}

int top_element(Stack st) {
  if (st.top == -1) {
    cout << "Stack Underflow\n";
    return 0;
  }
  return st.s[st.top];
}

int main() {
  Stack st;
  create(st);
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  push(&st, 50);

  display(st);

  cout << top_element(st) << "\n";
  cout << peek(st, 1) << "\n";

  cout << "After Pop Function call\n";
  pop(&st);
  pop(&st);
  display(st);
}