#include <iostream>

#include "Node.h"
#include "circular_ll.h"
#include "doublycircularll.h"
#include "doublyll.h"
using namespace std;

int main() {
  LinkedList ll;
  cout << ll.josephus(5, 3);
}