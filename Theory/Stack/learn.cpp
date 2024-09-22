#include <iostream>
using namespace std;

class Stack {
 public:
  int size;  // size of stack array
  int top;   // Pointer pointing to the top
  int* s;    // pointer that points to the dynamically creating the new array
};

void push(Stack* st, int value) {
  // Checking wether the stack is full
  if (st->top == st->size - 1) {
    cout << "Stack Overflow\n";
    return;
  }
  st->top++;
  st->s[st->top] = value;
  return;
}

int pop(Stack* st) {
  int x = -1;
  if (st->top == -1) {
    cout << "Stack Underflow\n";
    return;
  }
  x = st->s[st->top];
  st->top--;
  return x;
}

int main() {
  Stack st;
  cout << "Enter the size of the stack ";
  cin >> st.size;           // size of array allocating at runtime
  st.s = new int[st.size];  // Creating the new array at heap during
  st.top = -1;              // when top == -1 the stack is empty
  // Stack full when top == size-1
}