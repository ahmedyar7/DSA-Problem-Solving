#include <iostream>

#include "stackll.h"
using namespace std;

int main() {
  // Test your Stack class and conversions
  Stack s;
  const char* expression = "{[a+b]*(c+d)}";
  if (s.valid_parenthesis(expression)) {
    cout << "Valid Parentheses\n";
  } else {
    cout << "Invalid Parentheses\n";
  }

  char infix[] = "(a+b)*(c+d)";
  char postfix[100], prefix[100];

  s.infix_to_postfix(infix, postfix);
  cout << "Postfix: " << postfix << endl;

  s.infix_to_prefix(infix, prefix);
  cout << "Prefix: " << prefix << endl;

  return 0;
}