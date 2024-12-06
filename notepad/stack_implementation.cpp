#include "_Stack.h"
template <class T>
stack<T>::stack(int size) {
  this->size = size;
  Head = nullptr;
}

template <class T>
stack<T>::stack() {
  Head = nullptr;  // Default constructor initializes Head to nullptr
}

template <class T>
void stack<T>::push(T data) {
  Node<T> *new_node = new Node<T>(data);
  new_node->setNext(Head);
  Head = new_node;
}

template <class T>
void stack<T>::pop() {
  if (Head != nullptr) {
    Node<T> *temp = Head;
    Head = temp->getNext();
    temp->setNext(nullptr);
    delete temp;
  } else {
    throw std::runtime_error("Stack is empty. Cannot pop.");
  }
}

template <class T>
T stack<T>::top() {
  if (Head != nullptr) {
    return Head->getData();
  } else {
    throw std::runtime_error("Stack is empty. Cannot get top.");
  }
}

template <class T>
bool stack<T>::empty() {
  return Head == nullptr;
}