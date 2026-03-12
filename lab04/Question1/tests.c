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
int maxDepth(struct TreeNode* root);

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
 * Helper: free all nodes in the tree
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
static void run_test(const char *name, struct TreeNode *root, int expected) {
    int actual = maxDepth(root);

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
    struct TreeNode *t2 = create_node(1);
    run_test("single node", t2, 1);

    /* Test 3: root with two children */
    struct TreeNode *t3 = create_node(1);
    t3->left = create_node(2);
    t3->right = create_node(3);
    run_test("root with two children", t3, 2);

    /* Test 4: left skewed tree */
    struct TreeNode *t4 = create_node(1);
    t4->left = create_node(2);
    t4->left->left = create_node(3);
    t4->left->left->left = create_node(4);
    run_test("left skewed tree", t4, 4);

    /* Test 5: right skewed tree */
    struct TreeNode *t5 = create_node(1);
    t5->right = create_node(2);
    t5->right->right = create_node(3);
    t5->right->right->right = create_node(4);
    run_test("right skewed tree", t5, 4);

    /* Test 6: balanced tree */
    struct TreeNode *t6 = create_node(1);
    t6->left = create_node(2);
    t6->right = create_node(3);
    t6->left->left = create_node(4);
    t6->left->right = create_node(5);
    t6->right->left = create_node(6);
    t6->right->right = create_node(7);
    run_test("balanced tree", t6, 3);

    /* Test 7: unbalanced tree */
    struct TreeNode *t7 = create_node(1);
    t7->left = create_node(2);
    t7->right = create_node(3);
    t7->left->left = create_node(4);
    t7->left->left->left = create_node(5);
    run_test("unbalanced tree", t7, 4);

    return 0;
}