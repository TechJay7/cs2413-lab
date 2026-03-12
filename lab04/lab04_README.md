# Lab Practice 04

This lab contains three binary-tree practice questions in C.

## Folder Structure

- `question1/`
- `question2/`
- `question3/`
- `Makefile`

Each question folder contains:

- `student.c` — your implementation file
- `tests.c` — the test program

---

## How to Run

Run Question 1 only:

```bash
make run1
```

Run Question 2 only:

```bash
make run2
```

Run Question 3 only:

```bash
make run3
```

Remove compiled files:

```bash
make clean
```

---

# Question 1: Maximum Depth of Binary Tree

## Description

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Function

```c
int maxDepth(struct TreeNode* root);
```

## Notes

- If the tree is empty, return `0`.
- A tree with only one node has depth `1`.

## Example 1

Input:

```text
    1
   / \
  2   3
```

Output:

```text
2
```

## Example 2

Input:

```text
    1
   /
  2
 /
3
```

Output:

```text
3
```

## Example 3

Input:

```text
empty tree
```

Output:

```text
0
```

---

# Question 2: Symmetric Tree

## Description

Given the root of a binary tree, determine whether it is symmetric around its center.

A tree is symmetric if the left subtree is a mirror reflection of the right subtree.

## Function

```c
bool isSymmetric(struct TreeNode* root);
```

## Notes

- An empty tree is considered symmetric.
- Compare the left subtree and right subtree as mirror images.

## Example 1

Input:

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

Output:

```text
true
```

## Example 2

Input:

```text
        1
       / \
      2   2
       \   \
        3    3
```

Output:

```text
false
```

## Example 3

Input:

```text
    1
```

Output:

```text
true
```

---

# Question 3: Sum Root to Leaf Numbers

## Description

You are given the root of a binary tree containing digits from `0` to `9` only.

Each root-to-leaf path represents a number. For example, the path `1 -> 2 -> 3` represents the number `123`.

Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

## Function

```c
int sumNumbers(struct TreeNode* root);
```

## Notes

- Each node stores a digit from `0` to `9`.
- If the tree is empty, return `0`.
- Build the current number as you move from root to leaf.

## Example 1

Input:

```text
    1
   / \
  2   3
```

Output:

```text
25
```

Explanation:

- `1 -> 2` represents `12`
- `1 -> 3` represents `13`
- `12 + 13 = 25`

## Example 2

Input:

```text
      4
     / \
    9   0
   / \
  5   1
```

Output:

```text
1026
```

Explanation:

- `4 -> 9 -> 5` represents `495`
- `4 -> 9 -> 1` represents `491`
- `4 -> 0` represents `40`
- `495 + 491 + 40 = 1026`

---

## Expected Output Style

The test files print whether each test case passes or fails:

```text
[PASS] test name -> expected X, got X
[FAIL] test name -> expected X, got Y
```

This helps you see which test cases are correct and which ones still need work.

---

## Suggested Workflow

1. Open `student.c` for one question.
2. Write your solution.
3. Run the corresponding command:
   - `make run1`
   - `make run2`
   - `make run3`
4. Check the output and fix any failed test cases.

---

## Reminder

Read the comments in each `student.c` file carefully before writing your solution.
