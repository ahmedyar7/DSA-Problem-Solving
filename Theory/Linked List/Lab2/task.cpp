#include <iostream>
using namespace std;

class SinglyLinkedList {
 public:
  int data;
  SinglyLinkedList* next;

  // Constructor
  SinglyLinkedList(int value) {
    data = value;
    next = nullptr;
  }

  ~SinglyLinkedList() {}

  // METHODS

  // Insert at tail
  void insert_at_tail(SinglyLinkedList*& head, int value) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
    if (head == nullptr) {
      head = new_SinglyLinkedList;
      return;
    }

    SinglyLinkedList* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_SinglyLinkedList;
    return;
  }

  // Insert at head
  void insert_at_head(SinglyLinkedList*& head, int value) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
    if (head == nullptr) {
      head = new_SinglyLinkedList;
      return;
    }
    new_SinglyLinkedList->next = head;
    head = new_SinglyLinkedList;
    return;
  }

  // Insert at location
  void insert_at_location(SinglyLinkedList*& head, int value, int postion) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);

    if (postion < 0) {
      cout << "Invalid Position\n";
      return;
    }

    if (postion == 1) {
      insert_at_head(new_SinglyLinkedList, value);
      return;
    }

    SinglyLinkedList* current = head;
    for (int i = 1; i < postion - 1 && current->next != nullptr; i++) {
      current = current->next;
    }
    new_SinglyLinkedList->next = current->next;
    current->next = new_SinglyLinkedList;
    return;
  }

  // Delete at location
  int delete_at_location(SinglyLinkedList*& head, int position) {
    if (position < 0) {
      cout << "Invalid Position\n";
      return -1;
    }

    if (position == 1) {
      head = head->next;
      int value = head->data;
      delete head;
    }

    SinglyLinkedList* current = head;
    SinglyLinkedList* previous = nullptr;

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
  void display(SinglyLinkedList* head) {
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

  // Count SinglyLinkedLists
  int count_SinglyLinkedLists(SinglyLinkedList* head) {
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
  cout << "1. Insert SinglyLinkedList at tail\n";
  cout << "2. Insert SinglyLinkedList at head\n";
  cout << "3. Insert SinglyLinkedList at any Position\n";
  cout << "4. Delete From any Postion\n";
  cout << "5. Display Linked List\n";
  cout << "6. Count Number of total SinglyLinkedLists\n\n";
}

int main() {
  SinglyLinkedList* head = nullptr;
  SinglyLinkedList SinglyLinkedList(0);  // object of SinglyLinkedList class

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
      SinglyLinkedList.insert_at_tail(head, value);
    }

    else if (user_input == 2) {
      cout << "Enter the value to enter: ";
      int value;
      cin >> value;
      SinglyLinkedList.insert_at_head(head, value);
    }

    else if (user_input == 3) {
      cout << "Enter the value to enter: ";
      int value;
      cin >> value;

      cout << "Enter the Location: ";
      int location;
      cin >> location;

      SinglyLinkedList.insert_at_location(head, value, location);
    }

    else if (user_input == 4) {
      cout << "Enter the Position you want to delete: ";
      int location;
      cin >> location;
      int deleted_value = SinglyLinkedList.delete_at_location(head, location);
      cout << deleted_value << "\n";
    }

    else if (user_input == 5) {
      cout << "Displaying the Linked List\n\n";
      SinglyLinkedList.display(head);
    }

    else if (user_input == 6) {
      cout << "Total Count of SinglyLinkedLists: "
           << SinglyLinkedList.count_SinglyLinkedLists(head) << "\n";
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