#include <iostream>
#include <stack>
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

  // Stack Approach
  bool isPalindriom_1(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* temp = head;
    stack<ListNode*> st;

    while (temp != nullptr) {
      st.push(temp);
      temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
      if (st.top()->data == temp->data) {
        st.pop();
        temp = temp->next;
      } else
        return false;
    }

    if (st.empty())
      return true;
    else
      return false;
  }

  // Tortoise and Hare Approach
  ListNode* reverse(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
      ListNode* front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }

  bool isPalindrom_2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* newHead = reverse(slow);

    ListNode* first = head;
    ListNode* second = newHead;

    while (second != nullptr) {
      if (first->data != second->data) {
        reverse(newHead);
        return false;
      }
      first = first->next;
      second = second->next;
    }

    reverse(newHead);
    return true;
  }
};