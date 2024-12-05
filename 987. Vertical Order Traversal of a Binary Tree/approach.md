# [987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)

### Intuition:

The basic idea behind the solution is that each node in a binary tree can be thought of as having two coordinates:

- **Horizontal Distance (HD)**: This determines how far left or right the node is from the root. The root has an HD of 0, its left child has HD - 1, and its right child has HD + 1.
- **Vertical Level**: This determines the depth or level of the node in the tree. The root has a level of 0, and its children have levels of 1, 2, and so on.

### Steps to approach the problem:

1. **BFS Traversal**:
   - We perform a level-order traversal (BFS) on the binary tree. This ensures that we visit the nodes level by level, which is essential for handling nodes that share the same vertical level and are at different depths.
2. **Tracking Horizontal Distance and Level**:

   - As we traverse, each node is associated with a **horizontal distance (HD)** and a **vertical level**.
   - We maintain a queue where each element stores:
     - A pointer to the current node.
     - A pair of coordinates `(horizontal distance, vertical level)`.

3. **Mapping Nodes to Vertical and Level Coordinates**:

   - We use a **map of maps**: `map<int, map<int, vector<int>>> nodes`. This structure helps organize the nodes based on their HD and vertical level:
     - The outer map uses the **horizontal distance (HD)** as the key.
     - The inner map uses the **level** as the key, and stores the node values at that level.

4. **Processing Each Node**:
   - For each node, we:
     - Update its corresponding entry in the `nodes` map using its HD and vertical level.
     - Add the node’s value to the correct position in the map.
5. **Ensuring Vertical Order**:

   - After BFS, we need to collect the nodes in **vertical order**:
     - For each vertical line (given by HD), we go through all the nodes at that HD (which are grouped by their vertical level).
     - Nodes at the same level should be processed in increasing order of their vertical level.
     - Finally, nodes in each level should be sorted to maintain the **lexical order** within a level (ascending).

6. **Returning the Result**:
   - After gathering all the nodes in vertical slices, we return them as the final result.

### Detailed Walkthrough:

1. **Initialize**:
   - Create a queue `q` to store nodes along with their HD and level.
   - Use a map `nodes` to store the node values grouped by HD and level.
2. **BFS**:

   - Start from the root (HD = 0, level = 0), and enqueue it with these coordinates.
   - For each node, process it by adding its left and right children to the queue with updated coordinates:
     - Left child: HD decreases by 1, level increases by 1.
     - Right child: HD increases by 1, level increases by 1.
   - As you process each node, store its value in `nodes[hd][level].push_back(node->val)`.

3. **Sorting**:

   - After BFS completes, iterate over the map:
     - For each horizontal slice (HD), traverse all levels.
     - Sort the node values at each level to maintain the order (in case multiple nodes are at the same level).
     - For each level, add the sorted values to a temporary vector `vertical`.

4. **Construct the Result**:
   - For each vertical slice (HD), gather the values in order and add them to the result vector `ans`.

### Time Complexity:

- **BFS traversal**: The BFS will visit each node exactly once, so this step takes \(O(N)\) time where \(N\) is the number of nodes in the tree.
- **Sorting**: Sorting each level within each vertical line. In the worst case, all nodes might fall on the same vertical line. Sorting the nodes at each level will take \(O(k \log k)\) where \(k\) is the number of nodes at that level. Thus, sorting complexity is dominated by the number of nodes at each level.
  Overall, the time complexity is \(O(N \log N)\), considering the sorting step.

### Space Complexity:

- The space complexity is primarily determined by:
  - The storage for the `nodes` map, which holds the nodes in the tree based on their horizontal distance and level. The map's space usage is \(O(N)\), where \(N\) is the total number of nodes.
  - The queue used for BFS also uses \(O(N)\) space at its maximum, but this is already included in the map's space.

Thus, the space complexity is \(O(N)\).
