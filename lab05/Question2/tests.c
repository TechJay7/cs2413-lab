#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k);

static void runTest(int* nums, int numsSize, int k, int expected, const char* testName) {
    int result = findKthLargest(nums, numsSize, k);

    printf("%s: ", testName);
    if (result == expected) {
        printf("PASS\n");
    } else {
        printf("FAIL (got %d, expected %d)\n", result, expected);
    }
}

int main(void) {
    int nums1[] = {3, 2, 1, 5, 6, 4};
    runTest(nums1, 6, 2, 5, "Test 1: basic example");

    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    runTest(nums2, 9, 4, 4, "Test 2: duplicates");

    int nums3[] = {7};
    runTest(nums3, 1, 1, 7, "Test 3: single element");

    int nums4[] = {-1, -2, -3, -4};
    runTest(nums4, 4, 2, -2, "Test 4: all negative");

    int nums5[] = {10, 10, 9, 8, 8, 7};
    runTest(nums5, 6, 3, 9, "Test 5: repeated large values");

    int nums6[] = {5, 4, 3, 2, 1};
    runTest(nums6, 5, 1, 5, "Test 6: largest element");

    int nums7[] = {5, 4, 3, 2, 1};
    runTest(nums7, 5, 5, 1, "Test 7: smallest element");

    int nums8[] = {2, 2, 2, 2, 2};
    runTest(nums8, 5, 3, 2, "Test 8: all same");

    int nums9[] = {9, 8, 7, 6, 5, 4, 3};
    runTest(nums9, 7, 4, 6, "Test 9: descending order");

    int nums10[] = {1, 2, 3, 4, 5, 6, 7};
    runTest(nums10, 7, 2, 6, "Test 10: ascending order");

    int nums11[] = {-10, 0, 5, 3, 8, -2};
    runTest(nums11, 6, 3, 3, "Test 11: mixed values");

    int nums12[] = {100, 50, 200, 150};
    runTest(nums12, 4, 2, 150, "Test 12: larger numbers");

    int nums13[] = {12, 11, 13, 5, 6, 7};
    runTest(nums13, 6, 3, 11, "Test 13: heap-style example");

    int nums14[] = {4, 1, 6, 2, 9, 7, 8, 3, 5};
    runTest(nums14, 9, 6, 4, "Test 14: shuffled 1 to 9");

    int nums15[] = {-5, -1, -3, -2, -4};
    runTest(nums15, 5, 4, -4, "Test 15: negative ranking");

    return 0;
}