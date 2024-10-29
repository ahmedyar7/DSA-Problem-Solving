#include <iostream>

#include "stack.h"

using namespace std;

int main() {
  char exp[] = "(a+b)(c-d)";
  cout << valid_parenthesis(exp) << endl;
  char postfix[100];
  infix_to_postfix(exp, postfix);
  cout << postfix;
}