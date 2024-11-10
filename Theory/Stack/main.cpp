#include <iostream>

#include "stack.h"
#include "stackll.h"
using namespace std;

int main() {
  Stack<int> st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  st.display();

  st.pop();
  st.display();
  st.pop();
  st.display();
}