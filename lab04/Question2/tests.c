#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool isSymmetric(struct TreeNode* root);

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
 * Helper: print bool as text
 */
static const char* bool_str(bool value) {
    return value ? "true" : "false";
}

/*
 * Helper: run one test case
 */
static void run_test(const char* name, struct TreeNode* root, bool expected) {
    bool actual = isSymmetric(root);

    if (actual == expected) {
        printf("[PASS] %s -> expected %s, got %s\n",
               name, bool_str(expected), bool_str(actual));
    } else {
        printf("[FAIL] %s -> expected %s, got %s\n",
               name, bool_str(expected), bool_str(actual));
    }

    free_tree(root);
}

int main(void) {
    /* Test 1: empty tree */
    run_test("empty tree", NULL, true);

    /* Test 2: single node */
    struct TreeNode* t2 = create_node(1);
    run_test("single node", t2, true);

    /* Test 3: symmetric tree */
    /*
             1
            / \
           2   2
          / \ / \
         3  4 4  3
    */
    struct TreeNode* t3 = create_node(1);
    t3->left = create_node(2);
    t3->right = create_node(2);
    t3->left->left = create_node(3);
    t3->left->right = create_node(4);
    t3->right->left = create_node(4);
    t3->right->right = create_node(3);
    run_test("perfect symmetric tree", t3, true);

    /* Test 4: asymmetric structure */
    /*
             1
            / \
           2   2
            \   \
             3   3
    */
    struct TreeNode* t4 = create_node(1);
    t4->left = create_node(2);
    t4->right = create_node(2);
    t4->left->right = create_node(3);
    t4->right->right = create_node(3);
    run_test("asymmetric structure", t4, false);

    /* Test 5: asymmetric values */
    /*
             1
            / \
           2   2
          /     \
         3       4
    */
    struct TreeNode* t5 = create_node(1);
    t5->left = create_node(2);
    t5->right = create_node(2);
    t5->left->left = create_node(3);
    t5->right->right = create_node(4);
    run_test("asymmetric values", t5, false);

    /* Test 6: symmetric but not perfect */
    /*
             1
            / \
           2   2
            \ /
            3 3
    */
    struct TreeNode* t6 = create_node(1);
    t6->left = create_node(2);
    t6->right = create_node(2);
    t6->left->right = create_node(3);
    t6->right->left = create_node(3);
    run_test("symmetric non-perfect tree", t6, true);

    /* Test 7: one side missing */
    /*
             1
            /
           2
    */
    struct TreeNode* t7 = create_node(1);
    t7->left = create_node(2);
    run_test("one side missing", t7, false);

    return 0;
}