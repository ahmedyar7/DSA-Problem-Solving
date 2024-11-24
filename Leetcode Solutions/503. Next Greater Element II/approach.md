# [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/description/)

### Problem:

Given a circular array `nums`, for each element, find the **next greater element** that appears after it. The circular array means that after the last element, we go back to the first element.

### Code Explanation:

#### **Class and Method Declaration**

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
```

- `Solution` is the class where the method `nextGreaterElements` is defined.
- `nextGreaterElements` takes a reference to a vector `nums` as input and returns a vector of integers.

#### **Variables Initialization**

```cpp
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n, -1);
```

1. **`stack<int> st`**: This stack will help keep track of elements in the `nums` array while we try to find the next greater element.
2. **`int n = nums.size()`**: Stores the size of the `nums` array in `n`.
3. **`vector<int> nge(n, -1)`**: A vector `nge` of size `n` is initialized with `-1`. This vector will store the next greater element for each position in `nums`. If no greater element is found, it will remain `-1`.

#### **Main Logic**

```cpp
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }
```

- **Outer Loop**: The loop runs from `2 * n - 1` to `0`, which ensures we look at each element twice. This is necessary because the array is circular, so we need to handle the second round of elements by treating the array as if it wraps around.
  - `i % n` ensures we handle the circular nature by mapping the indices back into the range `[0, n-1]`. This allows the second pass over the array to access the earlier elements in the array.
- **Inner While Loop**:
  - `while (!st.empty() && st.top() <= nums[i % n])`: This loop pops elements from the stack until it finds an element that is strictly greater than the current element (`nums[i % n]`). We are essentially trying to discard elements that cannot be the next greater element for any element in the array.
- **Updating the Next Greater Element**:

  - If the stack is not empty after the inner loop (`if (!st.empty())`), the top of the stack is the next greater element for the current element (`nums[i % n]`), so we update `nge[i % n] = st.top()`.

- **Pushing the Current Element to the Stack**:
  - After processing the current element, it is pushed onto the stack (`st.push(nums[i % n])`) to be used for the next elements.

#### **Return Statement**

```cpp
        return nge;
    }
};
```

- Finally, after processing all elements, the `nge` vector is returned. It contains the next greater element for each index in `nums`.

### **Example Walkthrough**

Let’s consider an example `nums = [1, 2, 1]`.

1. **Initialization**:

   - `st = empty stack`
   - `nge = [-1, -1, -1]`

2. **Iteration 1** (i = 5, i % 3 = 2):
   - `nums[i % n] = nums[2] = 1`
   - The stack is empty, so `1` is pushed onto the stack (`st = [1]`).
3. **Iteration 2** (i = 4, i % 3 = 1):

   - `nums[i % n] = nums[1] = 2`
   - The stack top is `1`, which is less than `2`, so we pop `1` (`st = []`).
   - Now, the stack is empty, so `nge[1]` remains `-1`.
   - Push `2` onto the stack (`st = [2]`).

4. **Iteration 3** (i = 3, i % 3 = 0):

   - `nums[i % n] = nums[0] = 1`
   - The stack top is `2`, which is greater than `1`, so `nge[0] = 2`.
   - Push `1` onto the stack (`st = [2, 1]`).

5. **Iteration 4** (i = 2, i % 3 = 2):

   - `nums[i % n] = nums[2] = 1`
   - The stack top is `1`, which is not greater than `1`, so pop the stack (`st = [2]`).
   - The stack top is `2`, which is greater than `1`, so `nge[2] = 2`.
   - Push `1` onto the stack (`st = [2, 1]`).

6. **Iteration 5** (i = 1, i % 3 = 1):

   - `nums[i % n] = nums[1] = 2`
   - The stack top is `1`, which is less than `2`, so pop `1` (`st = [2]`).
   - The stack top is `2`, which is not greater than `2`, so we don’t update `nge[1]` and continue.

7. **Iteration 6** (i = 0, i % 3 = 0):
   - `nums[i % n] = nums[0] = 1`
   - The stack top is `2`, which is greater than `1`, so `nge[0] = 2`.

After the loop, the `nge` vector contains `[2, -1, 2]`, which is the final result.

### **Time Complexity**

- **Time Complexity**: O(n), where `n` is the size of the input array `nums`. Each element is pushed and popped from the stack at most once, so the total number of operations is linear in terms of the size of the array.
- **Space Complexity**: O(n), due to the use of a stack and an additional `nge` vector of size `n`.

This approach efficiently solves the problem using a stack to keep track of the next greater element for each item while handling the circular nature of the array.
