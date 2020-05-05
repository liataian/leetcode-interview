#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target){
    int *rarray = (int*)calloc(2, sizeof(int));
    for (int i=0; i<numsSize; i++) {
        for (int j=0; j<numsSize; j++){
            if (j==i) continue;
            if (target - (nums[i]+nums[j]) == 0) {
                *rarray = i;
                *(rarray+1) = j;
		return rarray;
            }
        }
    }
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int *res = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target);
    for (int i=0;i<2;i++) printf("%d \n", res[i]);
    return 0;
}
