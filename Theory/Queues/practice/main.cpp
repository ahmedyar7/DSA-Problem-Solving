#include "queue.cpp"
#include "queue.h"

int main() {
  Queue qu(5);

  qu.push(10);
  qu.push(20);
  qu.push(30);
  qu.push(40);
  qu.push(50);

  qu.display();
}