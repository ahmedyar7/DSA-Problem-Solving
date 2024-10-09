#include "browser_history.h"

void BrowserHistory::visit(string url) {
  Node* newNode = new Node(url);
  // Remove all forward history
  current->next = nullptr;
  newNode->prev = current;
  current->next = newNode;
  current = newNode;
}

string BrowserHistory::back(int steps) {
  while (steps > 0 && current->prev != nullptr) {
    current = current->prev;
    steps--;
  }
  return current->url;
}

string BrowserHistory::forward(int steps) {
  while (steps > 0 && current->next != nullptr) {
    current = current->next;
    steps--;
  }
  return current->url;
}