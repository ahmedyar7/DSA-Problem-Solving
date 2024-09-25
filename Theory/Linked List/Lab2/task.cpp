#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  // Constructor
  Node(int value) {
    data = value;
    next = nullptr;
  }

  // METHODS

  // Insert at tail
  void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
    return;
  }

  // Insert at head
  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head = new_node;
    return;
  }

  // Insert at location
  void insert_at_location(Node*& head, int value, int postion) {
    Node* new_node = new Node(value);

    if (postion < 0) {
      cout << "Invalid Position\n";
      return;
    }

    if (postion == 1) {
      insert_at_head(new_node, value);
      return;
    }

    Node* current = head;
    for (int i = 1; i < postion - 1 && current->next != nullptr; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return;
  }

  // Delete at location
  int delete_at_location(Node*& head, int position) {
    if (position < 0) {
      cout << "Invalid Position\n";
      return -1;
    }

    if (position == 1) {
      head = head->next;
      int value = head->data;
      delete head;
    }

    Node* current = head;
    Node* previous = nullptr;

    for (int i = 0; i < position && current->next != nullptr; i++) {
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
    int deleted_value = current->data;
    delete current;

    return deleted_value;
  }

  // Disply Linked List
  void display(Node* head) {
    if (head == nullptr) {
      return;
    }
    while (head != nullptr) {
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << "NULL\n";
    return;
  }

  // Count Nodes
  int count_nodes(Node* head) {
    int counter = 0;
    if (head == nullptr) {
      return counter;
    }

    while (head != nullptr) {
      counter++;
      head = head->next;
    }
    return counter;
  }
};

void main_menu() {
  cout << "\n\nWelcome to the Linked List \n\n";
  cout << "1. Insert Node at tail\n";
  cout << "2. Insert Node at head\n";
  cout << "3. Insert Node at any Position\n";
  cout << "4. Delete From any Postion\n";
  cout << "5. Display Linked List\n";
  cout << "6. Count Number of total nodes\n\n";
}

int main() {
  Node* head = nullptr;
  Node node(0);  // object of Node class

  bool run = true;
  while (run) {
    main_menu();

    int user_input;
    cout << "Enter Your Choice: ";
    cin >> user_input;

    if (user_input == 1) {
      cout << "Enter the value to enter: ";
      int value;
      cin >> value;
      node.insert_at_tail(head, value);
    }

    else if (user_input == 2) {
      cout << "Enter the value to enter: ";
      int value;
      cin >> value;
      node.insert_at_head(head, value);
    }

    else if (user_input == 3) {
      cout << "Enter the value to enter: ";
      int value;
      cin >> value;

      cout << "Enter the Location: ";
      int location;
      cin >> location;

      node.insert_at_location(head, value, location);
    }

    else if (user_input == 4) {
      cout << "Enter the Position you want to delete: ";
      int location;
      cin >> location;
      int deleted_value = node.delete_at_location(head, location);
      cout << deleted_value << "\n";
    }

    else if (user_input == 5) {
      cout << "Displaying the Linked List\n\n";
      node.display(head);
    }

    else if (user_input == 6) {
      cout << "Total Count of Nodes: " << node.count_nodes(head) << "\n";
    }

    else {
      cout << "Enter a Valid Input\n";
    }
  }
}

// export TERM=xterm-256color
// export PATH=$PATH:/root/.local/bin
// eval "$(oh-my-posh init bash)"
// eval "$(oh-my-posh init bash --config '/root/themes/quick-term.omp.json')"