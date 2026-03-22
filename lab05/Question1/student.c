/*
Question 1: Two Sum (Hash-based)

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

You must solve this problem using a hash-table style idea (not brute force).

Example:
Input:
nums = [2, 7, 11, 15], target = 9

Output:
[0, 1]

Explanation:
nums[0] + nums[1] = 2 + 7 = 9

Instructions:
- Implement the function below.
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2.
- The caller will free the returned array.

Hint:
As you scan the array, for each nums[i], check whether target - nums[i]
has appeared before.
*/

#include <stdlib.h>

/*
A simple hash entry for integer value -> index mapping.
This implementation uses separate chaining.
*/
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        if (find(table, complement, &foundIndex)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }

        insert(table, nums[i], i);
    }

    *returnSize = 0;
    freeTable(table);
    return NULL;
}