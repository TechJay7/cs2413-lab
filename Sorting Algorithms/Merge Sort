#include <stdlib.h>
#include <stddef.h>
/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    if (arr == NULL || size <= 1)
        return;

    mergeSortHelper(arr, 0, size - 1);
}

void mergeSortHelper(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSortHelper(arr,left,mid);
    mergeSortHelper(arr, mid + 1, right);

    merge (arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

