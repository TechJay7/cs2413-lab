# Lab Practice 07

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
