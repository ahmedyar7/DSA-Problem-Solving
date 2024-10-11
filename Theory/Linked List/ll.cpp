#include <iostream>
#include <map>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = nullptr;
  }

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

  void display(Node* head) {
    if (head == nullptr) {
      cout << "List Is Empty\n";
      return;
    }
    while (head != nullptr) {
      cout << "[" << head->data << "] -> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  Node* middle_element(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node* merge_2_sorted_list(Node*& node1, Node*& node2) {
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;
  }

  Node* sort_ll(Node* head) {
    // code
  }

  Node* removeNthFromEnd(Node*& head, int n) {
    int counter = 0;
    Node* temp = head;
    while (temp != nullptr) {
      counter++;
      temp = temp->next;
    }
    if (counter == n) {
      Node* del_node = head;
      head = head->next;
      delete del_node;
      return head;
    } else {
      temp = head;
      for (int i = 0; i < counter - n - 1; i++) {
        temp = temp->next;
      }
      Node* del_node = temp->next;
      temp->next = temp->next->next;
      delete del_node;
      return head;
    }
    return head;
  }

  Node* getIntersectionNode(Node*& headA, Node*& headB) {
    Node* temp = headA;
    map<Node*, int> hashmap;

    while (temp != nullptr) {
      hashmap[temp] = 1;
      temp = temp->next;
    }
    temp = headB;
    while (temp != nullptr) {
      if (hashmap.find(temp) != hashmap.end()) {
        return temp;
      }
      temp = temp->next;
    }
    return temp;
  }

  Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* current = dummy;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr) {
      int sum = carry;

      if (temp1) sum = sum + temp1->data;
      if (temp2) sum = sum + temp2->data;

      Node* new_node = new Node(sum % 10);
      carry = sum / 10;
      current->next = new_node;
      current = current->next;

      if (temp1) temp1 = temp1->next;
      if (temp2) temp2 = temp2->next;
    }

    if (carry) {
      Node* new_node = new Node(carry);
      current->next = new_node;
    }
    return dummy->next;
  }

  Node* reverse_ll(Node* head) {
    Node* p = head;
    Node* q = nullptr;
    Node* r = nullptr;

    while (p != nullptr) {
      r = q;
      p = p;
      p = p->next;
    }
    return q;
  }

  Node* get_kth_node(Node* temp, int k) {
    k -= 1;
    while (temp != nullptr && k > 0) {
      k--;
      temp = temp->next;
    }
    return temp;
  }

  Node* reverse_in_group(Node* head, int k) {
    Node* temp = head;
    Node* prev_node = nullptr;
    Node* kth_node = nullptr;

    while (temp != nullptr) {
      kth_node = get_kth_node(temp, k);
      if (kth_node == nullptr) {
        if (prev_node) {
          prev_node->next = temp;
        }
        break;
      }
    }

    Node* next_node = kth_node->next;
    kth_node->next = nullptr;
  }
};

int main() {
  Node* head1 = nullptr;
  Node* head2 = nullptr;
  Node ll(0);

  ll.insert_at_tail(head1, 2);
  ll.insert_at_tail(head1, 3);
  ll.insert_at_tail(head1, 4);

  ll.insert_at_tail(head2, 4);
  ll.insert_at_tail(head2, 5);
  ll.insert_at_tail(head2, 6);

  Node* concate = ll.merge_2_sorted_list(head1, head2);
  ll.display(concate);
}