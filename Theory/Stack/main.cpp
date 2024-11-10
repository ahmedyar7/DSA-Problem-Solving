#include <iostream>

#include "stackll.h"
using namespace std;

int main() {
  Stack<int> st;

  char exp[] = "((a+b)*(c-d))/(e+f)";
  cout << valid_parenthesis(exp) << endl;

  char postfix[100];
  infix_to_postfix(exp, postfix);
  cout << postfix << endl;

  char prefix[100];
  infix_to_prefix(exp, prefix);
  cout << prefix << endl;
}