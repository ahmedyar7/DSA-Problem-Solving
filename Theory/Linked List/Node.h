#include <iostream>
using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <typename T>
class LinkedList {
 private:
  Node<T>* head;

 public:
  LinkedList() { head = nullptr; }

  void insert_at_tail(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
  }

  void insert_at_head(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head = new_node;
  }

  void print() {
    if (head == nullptr) {
      cout << "Head is empty\n";
      return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "end\n";
  }

  void insert_at_position(int position, T data) {
    if (position <= 0) {
      cout << "Please enter valid position\n";
      return;
    }
    Node<T>* new_node = new Node<T>(data);
    if (position == 1 || head == nullptr) {
      new_node->next = head;
      head = new_node;
      return;
    }
    Node<T>* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }

  void max_n_min() {
    if (head == nullptr) {
      cout << "List is empty\n";
      return;
    }
    int max = head->data;
    int min = head->data;
    Node<T>* temp = head;

    while (temp != nullptr) {
      if (temp->data > max) {
        max = temp->data;
      }
      if (temp->data < min) {
        min = temp->data;
      }
      temp = temp->next;
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
  }

  void count_nodes() {
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    cout << "Total Nodes: " << count << endl;
  }

  Node<T>* reverse_node() {
    if (head == nullptr) {
      cout << "List is empty\n";
      return nullptr;
    }
    Node<T>* p = head;
    Node<T>* q = nullptr;
    Node<T>* r = nullptr;
    while (p != nullptr) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    head = q;
    return q;
  }

  bool find_element(T element) {
    if (head == nullptr) {
      cout << "List is empty\n";
      return false;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
      if (temp->data == element) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  Node<T>* concatenation(Node<T>* head_1, Node<T>* head_2) {
    if (head_1 == nullptr) {
      return head_2;
    }
    if (head_2 == nullptr) {
      return head_1;
    }
    Node<T>* temp = head_1;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    head_2->next = nullptr;
    return head_1;  // Return concatenated list's head
  }

  Node<T>* merge_sorted(Node<T>* head1, Node<T>* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node<T>* first = head1;
    Node<T>* second = head2;
    Node<T>* third = nullptr;
    Node<T>* last = nullptr;

    if (first->data < second->data) {
      third = last = first;
      first = first->next;
    } else {
      third = last = second;
      second = second->next;
    }

    while (first != nullptr && second != nullptr) {
      if (first->data < second->data) {
        last->next = first;
        last = first;
        first = first->next;
      } else {
        last->next = second;
        last = second;
        second = second->next;
      }
    }

    if (first == nullptr) {
      last->next = second;
    } else {
      last->next = first;
    }
    return third;
  }

  Node<T>* find_mid(Node<T>* head) {
    if (head == nullptr) {
      cout << "List is empty\n";
      return nullptr;
    }

    Node<T>* slow = head;
    Node<T>* fast = slow->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node<T>* sort(Node<T>* head) {
    if (head == nullptr && head->next == nullptr) {
      return nullptr;
    }

    Node<T>* left = head;
    Node<T>* mid = find_mid(head);
    Node<T>* right = mid->next;
    mid->next = nullptr;

    left = sort(left);
    right = sort(right);

    return (left, right);
  }

  // Destructor
  ~LinkedList() {
    Node<T>* temp = head;
    while (temp != nullptr) {
      Node<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
  }
};
