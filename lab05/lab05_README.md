# Lab Practice 05

This lab contains two practice questions in C.

## Folder Structure

- `question1/`
- `question2/`
- `Makefile`

Each question folder contains:

- `student.c` — your implementation file
- `tests.c` — the test program

---

## How to Run

Run Question 1 only:

```bash
make run1
```

Run Question 2 only:

```bash
make run2
```

Remove compiled files:

```bash
make clean
```

---

# Question 1: Two Sum

## Description

Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

## Function

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
```

## Notes

- If the tree is empty, return `0`.
- A tree with only one node has depth `1`.

## Example 1

Input:

```text
nums = [2, 7, 11, 15], target = 9
```

Output:

```text
[0, 1]
```

## Example 2

Input:

```text
    nums = [3, 2, 4], target = 6
```

Output:

```text
[1, 2]
```

## Example 3

Input:

```text
nums = [3, 3], target = 6
```

Output:

```text
[0, 1]
```

---

# Question 2: Kth Largest Element in an Array

## Description

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

For this lab, you should solve the problem using a heap-based idea.

## Function

```c
int findKthLargest(int* nums, int numsSize, int k);
```

## Notes

You may assume 1 <= k <= numsSize.

This problem asks for the kth largest value after sorting.

Repeated values still count.

A min-heap of size k is a good way to solve this problem efficiently.

## Example 1

Input:

```text
nums = [3, 2, 1, 5, 6, 4], k = 2
```

Output:

```text
5
```

## Example 2

Input:

```text
      nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
```

Output:

```text
4
```

## Example 3

Input:

```text
nums = [7], k = 1
```

Output:

```text
7
```

---



## Expected Output Style

The test files print whether each test case passes or fails:

```text
[PASS] test name -> expected X, got X
[FAIL] test name -> expected X, got Y
```

This helps you see which test cases are correct and which ones still need work.

---

## Suggested Workflow

1. Open `student.c` for one question.
2. Write your solution.
3. Run the corresponding command:
   - `make run1`
   - `make run2`
4. Check the output and fix any failed test cases.

---

## Reminder

Read the comments in each `student.c` file carefully before writing your solution.
