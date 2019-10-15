#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target){
    int *rarray = (int*)malloc(2 * sizeof(int));
    if (rarray == NULL) {
        printf("something wrong\n");
        return NULL;
    }
    int head = 0;
    int last = numsSize-1;
    while (head < last) {
        printf("head=%d, last=%d\n", head, last);
        if (nums[head] + nums[last] > target) {
            last--;
            printf("last=%d\n", last);
        } else if (nums[head] + nums[last] < target) {
            head++;
            printf("head=%d\n", head);
        } else {
            printf("Found!! nums[%d]=%d, nums[%d]=%d\n", head, nums[head], last, nums[last]);
            rarray[0] = head;
            rarray[1] = last;
            return rarray; 
        }
    }
    printf("unable to find...\n");
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int *res = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target);
    for (int i=0;i<2;i++) printf("%d \n", res[i]);
    return 0;
}
