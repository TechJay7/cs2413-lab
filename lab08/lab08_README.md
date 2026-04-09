# Lab Practice 06

This lab contains three practice questions in C.

## Folder Structure

- `question1/`
- `question2/`
- `question3/`
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

Run Question 3 only:

```bash
make run3
```

Remove compiled files:

```bash
make clean
```

---

# Question 1: Longest Common Prefix

## Description

Given an array of strings, find the longest common prefix shared by all strings.

A prefix is the starting part of a string.


## Example 1

Input:

```text
["flower", "flow", "flight"]
```

Output:

```text
"fl"
```

## Example 2

Input:

```text
   ["dog", "racecar", "car"]
```

Output:

```text
""
```
## Notes

- You are allowed to modify the first string (strs[0])
- Store the result directly in strs[0]
- Return strs[0]






---

# Question 2: Find the Index of the First Occurrence in a String

## Description

Given two strings haystack and needle, return the index of the first occurrence of needle in haystack.

If needle is not found, return -1.



## Notes

- Use a simple nested-loop approach
- Do NOT use built-in substring functions

## Example 1

Input:

```text
        haystack = "sadbutsad", needle = "sad"
```

Output:

```text
0
```

## Example 2

Input:

```text
haystack = "leetcode", needle = "leeto"
```

Output:

```text
-1
```

---

# Question 3: Is Subsequence

## Description

Given two strings s and t, determine whether s is a subsequence of t.

A subsequence is formed by deleting some characters without changing the order of the remaining characters.


## Example 1

Input:

```text
    s = "abc", t = "ahbgdc"
```

Output:

```text
true
```


## Example 2

Input:

```text
s = "axc", t = "ahbgdc"
```

Output:

```text
false
```

Explanation:

- `4 -> 9 -> 5` represents `495`
- `4 -> 9 -> 1` represents `491`
- `4 -> 0` represents `40`
- `495 + 491 + 40 = 1026`

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
   - `make run3`
4. Check the output and fix any failed test cases.

---

## Reminder

Read the comments in each `student.c` file carefully before writing your solution.
