#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
//nums[i] + nums[j] + nums[k] == 0
int target = 0;
   int i = 0;
    int j = i + 1;
    int k = n - 1;
    for(; i < n; i++)
    {
        if(!(i < j && j < k))
            return 0;
        if(nums[i] + nums[j] + nums[k] < target)
            j++;
        else if (nums[i] + nums[j] + nums[k] > target)
            k--;
        else if (nums[i] + nums[j] + nums[k] == target)
        {
            *out_i = i; 
            *out_j = j;
            *out_k = k; 
            
            return 1;
        }
    }

    return 0;
}
