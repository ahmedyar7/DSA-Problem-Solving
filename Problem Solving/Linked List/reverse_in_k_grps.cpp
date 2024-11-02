#include <bits/stdc++.h>

#include <iostream>

using namespace std;

// ListNode class represents a
// node in a linked list
class ListNode {
 public:
  // Data stored in the node
  int data;

  // Pointer to the next node in the list
  ListNode* next;

  // Constructor with both data and
  // next node as parameters
  ListNode(int data1, ListNode* next1) {
    data = data1;
    next = next1;
  }

  // Constructor with only data as a
  // parameter, sets next to nullptr
  ListNode(int data1) {
    data = data1;
    next = nullptr;
  }
};

// This function has been explained
// in previous videos/articles

// Function to reverse a linked list
// using the 3-pointer approach
ListNode* reverseLinkedList(ListNode*& head) {
  ListNode* q = nullptr;
  ListNode* p = head;
  ListNode* r = nullptr;

  while (p != nullptr) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return q;
}

// Function to get the Kth node from
// a given position in the linked list
ListNode* getKthNode(ListNode* temp, int k) {
  // Decrement K as we already
  // start from the 1st node
  k -= 1;

  // Decrement K until it reaches
  // the desired position
  while (temp != NULL && k > 0) {
    // Decrement k as temp progresses
    k--;

    // Move to the next node
    temp = temp->next;
  }

  // Return the Kth node
  return temp;
}

// Function to reverse nodes in groups of K
ListNode* kReverse(ListNode* head, int k) {
  // Initialize a temporary
  // node to traverse the list
  ListNode* temp = head;

  // Initialize a pointer to track the
  // ;ast node of the previous group
  ListNode* prevLast = NULL;

  // Traverse through the linked list
  while (temp != NULL) {
    // Get the Kth node of the current group
    ListNode* kThNode = getKthNode(temp, k);

    // If the Kth node is NULL
    // (not a complete group)
    if (kThNode == NULL) {
      // If there was a previous group,
      // link the last node to the current node
      if (prevLast) {
        prevLast->next = temp;
      }

      // Exit the loop
      break;
    }

    // Store the next node
    // after the Kth node
    ListNode* nextNode = kThNode->next;

    // Disconnect the Kth node
    // to prepare for reversal
    kThNode->next = NULL;

    // Reverse the nodes from
    // temp to the Kth node
    reverseLinkedList(temp);

    // Adjust the head if the reversal
    // starts from the head
    if (temp == head) {
      head = kThNode;
    } else {
      // Link the last node of the previous
      // group to the reversed group
      prevLast->next = kThNode;
    }

    // Update the pointer to the
    // last node of the previous group
    prevLast = temp;

    // Move to the next group
    temp = nextNode;
  }

  // Return the head of the
  // modified linked list
  return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
  ListNode* temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  // Create a linked list with
  // values 5, 4, 3, 7, 9 and 2
  ListNode* head = new ListNode(5);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(7);
  head->next->next->next->next = new ListNode(9);
  head->next->next->next->next->next = new ListNode(2);

  // Print the original linked list
  cout << "Original Linked List: ";
  printLinkedList(head);

  // Reverse the linked list
  head = kReverse(head, 3);

  // Print the reversed linked list
  cout << "Reversed Linked List: ";
  printLinkedList(head);

  return 0;
}