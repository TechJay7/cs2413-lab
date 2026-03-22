#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

static void runTest(int* nums, int numsSize, int target, const char* testName) {
    int returnSize = 0;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("%s: ", testName);

    if (result == NULL || returnSize != 2) {
        printf("FAIL (invalid return)\n");
        free(result);
        return;
    }

    int i = result[0];
    int j = result[1];

    if (i < 0 || i >= numsSize || j < 0 || j >= numsSize) {
        printf("FAIL (index out of range: [%d, %d])\n", i, j);
    } else if (i == j) {
        printf("FAIL (same index used twice: [%d, %d])\n", i, j);
    } else if (nums[i] + nums[j] != target) {
        printf("FAIL (nums[%d]=%d, nums[%d]=%d, sum=%d, target=%d)\n",
               i, nums[i], j, nums[j], nums[i] + nums[j], target);
    } else {
        printf("PASS (indices [%d, %d], values [%d, %d])\n",
               i, j, nums[i], nums[j]);
    }

    free(result);
}

int main(void) {
    int nums1[] = {2, 7, 11, 15};
    runTest(nums1, 4, 9, "Test 1: basic example");

    int nums2[] = {3, 2, 4};
    runTest(nums2, 3, 6, "Test 2: middle and end");

    int nums3[] = {3, 3};
    runTest(nums3, 2, 6, "Test 3: duplicate values");

    int nums4[] = {-1, -2, -3, -4, -5};
    runTest(nums4, 5, -8, "Test 4: all negative");

    int nums5[] = {10, 20, 30, 40, 50};
    runTest(nums5, 5, 70, "Test 5: larger values");

    int nums6[] = {0, 4, 3, 0};
    runTest(nums6, 4, 0, "Test 6: zeros");

    int nums7[] = {-3, 4, 3, 90};
    runTest(nums7, 4, 0, "Test 7: negative and positive");

    int nums8[] = {5, 75, 25};
    runTest(nums8, 3, 100, "Test 8: short array");

    int nums9[] = {1, 5, 1, 5};
    runTest(nums9, 4, 10, "Test 9: repeated numbers");

    int nums10[] = {8, 6, 7, 2, 15, 4};
    runTest(nums10, 6, 10, "Test 10: unordered array");

    int nums11[] = {100, -20, 30, 70, 50};
    runTest(nums11, 5, 80, "Test 11: mixed signs");

    int nums12[] = {1, 2};
    runTest(nums12, 2, 3, "Test 12: minimum valid size");

    return 0;
}