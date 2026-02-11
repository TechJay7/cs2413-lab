#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement
    int newSize = digitsSize; // we can assume the best case that theyre the same size
    int allNines = 1; 
   for(int i = digitsSize - 1; i >= 0; i--)
   {
    if(digits[i] != 9)
    {
        allNines = 0;
        break;
    }
   
   }
        // so now if the code comes here we assume theres only 9's
        if(allNines)
        newSize = digitsSize + 1;

    int* arr = (int*)malloc(newSize * sizeof(int));
    if (arr == NULL) { //make sure not null or crash
    *returnSize = 0;
    return NULL;
}
    int shifter = newSize - digitsSize; // we can use this to see if a shift was made

    for(int i = 0; i < digitsSize; i++)
    {
        arr[i + shifter] = digits[i];
    }

    if(allNines)
    arr[0] = 0;

    for (int i = newSize - 1; i >= 0; i--)
    {
        if(arr[i] != 9)
        {
            arr[i]++;
            break;
        }
        arr[i] = 0;
    }

    *returnSize = newSize;
    return arr;


}

