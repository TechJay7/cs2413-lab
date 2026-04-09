#include <stdio.h>

int strStr(char* haystack, char* needle);

void runTest(char* haystack, char* needle, int expected) {
    int result = strStr(haystack, needle);
    if (result == expected) {
        printf("PASS | haystack=\"%s\", needle=\"%s\" | Expected: %d, Got: %d\n",
               haystack, needle, expected, result);
    } else {
        printf("FAIL | haystack=\"%s\", needle=\"%s\" | Expected: %d, Got: %d\n",
               haystack, needle, expected, result);
    }
}

int main() {
    runTest("sadbutsad", "sad", 0);
    runTest("leetcode", "leeto", -1);
    runTest("hello", "ll", 2);
    runTest("aaaaa", "bba", -1);
    runTest("abc", "abc", 0);
    runTest("abc", "c", 2);
    runTest("mississippi", "issip", 4);
    runTest("a", "a", 0);
    runTest("a", "aa", -1);

    return 0;
}