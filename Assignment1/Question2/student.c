#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement
     //O(n^2)
     for (int i = 0; i < numsSize - 1; i++) //sorting first so biggest number is in the middle
          for(int j = 0; j < numsSize - 1; j++)
               if(nums[j] > nums[j+1])
               {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
               }

     
     return nums[numsSize/2];

}
