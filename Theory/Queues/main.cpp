#include <iostream>
using namespace std;

#include "stack_Qll.h"

int main() {
  queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << "Front element: " << q.get_front() << endl;
  cout << "Dequeue element: " << q.dequeue() << endl;
  cout << "Front element after dequeue: " << q.get_front() << endl;

  return 0;
}