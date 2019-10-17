#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int res = 0;
    for (int i=0; i<numsSize; i++) {
        res^=nums[i];
    }
    return res;
}

int main() {
    int a[5] = {4,1,2,1,2};
    int ret = singleNumber(a, 5);
    printf("ret=%d\n", ret);
    return 0;
}
