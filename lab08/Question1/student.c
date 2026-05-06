#include <stdio.h>

/*
Question 1: Longest Common Prefix

Write a function to find the longest common prefix string
among an array of strings.

A prefix is the beginning part of a string.

Examples:
Input: ["flower", "flow", "flight"]
Output: "fl"

Input: ["dog", "racecar", "car"]
Output: ""

IMPORTANT:
- You ARE allowed to modify the first string (strs[0])
- You should store the result directly in strs[0]
- Return strs[0] as the result
*/

char* longestCommonPrefix(char** strs, int strsSize) {
      // TODO: implement
      if (strs == NULL || strsSize == 0)
            return "";

      if (strs[0] == NULL)
            return "";

      for(int i = 1; i < strsSize; i++)
      {
            int j = 0;

            while (strs[0][j] != '\0' && strs[i][j] != '\0' && strs[0][j] == strs[i][j])
                  j++;
            
            strs[0][j] = '\0';
      }
      return strs[0];

}