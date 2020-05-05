#include <stdio.h>
#include <stdlib.h>

//Time:O(n)
//Space:O(1)

int findMin(int* nums, int numsSize){
    int res = 0;
    if (numsSize == 1) return nums[res];
    
    for (int i=0; i<numsSize-1; i++) {
        if (nums[i]>nums[i+1]) {
            res = nums[i+1];
            return res;
        }
    }
    return nums[res];
}

int main(){
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    int min = findMin(nums, sizeof(nums)/sizeof(nums[0]));
    printf("min value is %d\n", min);
}
