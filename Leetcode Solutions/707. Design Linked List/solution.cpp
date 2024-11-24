class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class MyLinkedList {
 public:
  Node* head;
  MyLinkedList() { head = nullptr; }

  int get(int index) {
    Node* temp = head;
    for (int i = 0; i < index && temp != nullptr; i++) {
      temp = temp->next;
    }
    if (temp == nullptr) return -1;  // return -1 if index is out of bounds
    return temp->data;
  }

  void addAtHead(int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
  }

  void addAtTail(int val) {
    Node* new_node = new Node(val);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {  // Traverse to the last node
      temp = temp->next;
    }
    temp->next = new_node;
  }

  void addAtIndex(int index, int val) {
    if (index < 0) return;

    if (index == 0) {
      addAtHead(val);
      return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }

    if (temp == nullptr) return;  // index is out of bounds

    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || head == nullptr) return;

    Node* temp = head;

    if (index == 0) {
      head = head->next;
      delete temp;
      return;
    }

    for (int i = 0; i < index - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }

    if (temp->next == nullptr) return;  // index is out of bounds

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
  }
};
