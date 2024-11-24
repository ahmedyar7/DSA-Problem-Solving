# [1472. Design Browser History](https://leetcode.com/problems/design-browser-history/description/)

This `BrowserHistory` class simulates a browser's history mechanism with functionalities to visit new URLs, go back a certain number of steps, and go forward a certain number of steps. It uses a **doubly linked list** to efficiently handle these operations. Let's break down the implementation step by step.

---

### **Code Explanation**

#### **1. Node Structure**

```cpp
struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
};
```

- Each `Node` represents a webpage in the browser's history.
- **Attributes**:
  - `url`: Stores the webpage URL.
  - `prev`: Pointer to the previous node (previous page in history).
  - `next`: Pointer to the next node (forward page in history).
- The constructor initializes a node with a URL, setting `prev` and `next` to `nullptr`.

---

#### **2. BrowserHistory Constructor**

```cpp
BrowserHistory(string homepage) {
    current = new Node(homepage);
}
```

- Initializes the browser history with a given homepage.
- A new `Node` is created for the homepage, and the `current` pointer is set to this node.

---

#### **3. Visit Method**

```cpp
void visit(string url) {
    Node* newNode = new Node(url);
    // Remove all forward history
    current->next = nullptr;
    newNode->prev = current;
    current->next = newNode;
    current = newNode;
}
```

- **Creates a new node** for the URL being visited.
- **Removes all forward history** by setting `current->next` to `nullptr`. This mimics how forward pages are erased in an actual browser when you visit a new page.
- Links the new node to the current node:
  - `newNode->prev` is set to the current node.
  - `current->next` is set to the new node.
- Updates `current` to point to the new node, marking the visited page as the current page.

---

#### **4. Back Method**

```cpp
string back(int steps) {
    while (steps > 0 && current->prev != nullptr) {
        current = current->prev;
        steps--;
    }
    return current->url;
}
```

- Moves the `current` pointer backward by `steps`:
  - As long as `steps > 0` and there is a `prev` node, the pointer moves to the previous node (`current = current->prev`).
  - Decrements `steps` at each move.
- Returns the URL of the page where the pointer stops.

---

#### **5. Forward Method**

```cpp
string forward(int steps) {
    while (steps > 0 && current->next != nullptr) {
        current = current->next;
        steps--;
    }
    return current->url;
}
```

- Moves the `current` pointer forward by `steps`:
  - As long as `steps > 0` and there is a `next` node, the pointer moves to the next node (`current = current->next`).
  - Decrements `steps` at each move.
- Returns the URL of the page where the pointer stops.

---

### **Example Usage**

#### **Initialization**

```cpp
BrowserHistory* obj = new BrowserHistory("leetcode.com");
```

- Creates the browser history with `leetcode.com` as the homepage.
- The doubly linked list is initialized with one node containing `"leetcode.com"`.

#### **Visit a New Page**

```cpp
obj->visit("google.com");
```

- A new node for `"google.com"` is added:
  - `leetcode.com` (prev: nullptr, next: google.com)
  - `google.com` (prev: leetcode.com, next: nullptr)
- The `current` pointer now points to the node for `"google.com"`.

#### **Go Back**

```cpp
string param_2 = obj->back(1);
```

- Moves back 1 step from `"google.com"` to `"leetcode.com"`.
- Returns `"leetcode.com"`.

#### **Go Forward**

```cpp
string param_3 = obj->forward(1);
```

- Moves forward 1 step from `"leetcode.com"` to `"google.com"`.
- Returns `"google.com"`.

---

### **Dry Run**

#### Example Input

```cpp
BrowserHistory* obj = new BrowserHistory("leetcode.com");
obj->visit("google.com");
obj->visit("youtube.com");
obj->back(1);   // Returns "google.com"
obj->back(1);   // Returns "leetcode.com"
obj->forward(1); // Returns "google.com"
obj->visit("facebook.com");
obj->forward(1); // Returns "facebook.com"
obj->back(2);   // Returns "leetcode.com"
obj->back(7);   // Returns "leetcode.com"
```

#### Steps:

1. **Initialization**:

   - Current: `"leetcode.com"`.

2. **Visit `"google.com"`**:

   - `"leetcode.com"` → `"google.com"` (current: `"google.com"`).

3. **Visit `"youtube.com"`**:

   - `"google.com"` → `"youtube.com"` (current: `"youtube.com"`).

4. **Back 1 Step**:

   - Moves from `"youtube.com"` → `"google.com"` (current: `"google.com"`).
   - Returns `"google.com"`.

5. **Back 1 Step**:

   - Moves from `"google.com"` → `"leetcode.com"` (current: `"leetcode.com"`).
   - Returns `"leetcode.com"`.

6. **Forward 1 Step**:

   - Moves from `"leetcode.com"` → `"google.com"` (current: `"google.com"`).
   - Returns `"google.com"`.

7. **Visit `"facebook.com"`**:

   - `"google.com"` → `"facebook.com"` (forward history erased).
   - Current: `"facebook.com"`.

8. **Forward 1 Step**:

   - No forward history from `"facebook.com"`.
   - Returns `"facebook.com"`.

9. **Back 2 Steps**:

   - Moves from `"facebook.com"` → `"google.com"` → `"leetcode.com"`.
   - Current: `"leetcode.com"`.
   - Returns `"leetcode.com"`.

10. **Back 7 Steps**:
    - Already at `"leetcode.com"` (no further back).
    - Returns `"leetcode.com"`.

---
