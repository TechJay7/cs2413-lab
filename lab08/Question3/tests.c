#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t);

void runTest(char* s, char* t, bool expected) {
    bool result = isSubsequence(s, t);
    if (result == expected) {
        printf("PASS | s=\"%s\", t=\"%s\" | Expected: %s, Got: %s\n",
               s, t,
               expected ? "true" : "false",
               result ? "true" : "false");
    } else {
        printf("FAIL | s=\"%s\", t=\"%s\" | Expected: %s, Got: %s\n",
               s, t,
               expected ? "true" : "false",
               result ? "true" : "false");
    }
}

int main() {
    runTest("abc", "ahbgdc", true);
    runTest("axc", "ahbgdc", false);
    runTest("", "ahbgdc", true);
    runTest("ace", "abcde", true);
    runTest("aec", "abcde", false);
    runTest("aaaaaa", "bbaaaa", false);
    runTest("b", "abc", true);
    runTest("abc", "", false);

    return 0;
}