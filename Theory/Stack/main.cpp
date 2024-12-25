#include <iostream>

#include "stackll.h"
using namespace std;

int main() {
  Stack s;
  char infix[] = "(A+B)*(C-D)";
  char postfix[100];
  char prefix[100];

  s.infix_to_postfix(infix, postfix);
  cout << "Postfix: " << postfix << endl;

  s.infix_to_prefix(infix, prefix);
  cout << "Prefix: " << prefix << endl;

  return 0;
}
