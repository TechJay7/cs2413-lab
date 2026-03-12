#include <stdio.h>
#include <stdlib.h>

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
 * Student function
 */
int sumNumbers(struct TreeNode* root);

/*
 * Helper: create a new node
 */
static struct TreeNode* create_node(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * Helper: free the tree
 */
static void free_tree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/*
 * Helper: run one test case
 */
static void run_test(const char* name, struct TreeNode* root, int expected) {
    int actual = sumNumbers(root);

    if (actual == expected) {
        printf("[PASS] %s -> expected %d, got %d\n", name, expected, actual);
    } else {
        printf("[FAIL] %s -> expected %d, got %d\n", name, expected, actual);
    }

    free_tree(root);
}

int main(void) {
    /* Test 1: empty tree */
    run_test("empty tree", NULL, 0);

    /* Test 2: single node */
    struct TreeNode* t2 = create_node(5);
    run_test("single node", t2, 5);

    /* Test 3: simple example */
    /*
            1
           / \
          2   3

       Numbers: 12, 13
       Sum = 25
    */
    struct TreeNode* t3 = create_node(1);
    t3->left = create_node(2);
    t3->right = create_node(3);
    run_test("two root-to-leaf paths", t3, 25);

    /* Test 4: deeper tree */
    /*
            4
           / \
          9   0
         / \
        5   1

       Numbers: 495, 491, 40
       Sum = 1026
    */
    struct TreeNode* t4 = create_node(4);
    t4->left = create_node(9);
    t4->right = create_node(0);
    t4->left->left = create_node(5);
    t4->left->right = create_node(1);
    run_test("classic example", t4, 1026);

    /* Test 5: left skewed tree */
    /*
            1
           /
          2
         /
        3

       Number: 123
    */
    struct TreeNode* t5 = create_node(1);
    t5->left = create_node(2);
    t5->left->left = create_node(3);
    run_test("left skewed tree", t5, 123);

    /* Test 6: right skewed tree */
    /*
            7
             \
              8
               \
                9

       Number: 789
    */
    struct TreeNode* t6 = create_node(7);
    t6->right = create_node(8);
    t6->right->right = create_node(9);
    run_test("right skewed tree", t6, 789);

    /* Test 7: multiple paths */
    /*
             2
            / \
           1   3
          /   / \
         4   5   6

       Numbers: 214, 235, 236
       Sum = 685
    */
    struct TreeNode* t7 = create_node(2);
    t7->left = create_node(1);
    t7->right = create_node(3);
    t7->left->left = create_node(4);
    t7->right->left = create_node(5);
    t7->right->right = create_node(6);
    run_test("multiple leaf paths", t7, 685);

    return 0;
}