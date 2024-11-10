#include <iostream>
using namespace std;

#include "queue_with_2_stack.h"

int main() {
  CircularQueue q(5);
  q.enqueue(5);
  q.enqueue(10);
  q.enqueue(15);
  q.enqueue(25);
  q.enqueue(30);

  q.display();

  q.dequeue();
  q.dequeue();
  q.display();

  q.enqueue(25);
  q.enqueue(30);

  q.display();

  return 0;
}