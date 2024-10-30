#include <iostream>

#include "queue.h"
using namespace std;

int main() {
  Queue<int> q(10);
  q.enqueue(2);
  q.enqueue(32);
  q.enqueue(42);
  q.dequeue();

  cout << q.first_element() << endl;

  q.display();
}
