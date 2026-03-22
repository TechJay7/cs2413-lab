#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool checker(struct TreeNode* leftNode, struct TreeNode* rightNode)
  {
    if (leftNode == NULL && rightNode == NULL)
      return true;
      
    if (leftNode == NULL || rightNode == NULL)
      return false;
      
    if (leftNode->val != rightNode->val)
      return false;
  
  return checker(leftNode->left, rightNode->right) && checker(leftNode->right, rightNode->left);
  }

bool isSymmetric(struct TreeNode* root) {
  // TODO: implement
  if(root == NULL)
    return true;
  
  

  return checker(root->left, root->right);
 
}