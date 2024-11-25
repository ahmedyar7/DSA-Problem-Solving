# [344. Reverse String](https://leetcode.com/problems/reverse-string/)

### **Code Explanation:**

```cpp
class Solution {
public:
  void reverseString(vector<char>& s) {
    stack<char> st;  // Declare a stack to store characters
    for (int i = 0; i < s.size(); i++) {  // First loop to push characters onto the stack
      st.push(s[i]);  // Push each character from the vector onto the stack
    }
    for (int i = 0; i < s.size(); i++) {  // Second loop to pop characters from the stack and assign them back to the vector
      s[i] = st.top();  // Take the character from the top of the stack
      st.pop();  // Remove the top element from the stack
    }
  }
};
```

### **Steps and Logic:**

1. **Creating a Stack:**

   - We use a stack (`st`) to temporarily store the characters. A stack follows **Last In, First Out (LIFO)**, meaning the last element that is pushed onto the stack will be the first to be popped out.

2. **Pushing Characters onto the Stack:**

   - We iterate over the input vector `s` (which contains characters) using a `for` loop, and push each character onto the stack.
   - This step will reverse the order of the characters because the last character pushed will be the first one popped in the next step.

3. **Popping Characters and Assigning Back to the Vector:**
   - After pushing all characters onto the stack, we again iterate over the vector `s` using another `for` loop.
   - In this second loop, we pop characters from the stack one by one and assign each popped character back to the vector at the same index.
   - Since the stack is LIFO, the characters are retrieved in reverse order and placed back into the vector `s`, effectively reversing the string.

### **Dry Run Example:**

Let's walk through a dry run of the algorithm using the input `s = ['h', 'e', 'l', 'l', 'o']`.

#### **Input:**

```cpp
s = ['h', 'e', 'l', 'l', 'o']
```

#### **Step 1: Push characters onto the stack**

- We iterate through the vector and push each character into the stack.

| Iteration | `i` | Stack (`st`)                | Action (Push) |
| --------- | --- | --------------------------- | ------------- |
| 1         | 0   | `['h']`                     | Push 'h'      |
| 2         | 1   | `['h', 'e']`                | Push 'e'      |
| 3         | 2   | `['h', 'e', 'l']`           | Push 'l'      |
| 4         | 3   | `['h', 'e', 'l', 'l']`      | Push 'l'      |
| 5         | 4   | `['h', 'e', 'l', 'l', 'o']` | Push 'o'      |

At the end of the first loop, the stack looks like this:

```
['h', 'e', 'l', 'l', 'o']
```

Since the stack follows LIFO (Last In, First Out), the first element that will be popped is `'o'`.

#### **Step 2: Pop characters from the stack and put them back into the vector**

- Now we iterate through the vector `s` and replace each element with the popped character from the stack.

| Iteration | `i` | Stack (`st`)           | Action (Pop and Assign)      | Updated Vector (`s`)        |
| --------- | --- | ---------------------- | ---------------------------- | --------------------------- |
| 1         | 0   | `['h', 'e', 'l', 'l']` | Pop 'o' and assign to `s[0]` | `['o', 'e', 'l', 'l', 'o']` |
| 2         | 1   | `['h', 'e', 'l']`      | Pop 'l' and assign to `s[1]` | `['o', 'l', 'l', 'l', 'o']` |
| 3         | 2   | `['h', 'e']`           | Pop 'l' and assign to `s[2]` | `['o', 'l', 'l', 'l', 'o']` |
| 4         | 3   | `['h']`                | Pop 'e' and assign to `s[3]` | `['o', 'l', 'l', 'e', 'o']` |
| 5         | 4   | `[]`                   | Pop 'h' and assign to `s[4]` | `['o', 'l', 'l', 'e', 'h']` |

After the second loop, the vector `s` is reversed:

#### **Final Output:**

```cpp
s = ['o', 'l', 'l', 'e', 'h']
```

So, the string `['h', 'e', 'l', 'l', 'o']` has been reversed to `['o', 'l', 'l', 'e', 'h']`.

### **Time Complexity:**

- **Pushing characters onto the stack:** This takes \( O(n) \), where \( n \) is the size of the vector `s`.
- **Popping characters from the stack and updating the vector:** This also takes \( O(n) \), since we pop each character once and assign it back to the vector.

Overall, the time complexity is \( O(n) \), where \( n \) is the number of characters in the string (size of the vector `s`).

### **Space Complexity:**

- The space complexity is \( O(n) \) because we are using a stack that stores all the characters of the string.

Thus, the algorithm has **linear time complexity** and **linear space complexity**.
