#include <iostream>
using namespace std;

void increment(int& a) { a++; }

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  /*
        1. Pointer variable that pointer towards the address of a
        2. & -> Address of Operators
        3. * -> Dereference of Operators

        POINTER TO POINTER:
        - Pointer that store address to another pointer
  */

  cout << &a << endl;
  cout << ptr << endl;

  int** c = &ptr;  // Pointer to pointer
  cout << "The value of Pointer " << **&ptr << endl;
  cout << "The value of Pointer " << **c << endl;
  int a = 1;
  for (int i = 0; i < 5; i++) {
    increment(a);
    cout << a << endl;
  }

  int a = 5, b = 10;
  swap(a, b);
  cout << a << " " << b << endl;

  return 0;
}
