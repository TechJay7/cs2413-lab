#include <stdio.h>
#include <stdbool.h>

void mergeSort(int arr[], int size);

void printArray(const int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

bool arraysEqual(const int a[], const int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void copyArray(int dest[], const int src[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void runSingleTest(const char* testName, const int input[], const int expected[], int size) {
    int actual[100];
    copyArray(actual, input, size);

    mergeSort(actual, size);

    printf("%s: ", testName);
    if (arraysEqual(actual, expected, size)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("  Input:    ");
        printArray(input, size);
        printf("\n");

        printf("  Expected: ");
        printArray(expected, size);
        printf("\n");

        printf("  Actual:   ");
        printArray(actual, size);
        printf("\n");
    }
}

int main() {
    {
        int input[] = {38, 27, 43, 3, 9, 82, 10};
        int expected[] = {3, 9, 10, 27, 38, 43, 82};
        runSingleTest("random array", input, expected, 7);
    }

    {
        int input[] = {1, 2, 3, 4, 5, 6};
        int expected[] = {1, 2, 3, 4, 5, 6};
        runSingleTest("already sorted", input, expected, 6);
    }

    {
        int input[] = {6, 5, 4, 3, 2, 1};
        int expected[] = {1, 2, 3, 4, 5, 6};
        runSingleTest("reverse sorted", input, expected, 6);
    }

    {
        int input[] = {4, 1, 3, 4, 2, 1};
        int expected[] = {1, 1, 2, 3, 4, 4};
        runSingleTest("with duplicates", input, expected, 6);
    }

    {
        int input[] = {-5, 2, 0, -1, 8, -3};
        int expected[] = {-5, -3, -1, 0, 2, 8};
        runSingleTest("with negative numbers", input, expected, 6);
    }

    {
        int input[] = {7};
        int expected[] = {7};
        runSingleTest("single element", input, expected, 1);
    }

    {
        int input[] = {};
        int expected[] = {};
        runSingleTest("empty array", input, expected, 0);
    }

    return 0;
}