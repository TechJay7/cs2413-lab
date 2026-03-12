\
/*
 * Assignment 2 / Question 1 / tests.c
 * ------------------------------------------------------------
 * Provided tests for bstSearch().
 *
 * This test runner prints which test cases PASS/FAIL and continues
 * running after failures (no assert-abort style).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target);

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

static struct TreeNode* bst_insert(struct TreeNode* root, int v) {
    if (!root) return node_new(v);
    if (v < root->val) root->left = bst_insert(root->left, v);
    else if (v > root->val) root->right = bst_insert(root->right, v);
    return root; // ignore duplicates for tests
}

static void bst_free(struct TreeNode* root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

/* ------------------------- Test cases ------------------------- */

static bool test_empty_tree() {
    CHECK(bstSearch(NULL, 123) == NULL);
    return true;
}

static bool test_single_node_hit_and_miss() {
    struct TreeNode* root = node_new(5);

    struct TreeNode* p = bstSearch(root, 5);
    CHECK(p != NULL);
    CHECK(p->val == 5);

    CHECK(bstSearch(root, -1) == NULL);
    CHECK(bstSearch(root, 999) == NULL);

    bst_free(root);
    return true;
}

static bool test_root_match_in_larger_tree() {
    int vals[] = {8,3,10,1,6,14,4,7,13};
    struct TreeNode* root = NULL;
    for (size_t i = 0; i < sizeof(vals)/sizeof(vals[0]); i++) root = bst_insert(root, vals[i]);

    struct TreeNode* p = bstSearch(root, 8);
    CHECK(p != NULL);
    CHECK(p->val == 8);

    bst_free(root);
    return true;
}

static bool test_example_tree_hits_and_misses() {
    int vals[] = {8,3,10,1,6,14,4,7,13};
    struct TreeNode* root = NULL;
    for (size_t i = 0; i < sizeof(vals)/sizeof(vals[0]); i++) root = bst_insert(root, vals[i]);

    struct TreeNode* p = bstSearch(root, 6);
    CHECK(p != NULL);
    CHECK(p->val == 6);

    p = bstSearch(root, 13);
    CHECK(p != NULL);
    CHECK(p->val == 13);

    CHECK(bstSearch(root, 2) == NULL);
    CHECK(bstSearch(root, 100) == NULL);

    bst_free(root);
    return true;
}

static bool test_degenerate_increasing_chain() {
    // increasing insert => all right children
    struct TreeNode* root = NULL;
    for (int i = 1; i <= 10; i++) root = bst_insert(root, i);

    for (int i = 1; i <= 10; i++) {
        struct TreeNode* p = bstSearch(root, i);
        CHECK(p != NULL);
        CHECK(p->val == i);
    }
    CHECK(bstSearch(root, 0) == NULL);
    CHECK(bstSearch(root, 11) == NULL);

    bst_free(root);
    return true;
}

static bool test_degenerate_decreasing_chain() {
    // decreasing insert => all left children
    struct TreeNode* root = NULL;
    for (int i = 10; i >= 1; i--) root = bst_insert(root, i);

    for (int i = 1; i <= 10; i++) {
        struct TreeNode* p = bstSearch(root, i);
        CHECK(p != NULL);
        CHECK(p->val == i);
    }
    CHECK(bstSearch(root, -999) == NULL);

    bst_free(root);
    return true;
}

static bool test_with_negative_values() {
    int vals[] = {0, -10, 10, -20, -5, 5, 20};
    struct TreeNode* root = NULL;
    for (size_t i = 0; i < sizeof(vals)/sizeof(vals[0]); i++) root = bst_insert(root, vals[i]);

    struct TreeNode* p = bstSearch(root, -20);
    CHECK(p != NULL && p->val == -20);

    p = bstSearch(root, -5);
    CHECK(p != NULL && p->val == -5);

    CHECK(bstSearch(root, -9999) == NULL);

    bst_free(root);
    return true;
}

static bool test_large_range_queries() {
    int vals[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 65, 78, 90};
    struct TreeNode* root = NULL;
    for (size_t i = 0; i < sizeof(vals)/sizeof(vals[0]); i++) root = bst_insert(root, vals[i]);

    CHECK(bstSearch(root, 5)  != NULL);
    CHECK(bstSearch(root, 90) != NULL);
    CHECK(bstSearch(root, 27) != NULL);

    CHECK(bstSearch(root, 26) == NULL);
    CHECK(bstSearch(root, 1000) == NULL);

    bst_free(root);
    return true;
}

int main(void) {
    printf("Question 1 — BST Search: running tests...\n");

    RUN_TEST(test_empty_tree);
    RUN_TEST(test_single_node_hit_and_miss);
    RUN_TEST(test_root_match_in_larger_tree);
    RUN_TEST(test_example_tree_hits_and_misses);
    RUN_TEST(test_degenerate_increasing_chain);
    RUN_TEST(test_degenerate_decreasing_chain);
    RUN_TEST(test_with_negative_values);
    RUN_TEST(test_large_range_queries);

    printf("\nSummary: %d run, %d failed\n", g_tests_run, g_tests_failed);
    if (g_tests_failed == 0) {
        printf("Question 1: All tests passed.\n");
        return 0;
    } else {
        printf("Question 1: Some tests failed.\n");
        return 1;
    }
}
