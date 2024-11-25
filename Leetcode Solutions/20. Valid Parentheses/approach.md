# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

### Problem Explanation:

The task is to determine if a string containing parentheses (`()`, `{}`, `[]`) is valid. A valid string meets the following conditions:

1. Every opening parenthesis (`(`, `{`, `[`) has a corresponding and correctly ordered closing parenthesis (`)`, `}`, `]`).
2. The parentheses are nested correctly.

### Approach:

We use a **stack** data structure to keep track of opening parentheses. The algorithm processes the string character by character:

1. **Push Opening Parentheses**: If the current character is an opening parenthesis (`(`, `{`, `[`), push it onto the stack.
2. **Validate and Pop for Closing Parentheses**: If the current character is a closing parenthesis (`)`, `}`, `]`):
   - Check if the stack is empty (indicating no corresponding opening parenthesis). If empty, the string is invalid.
   - Otherwise, check if the top of the stack contains the matching opening parenthesis. If so, pop it from the stack; otherwise, the string is invalid.
3. **Final Check**: After processing the entire string, the stack must be empty for the string to be valid.

### Dry Run Example:

#### Input:

`s = "({[]})"`

#### Steps:

1. Initialize an empty stack: `st = []`.

2. **Process Each Character**:

   - **Character 1: `(`**

     - It’s an opening parenthesis. Push it onto the stack.
     - `st = ['(']`

   - **Character 2: `{`**

     - It’s an opening parenthesis. Push it onto the stack.
     - `st = ['(', '{']`

   - **Character 3: `[`**

     - It’s an opening parenthesis. Push it onto the stack.
     - `st = ['(', '{', '[']`

   - **Character 4: `]`**

     - It’s a closing parenthesis. Check the top of the stack:
       - Top of the stack: `[`. It matches the current character `]`.
       - Pop the stack.
     - `st = ['(', '{']`

   - **Character 5: `}`**

     - It’s a closing parenthesis. Check the top of the stack:
       - Top of the stack: `{`. It matches the current character `}`.
       - Pop the stack.
     - `st = ['(']`

   - **Character 6: `)`**
     - It’s a closing parenthesis. Check the top of the stack:
       - Top of the stack: `(`. It matches the current character `)`.
       - Pop the stack.
     - `st = []`

3. **Final Check**:
   - After processing all characters, the stack is empty, meaning all parentheses were matched correctly.

#### Output:

`true` (The string is valid).

---

#### Example 2:

Input: `s = "(]"`

Steps:

1. Initialize `st = []`.
2. **Character 1: `(`**
   - Push onto the stack: `st = ['(']`.
3. **Character 2: `]`**
   - It’s a closing parenthesis. Check the top of the stack:
     - Top of the stack: `(`. It does not match `]`.
   - Return `false`.

---

### Key Points:

- If the stack is not empty at the end, it means there are unmatched opening parentheses.
- If a closing parenthesis does not match the top of the stack, the string is invalid.

### Time and Space Complexity:

- **Time Complexity**: O(N), where N is the length of the string. We traverse the string once.
- **Space Complexity**: O(N) in the worst case, where all characters are opening parentheses (stack stores all of them).
