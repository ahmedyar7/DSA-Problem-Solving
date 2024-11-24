class BrowserHistory {
 private:
  struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
  };

 public:
  Node* current;

  BrowserHistory(string homepage) { current = new Node(homepage); }

  void visit(string url) {
    Node* newNode = new Node(url);
    // Remove all forward history
    current->next = nullptr;
    newNode->prev = current;
    current->next = newNode;
    current = newNode;
  }

  string back(int steps) {
    while (steps > 0 && current->prev != nullptr) {
      current = current->prev;
      steps--;
    }
    return current->url;
  }

  string forward(int steps) {
    while (steps > 0 && current->next != nullptr) {
      current = current->next;
      steps--;
    }
    return current->url;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */