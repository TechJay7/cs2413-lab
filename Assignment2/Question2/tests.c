\
/*
 * Assignment 2 / Question 2 / tests.c
 * ------------------------------------------------------------
 * Provided tests for isAVL().
 *
 * This test runner prints which test cases PASS/FAIL and continues
 * running after failures (no assert-abort style).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isAVL(struct TreeNode* root);

/* -------------------- Simple test framework -------------------- */

static int g_tests_run = 0;
static int g_tests_failed = 0;

#define CHECK(cond) do { \
    if (!(cond)) { \
        printf("      FAIL: %s (line %d)\n", #cond, __LINE__); \
        return false; \
    } \
} while (0)

#define RUN_TEST(fn) do { \
    g_tests_run++; \
    printf("  [%02d] %-40s", g_tests_run, #fn); \
    bool ok = fn(); \
    if (ok) { \
        printf("PASS\n"); \
    } else { \
        printf("FAIL\n"); \
        g_tests_failed++; \
    } \
} while (0)

/* -------------------- Helpers (tests only) -------------------- */

static struct TreeNode* node_new(int v) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

static void tree_free(struct TreeNode* root) {
    if (!root) return;
    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

static struct TreeNode* bst_insert(struct TreeNode* root, int v) {
    if (!root) return node_new(v);
    if (v < root->val) root->left = bst_insert(root->left, v);
    else if (v > root->val) root->right = bst_insert(root->right, v);
    return root; // ignore duplicates in builder
}

/* ------------------------- Test cases ------------------------- */

static bool test_empty_tree() {
    CHECK(isAVL(NULL) == true);
    return true;
}

static bool test_single_node() {
    struct TreeNode* root = node_new(10);
    CHECK(isAVL(root) == true);
    tree_free(root);
    return true;
}

static bool test_valid_avl_small() {
    //   2
    //  / \
    // 1   3
    struct TreeNode* root = node_new(2);
    root->left = node_new(1);
    root->right = node_new(3);
    CHECK(isAVL(root) == true);
    tree_free(root);
    return true;
}

static bool test_valid_avl_larger_balanced() {
    // Perfectly balanced BST (also AVL):
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1  3  5  7
    struct TreeNode* root = node_new(4);
    root->left = node_new(2);
    root->right = node_new(6);
    root->left->left = node_new(1);
    root->left->right = node_new(3);
    root->right->left = node_new(5);
    root->right->right = node_new(7);
    CHECK(isAVL(root) == true);
    tree_free(root);
    return true;
}

static bool test_bst_but_not_avl_unbalanced_chain() {
    // 1 -> 2 -> 3 -> 4 (all to the right) is BST but not AVL
    struct TreeNode* root = NULL;
    for (int i = 1; i <= 4; i++) root = bst_insert(root, i);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_bst_but_not_avl_lower_imbalance() {
    //        10
    //       /  \
    //      5    20
    //     /
    //    2
    //   /
    //  1
    // BST but not AVL (imbalance at node 5)
    struct TreeNode* root = node_new(10);
    root->left = node_new(5);
    root->right = node_new(20);
    root->left->left = node_new(2);
    root->left->left->left = node_new(1);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_balanced_but_not_bst() {
    //   2
    //  / \
    // 3   1
    struct TreeNode* root = node_new(2);
    root->left = node_new(3);
    root->right = node_new(1);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_bst_violation_deep_right_subtree() {
    //       10
    //      /  \
    //     5    15
    //         /  \
    //        6   20
    // Not BST because 6 is in right subtree of 10 but < 10.
    struct TreeNode* root = node_new(10);
    root->left = node_new(5);
    root->right = node_new(15);
    root->right->left = node_new(6);
    root->right->right = node_new(20);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_bst_violation_deep_left_subtree() {
    //       10
    //      /  \
    //     5    15
    //      \
    //      12   (violates: 12 is in left subtree of 10 but > 10)
    struct TreeNode* root = node_new(10);
    root->left = node_new(5);
    root->right = node_new(15);
    root->left->right = node_new(12);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_duplicate_not_allowed() {
    //  2
    // / \
    //1   2  (duplicate on right)
    struct TreeNode* root = node_new(2);
    root->left = node_new(1);
    root->right = node_new(2);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

static bool test_valid_with_boundaries() {
    //      0
    //     / \
    // INT_MIN INT_MAX
    struct TreeNode* root = node_new(0);
    root->left = node_new(INT_MIN);
    root->right = node_new(INT_MAX);
    CHECK(isAVL(root) == true);
    tree_free(root);
    return true;
}

static bool test_invalid_boundary_in_left_subtree() {
    //       0
    //      / \
    //   INT_MIN  10
    //        \
    //        INT_MAX   (violates BST: INT_MAX in left subtree of 0)
    struct TreeNode* root = node_new(0);
    root->left = node_new(INT_MIN);
    root->right = node_new(10);
    root->left->right = node_new(INT_MAX);
    CHECK(isAVL(root) == false);
    tree_free(root);
    return true;
}

int main(void) {
    printf("Question 2 — AVL Check: running tests...\n");

    RUN_TEST(test_empty_tree);
    RUN_TEST(test_single_node);
    RUN_TEST(test_valid_avl_small);
    RUN_TEST(test_valid_avl_larger_balanced);
    RUN_TEST(test_bst_but_not_avl_unbalanced_chain);
    RUN_TEST(test_bst_but_not_avl_lower_imbalance);
    RUN_TEST(test_balanced_but_not_bst);
    RUN_TEST(test_bst_violation_deep_right_subtree);
    RUN_TEST(test_bst_violation_deep_left_subtree);
    RUN_TEST(test_duplicate_not_allowed);
    RUN_TEST(test_valid_with_boundaries);
    RUN_TEST(test_invalid_boundary_in_left_subtree);

    printf("\nSummary: %d run, %d failed\n", g_tests_run, g_tests_failed);
    if (g_tests_failed == 0) {
        printf("Question 2: All tests passed.\n");
        return 0;
    } else {
        printf("Question 2: Some tests failed.\n");
        return 1;
    }
}
