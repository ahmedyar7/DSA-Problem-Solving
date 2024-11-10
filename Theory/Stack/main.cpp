#include <iostream>

#include "stack.h"
using namespace std;

int main() {
  stack<char> st(100);

  char exp[] = "((a+b)*(c-d))/(e+f)";

  char postfix[100];
  infix_to_postfix(exp, postfix);
  cout << postfix << endl;

  char prefix[100];
  infix_to_prefix(exp, prefix);
  cout << prefix << endl;
}