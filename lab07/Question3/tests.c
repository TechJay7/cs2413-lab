#include <stdio.h>
#include <stdbool.h>

void quickSort(int arr[], int size);

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

    quickSort(actual, size);

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
        int input[] = {10, 7, 8, 9, 1, 5};
        int expected[] = {1, 5, 7, 8, 9, 10};
        runSingleTest("random array", input, expected, 6);
    }

    {
        int input[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        runSingleTest("already sorted", input, expected, 5);
    }

    {
        int input[] = {5, 4, 3, 2, 1};
        int expected[] = {1, 2, 3, 4, 5};
        runSingleTest("reverse sorted", input, expected, 5);
    }

    {
        int input[] = {4, 2, 4, 1, 3, 2};
        int expected[] = {1, 2, 2, 3, 4, 4};
        runSingleTest("with duplicates", input, expected, 6);
    }

    {
        int input[] = {-2, 8, 0, -7, 3, 1};
        int expected[] = {-7, -2, 0, 1, 3, 8};
        runSingleTest("with negative numbers", input, expected, 6);
    }

    {
        int input[] = {99};
        int expected[] = {99};
        runSingleTest("single element", input, expected, 1);
    }

    {
        int input[] = {};
        int expected[] = {};
        runSingleTest("empty array", input, expected, 0);
    }

    return 0;
}