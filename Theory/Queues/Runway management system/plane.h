#include <iostream>
using namespace std;

struct Plane {
  string flight_number;
  int priority;
};

class PriorityQueue {
 private:
   int front;
  int rear;
  int size;
  int *arr;

 public:
  PriorityQueue(int size) { arr = new int[size]; }
  ~PriorityQueue() { delete[] arr; }

  void arrive()
};