#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    //先去頭去尾
    if(target<nums[0])
        return 0;
    if(target>nums[numsSize-1])
        return numsSize;

    //再考慮中間
    int low=0,high=numsSize-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int main(void) {
    int a[5] = {13,16,79,88,100};
    int arg = 0;
    printf("Please give a value to search its position...\n>>> ");
    scanf("%d", &arg);
    printf("You give %d\n", arg);
    int resIdx = searchInsert(a, 5, arg);
    printf("resIdx=%d\n", resIdx);
}

