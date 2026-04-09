#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

void runTest(char** strs, int strsSize, const char* expected) {
    char* result = longestCommonPrefix(strs, strsSize);

    if (strcmp(result, expected) == 0) {
        printf("PASS | Expected: \"%s\", Got: \"%s\"\n", expected, result);
    } else {
        printf("FAIL | Expected: \"%s\", Got: \"%s\"\n", expected, result);
    }
}

int main() {
    // Test 1: normal common prefix
    char a1[] = "flower";
    char a2[] = "flow";
    char a3[] = "flight";
    char* t1[] = {a1, a2, a3};
    runTest(t1, 3, "fl");

    // Test 2: no common prefix
    char b1[] = "dog";
    char b2[] = "racecar";
    char b3[] = "car";
    char* t2[] = {b1, b2, b3};
    runTest(t2, 3, "");

    // Test 3: longer common prefix
    char c1[] = "interview";
    char c2[] = "internet";
    char c3[] = "internal";
    char c4[] = "into";
    char* t3[] = {c1, c2, c3, c4};
    runTest(t3, 4, "int");

    // Test 4: only one string
    char d1[] = "a";
    char* t4[] = {d1};
    runTest(t4, 1, "a");

    // Test 5: one string is prefix of others
    char e1[] = "ab";
    char e2[] = "abc";
    char e3[] = "abcd";
    char* t5[] = {e1, e2, e3};
    runTest(t5, 3, "ab");

    // Test 6: first mismatch at second character
    char f1[] = "aa";
    char f2[] = "ab";
    char* t6[] = {f1, f2};
    runTest(t6, 2, "a");

    // Test 7: identical strings
    char g1[] = "same";
    char g2[] = "same";
    char g3[] = "same";
    char* t7[] = {g1, g2, g3};
    runTest(t7, 3, "same");

    // Test 8: empty first string
    char h1[] = "";
    char h2[] = "abc";
    char* t8[] = {h1, h2};
    runTest(t8, 2, "");

    // Test 9: all empty strings
    char i1[] = "";
    char i2[] = "";
    char i3[] = "";
    char* t9[] = {i1, i2, i3};
    runTest(t9, 3, "");

    // Test 10: common prefix is full first string
    char j1[] = "car";
    char j2[] = "cart";
    char j3[] = "carpet";
    char* t10[] = {j1, j2, j3};
    runTest(t10, 3, "car");

    // Test 11: mismatch at first character
    char k1[] = "x";
    char k2[] = "y";
    char k3[] = "z";
    char* t11[] = {k1, k2, k3};
    runTest(t11, 3, "");

    // Test 12: multiple strings with single-letter prefix
    char l1[] = "apple";
    char l2[] = "ape";
    char l3[] = "april";
    char* t12[] = {l1, l2, l3};
    runTest(t12, 3, "ap");

    return 0;
}