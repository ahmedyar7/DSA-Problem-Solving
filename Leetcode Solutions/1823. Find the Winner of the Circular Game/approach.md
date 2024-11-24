# [1823. Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

The given problem is a variation of the **Josephus problem**, a classic algorithmic problem. Let’s break down the code, the logic, and how it works step by step with a **dry run**.

---

## **Explanation of the Code**

The recursive function solves the problem by breaking it into smaller subproblems:

- It calculates the winner for a circle of \( n-1 \) friends and then adjusts for the current circle of size \( n \) by accounting for the position offset caused by the elimination of the \( k^{th} \) person.

### **Recursive Function**

```cpp
int findTheWinner(int n, int k) {
    if (n == 1)
        return 1;  // Base case: Only one person is left, so they are the winner.
    return (findTheWinner(n - 1, k) + (k - 1)) % n + 1; // Recursive step
}
```

1. **Base Case (`n == 1`)**:

   - If there’s only one person left, they are the winner, so return 1.

2. **Recursive Case**:

   - The function `findTheWinner(n - 1, k)` calculates the winner for the smaller circle of \( n-1 \) people.
   - After this, the formula:
     ```cpp
     (findTheWinner(n - 1, k) + (k - 1)) % n + 1
     ```
     adjusts the winner's position to account for the elimination of the \( k^{th} \) person.

3. **Formula Details**:
   - **`findTheWinner(n - 1, k)`**: Winner of the smaller circle.
   - **`(k - 1)`**: Accounts for the offset due to \( k^{th} \) person being eliminated.
   - **`% n`**: Ensures the result wraps around the circle when it exceeds \( n \).
   - **`+ 1`**: Converts zero-based indexing (from modular arithmetic) back to one-based indexing.

---

## **Dry Run**

### Example 1: \( n = 5, k = 2 \)

Friends: **1, 2, 3, 4, 5**

**Steps**:

1. **Step 1**: \( n = 1 \)

   - Base case reached: `findTheWinner(1, 2) = 1`.

2. **Step 2**: \( n = 2 \)

   - Recursive call: `findTheWinner(2, 2) = (findTheWinner(1, 2) + (2 - 1)) % 2 + 1`.
   - Substitution: `findTheWinner(2, 2) = (1 + 1) % 2 + 1 = 2`.

3. **Step 3**: \( n = 3 \)

   - Recursive call: `findTheWinner(3, 2) = (findTheWinner(2, 2) + (2 - 1)) % 3 + 1`.
   - Substitution: `findTheWinner(3, 2) = (2 + 1) % 3 + 1 = 3`.

4. **Step 4**: \( n = 4 \)

   - Recursive call: `findTheWinner(4, 2) = (findTheWinner(3, 2) + (2 - 1)) % 4 + 1`.
   - Substitution: `findTheWinner(4, 2) = (3 + 1) % 4 + 1 = 1`.

5. **Step 5**: \( n = 5 \)
   - Recursive call: `findTheWinner(5, 2) = (findTheWinner(4, 2) + (2 - 1)) % 5 + 1`.
   - Substitution: `findTheWinner(5, 2) = (1 + 1) % 5 + 1 = 3`.

**Result**: The winner is **3**.

---

### Example 2: \( n = 6, k = 5 \)

Friends: **1, 2, 3, 4, 5, 6**

**Steps**:

1. **Step 1**: \( n = 1 \)

   - Base case reached: `findTheWinner(1, 5) = 1`.

2. **Step 2**: \( n = 2 \)

   - Recursive call: `findTheWinner(2, 5) = (findTheWinner(1, 5) + (5 - 1)) % 2 + 1`.
   - Substitution: `findTheWinner(2, 5) = (1 + 4) % 2 + 1 = 1`.

3. **Step 3**: \( n = 3 \)

   - Recursive call: `findTheWinner(3, 5) = (findTheWinner(2, 5) + (5 - 1)) % 3 + 1`.
   - Substitution: `findTheWinner(3, 5) = (1 + 4) % 3 + 1 = 2`.

4. **Step 4**: \( n = 4 \)

   - Recursive call: `findTheWinner(4, 5) = (findTheWinner(3, 5) + (5 - 1)) % 4 + 1`.
   - Substitution: `findTheWinner(4, 5) = (2 + 4) % 4 + 1 = 2`.

5. **Step 5**: \( n = 5 \)

   - Recursive call: `findTheWinner(5, 5) = (findTheWinner(4, 5) + (5 - 1)) % 5 + 1`.
   - Substitution: `findTheWinner(5, 5) = (2 + 4) % 5 + 1 = 1`.

6. **Step 6**: \( n = 6 \)
   - Recursive call: `findTheWinner(6, 5) = (findTheWinner(5, 5) + (5 - 1)) % 6 + 1`.
   - Substitution: `findTheWinner(6, 5) = (1 + 4) % 6 + 1 = 1`.

**Result**: The winner is **1**.

---

## **Complexity Analysis**

1. **Time Complexity**:

   - Each recursive call reduces \( n \) by 1, resulting in \( O(n) \) recursive calls.
   - Time complexity: **O(n)**.

2. **Space Complexity**:
   - The recursion stack requires \( O(n) \) space in the worst case.
   - Space complexity: **O(n)**.

---

### **Summary**

This recursive approach solves the Josephus problem efficiently for small \( n \), and the formula \( (findTheWinner(n-1, k) + (k-1)) \% n + 1 \) ensures correct positioning in the circle after every elimination.
