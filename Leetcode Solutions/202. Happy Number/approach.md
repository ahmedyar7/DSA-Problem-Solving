# [202. Happy Number](https://leetcode.com/problems/happy-number/description/)

### Problem Understanding:

A **happy number** is defined as follows:

1. Starting with any positive integer, replace the number by the sum of the squares of its digits.
2. Repeat the process until:
   - The number equals `1` (in which case the number is happy).
   - Or, the number starts repeating (in which case the number is not happy).

### Code Explanation:

#### 1. **Helper Function `sum_of_squares(int n)`**:

This function calculates the sum of the squares of the digits of the number `n`.

- `int digit = n % 10;`: This extracts the last digit of `n`.
- `output += digit * digit;`: It adds the square of the digit to the result.
- `n = n / 10;`: This removes the last digit from `n` by integer division.

#### 2. **Main Function `isHappy(int n)`**:

This function determines whether a number `n` is happy or not.

- A **set** `st` is used to track previously encountered numbers. This helps in detecting cycles (which would imply the number is not happy).
- The loop continues until:
  - If `n == 1`, it returns `true` (the number is happy).
  - If the number `n` has been encountered before (i.e., it's already in the set), a cycle is detected, and it returns `false` (the number is not happy).

### Dry Run Example:

Let's dry run the code with `n = 19` to determine if it is a happy number.

#### **Initialization**:

- `n = 19`
- `st = {}` (empty set)

#### **First Iteration**:

1. **Call `sum_of_squares(19)`**:
   - `n = 19`
   - Extract the digits and square them:
     - Digit 9: `9^2 = 81`
     - Digit 1: `1^2 = 1`
   - Sum of squares: `81 + 1 = 82`
   - Return `82` from `sum_of_squares`.
2. **Update**:
   - Insert `19` into the set: `st = {19}`
   - Now, `n = 82`.

#### **Second Iteration**:

1. **Call `sum_of_squares(82)`**:

   - `n = 82`
   - Extract the digits and square them:
     - Digit 2: `2^2 = 4`
     - Digit 8: `8^2 = 64`
   - Sum of squares: `64 + 4 = 68`
   - Return `68` from `sum_of_squares`.

2. **Update**:
   - Insert `82` into the set: `st = {19, 82}`
   - Now, `n = 68`.

#### **Third Iteration**:

1. **Call `sum_of_squares(68)`**:

   - `n = 68`
   - Extract the digits and square them:
     - Digit 8: `8^2 = 64`
     - Digit 6: `6^2 = 36`
   - Sum of squares: `64 + 36 = 100`
   - Return `100` from `sum_of_squares`.

2. **Update**:
   - Insert `68` into the set: `st = {19, 82, 68}`
   - Now, `n = 100`.

#### **Fourth Iteration**:

1. **Call `sum_of_squares(100)`**:

   - `n = 100`
   - Extract the digits and square them:
     - Digit 0: `0^2 = 0`
     - Digit 0: `0^2 = 0`
     - Digit 1: `1^2 = 1`
   - Sum of squares: `1 + 0 + 0 = 1`
   - Return `1` from `sum_of_squares`.

2. **Update**:
   - Insert `100` into the set: `st = {19, 82, 68, 100}`
   - Now, `n = 1`.

#### **Fifth Iteration**:

- Since `n == 1`, the function returns `true`, indicating that 19 is a happy number.

### Why the Code Works:

- The **set `st`** ensures that if a number repeats (i.e., a cycle forms), it will be detected and the function will return `false`.
- The **`sum_of_squares` function** computes the sum of the squares of the digits in each iteration, and the process continues until either `n == 1` or a cycle is detected.
- If the sum eventually reaches `1`, the function returns `true`, indicating the number is happy. If a cycle is detected (i.e., the number reappears), it returns `false`, indicating the number is not happy.

### Complexity:

- **Time Complexity**: Each call to `sum_of_squares` processes each digit of `n`, and in the worst case, we may go through several iterations before either reaching 1 or detecting a cycle.
- **Space Complexity**: The space complexity is O(k), where k is the number of distinct numbers we encounter before detecting a cycle.
