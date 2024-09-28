#include <iostream>
using namespace std;

class Stack {
 private:
 public:
  int size;
  int top;
  int *s;

  void create_stack(Stack &st) {
    cout << "Enter the size of stack: ";
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;
  }

  void push(Stack *st, int value) {
    if (st->top == st->size - 1) {
      cout << "Stack Overflow\n";
      return;
    }
    st->top++;
    st->s[st->top] = value;
    return;
  }

  void display(Stack st) {
    for (int i = st.top; i >= 0; i--) {
      cout << st.s[i] << " ";
    }
    cout << endl;
  }

  int pop(Stack *st) {
    if (st->top == -1) {
      cout << "Stack is empty\n";
      return -1;
    }
    int value = st->s[st->top];
    st->top--;
    cout << value << endl;
  }

  int peek(Stack st, int position) {
    if (st.top == -1) {
      cout << "Stack Is Empty\n";
      return -1;
    }
    cout << st.s[st.top - position + 1] << " ";
  }

  bool is_empty(Stack st) {
    if (st.top == -1) {
      return 1;
    }
    return 0;
  }

  bool is_full(Stack st) {
    if (st.top == -1) {
      return 1;
    }
    return 0;
  }
};

int main() {
  Stack st;
  st.create_stack(st);

  st.push(&st, 10);
  st.push(&st, 20);
  st.push(&st, 30);
  st.push(&st, 40);
  st.push(&st, 50);

  st.display(st);

  st.pop(&st);
  st.pop(&st);

  st.peek(st, 1);
  st.peek(st, 2);
}