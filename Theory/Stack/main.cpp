#include <iostream>

#include "stack.h"
using namespace std;

int main() {
  stack<char> st(100);

  char exp[] = "[{()}]";
  cout << valid_parenthesis(exp);
}