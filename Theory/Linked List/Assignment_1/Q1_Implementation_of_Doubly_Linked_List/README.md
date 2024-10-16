# 💫 Doubly Linked List Implementation

This project implements a **doubly linked list** in C++, with a `Node` class and a `DoublyLinkedList` class. The `Node` class defines the structure of each node, while the `DoublyLinkedList` class manages the operations on the list. The project includes common linked list operations like **insertion**, **deletion**, **searching**, **reversing**, and **merging**, all of which are implemented in a modular fashion.

## 📂 Project Structure

The project is divided into the following files:

- **📄 node.h**: Defines the `Node` class, representing a single node in the linked list.
- **📄 DoublyLinkedList.h**: Declares the `DoublyLinkedList` class and all its methods.
- **📄 DoublyLinkedList.cpp**: Implements the methods declared in `DoublyLinkedList.h`.
- **📄 main.cpp**: The main file where the doubly linked list is manipulated interactively by calling the various methods.

### 🧩 Node Class (`node.h`)

The `Node` class encapsulates the structure of a node in the linked list. It contains:

- **📝 Data Members**:

  - `int data`: Stores the value of the node.
  - `Node* next`: Pointer to the next node.
  - `Node* prev`: Pointer to the previous node.

- **🔧 Member Functions**:
  - `Node(int data)`: Constructor to initialize the node with a value.
  - `void set_next(Node* address)`: Sets the next pointer of the node.
  - `void set_prev(Node* address)`: Sets the previous pointer of the node.
  - `Node* get_next()`: Returns the next node pointer.
  - `Node* get_prev()`: Returns the previous node pointer.
  - `int get_data()`: Returns the data of the node.

### 🏗️ DoublyLinkedList Class (`DoublyLinkedList.h` and `DoublyLinkedList.cpp`)

The `DoublyLinkedList` class contains methods to manage the linked list:

- **⚙️ Methods**:
  - `🖥️ void display_H_T(Node* head)`: Displays the list from head to tail.
  - `➕ void insert_at_head(Node*& head, int value)`: Inserts a new node at the head.
  - `➕ void insert_at_tail(Node*& head, int value)`: Inserts a new node at the tail.
  - `📍 void insert_at_location(Node*& head, int position, int value)`: Inserts a new node at a specific position.
  - `🗑️ int delete_at_position(Node*& head, int position)`: Deletes a node at a specific position and returns its value.
  - `🔍 bool search_node(Node* head, int search_value)`: Searches for a node with a specific value.
  - `🔄 Node* reverse_dll(Node* head)`: Reverses the linked list.
  - `🔗 Node* merge(Node*& head1, Node*& head2)`: Merges two doubly linked lists.

### 🎮 Main Function (`main.cpp`)

The main function provides an interactive interface to manipulate the doubly linked list. It offers options to:

1. ➕ Insert nodes at the head, tail, or at a specific position.
2. 🗑️ Delete nodes from the list at a specific position.
3. 🔍 Search for a value in the list.
4. 📜 Display the list from head to tail.
5. 🔄 Reverse the entire list.
6. 🔗 Merge two linked lists.

This allows users to test and visualize the behavior of the linked list dynamically.

### 🛠️ Compilation and Execution

To compile and run the program, follow these steps:

1. 📁 Make sure all `.h` and `.cpp` files are in the same directory.
2. 🖥️ Open a terminal and navigate to the project directory.
3. 🏗️ Compile the program using:

   ```bash
   g++ main.cpp DoublyLinkedList.cpp -o output

   ```

4. Run the Execuatable file

   ```
   ./output.ext
   ```
