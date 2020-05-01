#include <stdio.h>

#if 0
void rotate(int* nums, int numsSize, int k){
    int tmp = 0;
    while (k>0) {
        tmp = nums[numsSize-1];
        for(int i=numsSize-1; i>0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = tmp;
        k--;
    }
}
#endif


#if 1
void R(int *a, int n){
    for(int i=0;i<n/2;i++){
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}
void rotate(int nums[], int n, int k) {
    k = k%n;
    R(nums,n-k);
    R(nums+n-k,k);
    R(nums,n);
}
#endif
