#include <iostream>

#include "Node.h"
#include "circular_ll.h"
#include "doublycircularll.h"
#include "doublyll.h"
using namespace std;

int main() {
  doublycircularll cdll;

  cdll.insert_at_head(1);
  cdll.insert_at_head(2);
  cdll.insert_at_head(3);
  cdll.insert_at_head(4);
  cdll.insert_at_head(5);

  cdll.insert_at_tail(4);
  cdll.insert_at_tail(5);
  cdll.insert_at_tail(1);
  cdll.insert_at_tail(3);
  cdll.insert_at_tail(2);

  cdll.display();

  cdll.insert_at_position(999, 3);
  cdll.display();

  cdll.delete_head();
  cdll.display();

  cdll.delete_at_position(2);
  cdll.display();
}