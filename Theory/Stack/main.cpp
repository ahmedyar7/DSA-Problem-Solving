#include <iostream>

#include "stackll.h"
using namespace std;

int main() {
  Stack s;

  // Testing push
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);

  cout << "Current Stack: ";
  s.display();

  // Testing top
  cout << "Top of the stack: " << s.top() << endl;

  // Testing pop
  cout << "Popped: " << s.pop() << endl;
  cout << "Popped: " << s.pop() << endl;

  cout << "Current Stack: ";
  s.display();

  // Testing top after pops
  cout << "Top of the stack after pops: " << s.top() << endl;

  return 0;
}