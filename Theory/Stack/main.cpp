#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  // Create an instance of Stack
  Stack stack(100);

  // Example expressions
  char infixExpression[] = "(A+B)*C";
  char postfixExpression[100];
  char prefixExpression[100];
  char validExpression[] = "{[()]}";    // Valid parenthesis example
  char invalidExpression[] = "{[(])}";  // Invalid parenthesis example

  // Validate parenthesis
  cout << "Valid Parenthesis Test:\n";
  if (stack.valid_parenthesis(validExpression)) {
    cout << validExpression << " is valid.\n";
  } else {
    cout << validExpression << " is invalid.\n";
  }
  if (stack.valid_parenthesis(invalidExpression)) {
    cout << invalidExpression << " is valid.\n";
  } else {
    cout << invalidExpression << " is invalid.\n";
  }

  // Convert Infix to Postfix
  cout << "\nInfix to Postfix Conversion:\n";
  cout << "Infix Expression: " << infixExpression << endl;
  stack.infix_to_postfix(infixExpression, postfixExpression);
  cout << "Postfix Expression: " << postfixExpression << endl;

  // Convert Infix to Prefix
  cout << "\nInfix to Prefix Conversion:\n";
  stack.infix_to_prefix(infixExpression, prefixExpression);
  cout << "Infix Expression: " << infixExpression << endl;
  cout << "Prefix Expression: " << prefixExpression << endl;

  return 0;
}
