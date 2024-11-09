#include <iostream>

#include "Node.h"
#include "circular_ll.h"
#include "doublyll.h"
using namespace std;

int main() {
  Doublyll dll;

  dll.insert_at_head(5);
  dll.insert_at_head(53);
  dll.insert_at_head(544);
  dll.insert_at_head(5422);
  dll.insert_at_head(542243);

  dll.insert_at_tail(5);
  dll.insert_at_tail(53);
  dll.insert_at_tail(544);
  dll.insert_at_tail(5422);
  dll.insert_at_tail(542243);

  dll.display();
}
