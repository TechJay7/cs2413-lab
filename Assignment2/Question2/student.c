/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
   
//helper
int helper(struct TreeNode* node, int* prev, bool* first)
{
    if (node == NULL)
        return 0;

    int lHeight = helper(node->left, prev, first);

    if (lHeight == -1)
        return -1;

    if(!(*first) && node -> val <= *prev) //its a duplicate
        return -1;
        
    *first = false;
    *prev = node-> val;

    
    int rHeight = helper(node->right, prev, first);
    if (rHeight == -1)
        return -1;
//height-balanced: abs(height(left) - height(right)) <= 1 at every node
    int diff = abs(lHeight - rHeight);

    if (diff > 1)
        return -1;

    if (lHeight > rHeight) //off by 1
        return ++lHeight; 
    else
        return ++rHeight;
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    int prev = 0;
    bool first = true;
    return helper(root, &prev, &first) != -1;

   
}