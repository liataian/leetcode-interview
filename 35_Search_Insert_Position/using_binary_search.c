#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    if(target<nums[0])
        return 0;
    if(target>nums[numsSize-1])
        return numsSize;
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

int main() {
    int a[5] = {13,16,79,88,100};
    int resIdx = searchInsert(a, 5, 15);
    printf("resIdx=%d", resIdx);
}

