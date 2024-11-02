#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
 private:
  struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
  };

  Node* current;

 public:
  // Constructor: Initialize with the homepage
  BrowserHistory(string homepage) { current = new Node(homepage); }

  // Visit a new URL
  void visit(string url);

  // Move back 'steps' pages in the history
  string back(int steps);

  // Move forward 'steps' pages in the history
  string forward(int steps);
};

#endif