#include <stdio.h>
#include <string.h>

/*
Question 2: Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the
first occurrence of needle in haystack, or -1 if needle is not
part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1

Note:
- You may use a simple nested-loop solution.
- Do not use library substring search functions.
*/

int strStr(char* haystack, char* needle) {
    // TODO: implement
    if(haystack == NULL || needle == NULL)
        return -1;
    
    int hayLen = strlen(haystack);
    int needLen = strlen(needle);

    if (needLen == 0)
        return 0;
    
    if(needLen > hayLen)
        return -1;
    
    for(int i = 0; i <= hayLen - needLen; i++)
    {
        int j = 0;
        while(j < needLen && haystack[i + j] == needle[j])
            j++;
        
        if(j == needLen)
            return i;
    }

    return -1;
}