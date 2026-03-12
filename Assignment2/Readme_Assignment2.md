# Assignment 2 — BST & AVL (2 Questions)

---
This assignment has **two questions**. Each question is in its own folder and contains:
- `student.c` (you implement the required function)
- `tests.c` (provided tests)
You will use the same GitHub repository workflow we used in lab: update your fork, pull, edit **one C file per question**, run tests with `make`, and submit your GitHub repo link on Canvas.
**You do NOT need to write `main()`**. The tests already include `main()`.

---

## How to run

From the `Assignment2` folder:

### Run Question 1 (BST Search)
```bash
make run1
```

### Run Question 2 (Check AVL)
```bash
make run2
```

### Clean
```bash
make clean
```

---

## Question 1 — Search in a Binary Search Tree (BST)

Implement:
```c
struct TreeNode* bstSearch(struct TreeNode* root, int target);
```

Given the root of a **Binary Search Tree** and an integer `target`, return a pointer to the node whose value equals `target`.
If the node does not exist, return `NULL`.

BST property (strict):
- left subtree values are **< node->val**
- right subtree values are **> node->val**

Requirements:
- Must be **O(h)** where `h` is the tree height.
- Do **not** allocate new nodes.
- Do **not** modify the tree.
- Do **not** print anything.

Example BST:
```
        8
      /   \
     3     10
    / \      \
   1   6      14
      / \     /
     4   7   13
```
- `bstSearch(root, 6)` -> node(6)
- `bstSearch(root, 2)` -> NULL

---

## Question 2 — Check if a BST is an AVL Tree

Implement:
```c
bool isAVL(struct TreeNode* root);
```

Return `true` if the tree is a **valid AVL tree**, otherwise return `false`.

AVL definition (this assignment): the tree must satisfy **both**
1) **Strict BST property** (no duplicates)
2) **Height-balanced** at every node:
```
abs(height(left) - height(right)) <= 1
```
Height definition:
- `height(NULL) = 0`
- `height(leaf) = 1`

Requirements:
- Must be **O(n)**.
- Do **not** allocate new nodes.
- Do **not** modify the tree.
- Do **not** print anything.
- Must correctly handle `INT_MIN` / `INT_MAX` (use `long long` bounds internally).

Examples:
- Valid AVL:
```
    2
   / \
  1   3
```
- BST but NOT AVL (unbalanced):
```
1
 \
  2
   \
    3
```
- Balanced but NOT BST:
```
   2
  / \
 3   1
```
