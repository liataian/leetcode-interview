#include <stdio.h>

//me
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize){
    int i=0, j=0; 
    while (i<numsSize-1 && j<numsSize-1) {
        if(nums[i]!=0) { //trace zero
            i++;
        }
        if (nums[j]==0) { //trace nono zero
            j++;
        }
        if (j>i) swap(nums+i,nums+j);
        else j++;
    }
}

//other
void moveZeroes2(int* nums, int numsSize) {
    int totalZeros = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            totalZeros++;
        }
        else {
            nums[i - totalZeros] = nums[i];
        }
    }

    for(int i = (numsSize - totalZeros); i < numsSize; i++) {
        nums[i] = 0;
    }
}
