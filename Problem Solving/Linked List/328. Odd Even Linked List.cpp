#include <iostream>
#include <vector>
using namespace std;

class ListNode {
 private:
 public:
  int data;
  ListNode* next;

  ListNode(int data) {
    this->data = data;
    next = nullptr;
  }

  // Array Approach
  ListNode* oddEvenList_1(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* temp = head;
    vector<int> vec;

    // Adding odd indexed values
    while (temp != nullptr && temp->next != nullptr) {
      vec.push_back(temp->data);
      temp = temp->next->next;
    }
    if (temp) vec.push_back(temp->data);

    // Adding even indexed values
    temp = head->next;
    while (temp != nullptr && temp->next != nullptr) {
      vec.push_back(temp->data);
      temp = temp->next->next;
    }
    if (temp) vec.push_back(temp->data);

    int it = 0;
    temp = head;

    while (temp != nullptr) {
      vec[it] = temp->data;
      it++;
      temp = temp->next;
    }

    return head;
  }

  // Without External Data Structure Approach
  ListNode* oddEvenList_2(ListNode* head) {
    if (head == nullptr || head->next != nullptr) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;

    while (even != nullptr && even->next != nullptr) {
      odd->next = even->next;
      odd = odd->next;

      even->next = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
    return head;
  }
};