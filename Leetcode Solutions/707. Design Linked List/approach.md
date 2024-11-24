# [707. Design Linked List](https://leetcode.com/problems/design-linked-list/)

The provided `MyLinkedList` class implements a singly linked list with the following functionalities: getting an element by index, adding elements at the head, tail, or a specific index, and deleting an element at a given index. The class uses a `Node` class to represent each element in the list. Here is a detailed explanation of each part of the code:

### **`Node` Class**

The `Node` class is the building block for the linked list. It contains:

- **`data`**: Stores the value of the node.
- **`next`**: A pointer to the next node in the list (initialized to `nullptr` by default).

The constructor initializes the `data` with the given value and sets `next` to `nullptr`.

### **`MyLinkedList` Class**

The `MyLinkedList` class represents a singly linked list. It has a `head` pointer that points to the first node in the list (initialized to `nullptr`, meaning the list is initially empty).

### **Methods in `MyLinkedList`**

#### **1. `get(int index)`**

```cpp
int get(int index) {
    Node* temp = head;
    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return -1; // return -1 if index is out of bounds
    return temp->data;
}
```

- **Purpose**: Retrieves the element at the specified `index` in the list.
- **Steps**:
  1. Traverse the list starting from the head.
  2. Move `temp` to the next node until reaching the specified `index` or until the end of the list (`temp == nullptr`).
  3. If `temp` becomes `nullptr`, return `-1`, indicating the index is out of bounds.
  4. Otherwise, return the `data` of the node at the given index.

#### **2. `addAtHead(int val)`**

```cpp
void addAtHead(int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
```

- **Purpose**: Adds a new node with the given value `val` at the beginning (head) of the list.
- **Steps**:
  1. Create a new node with the value `val`.
  2. Set the `next` pointer of the new node to the current head (`new_node->next = head`).
  3. Update the `head` to point to the new node (`head = new_node`).

#### **3. `addAtTail(int val)`**

```cpp
void addAtTail(int val) {
    Node* new_node = new Node(val);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = new_node;
}
```

- **Purpose**: Adds a new node with the given value `val` at the end (tail) of the list.
- **Steps**:
  1. Create a new node with the value `val`.
  2. If the list is empty (`head == nullptr`), set the `head` to the new node.
  3. Otherwise, traverse to the last node of the list (where `temp->next == nullptr`).
  4. Set the `next` pointer of the last node to the new node (`temp->next = new_node`).

#### **4. `addAtIndex(int index, int val)`**

```cpp
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

    if (temp == nullptr) return; // index is out of bounds

    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;
}
```

- **Purpose**: Adds a new node with the given value `val` at the specified `index`.
- **Steps**:
  1. If the index is less than 0, return without doing anything.
  2. If the index is 0, call `addAtHead(val)` to insert the node at the head.
  3. Otherwise, traverse to the node at `index - 1` (the node before the desired index).
  4. If `temp` becomes `nullptr`, return, indicating that the index is out of bounds.
  5. Create a new node with the value `val` and insert it after `temp`. Update `temp->next` to point to the new node.

#### **5. `deleteAtIndex(int index)`**

```cpp
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

    if (temp->next == nullptr) return; // index is out of bounds

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
}
```

- **Purpose**: Deletes the node at the specified `index`.
- **Steps**:
  1. If the index is less than 0 or the list is empty (`head == nullptr`), return without doing anything.
  2. If the `index` is 0 (delete the head), update the `head` to point to the next node (`head = head->next`) and delete the old head.
  3. Otherwise, traverse to the node at `index - 1`.
  4. If `temp->next` is `nullptr`, return, indicating that the index is out of bounds.
  5. Set `node_to_delete` to the node after `temp` and update `temp->next` to skip over `node_to_delete` (i.e., `temp->next = node_to_delete->next`).
  6. Delete the node `node_to_delete`.

---

### **Summary of Operations**

1. **Get Element**: Returns the element at the given index or `-1` if the index is out of bounds.
2. **Add at Head**: Inserts a new node at the start of the list.
3. **Add at Tail**: Inserts a new node at the end of the list.
4. **Add at Index**: Inserts a new node at a specified index.
5. **Delete at Index**: Deletes a node at the specified index.

### **Edge Cases**

- **Out of bounds index**: If an invalid index is provided (negative or too large), the operation is ignored (for insertion) or returns an error (for `get()` and `deleteAtIndex()`).
- **Empty list**: Insertion at head or tail works even when the list is empty. Deletion and retrieval operations handle the empty list gracefully by checking `head == nullptr`.

### **Time Complexity**

- **`get(index)`**: O(n), where `n` is the index, since we need to traverse the list to reach the desired index.
- **`addAtHead(val)`**: O(1), constant time operation.
- **`addAtTail(val)`**: O(n), since we need to traverse the list to find the last node.
- **`addAtIndex(index, val)`**: O(n), since we may need to traverse up to `index` to insert the node.
- **`deleteAtIndex(index)`**: O(n), since we need to traverse the list to find the node to delete.

This class provides basic linked list operations with efficient insertions and deletions at the head and tail but can become inefficient for operations involving traversal (like insertion or deletion at a specific index).
