#include <stdio.h>
#include <stdlib.h>
#if 0
//Output limit exceeded: O(n^2)
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize<=1) return false;
    for(int i=0; i<numsSize-1; i++) {
        for (int j=i+1;j<numsSize; j++) {
            printf("nums[%d]=%d, nums[%d]=%d\n", i, nums[i], j, nums[j]);
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}
#endif

#if 1
//Using quick sort & check
int comp (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int containsDuplicate(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i++) {
	printf("nums[%d]=%d\n", i, nums[i]);
        if (nums[i] == nums[i+1]) {
            return 1;
        }
    }
    return 0;
}
#endif

int main() {
    int a[] = {1,1,1,3,3,4,3,2,4,2};
    int res = containsDuplicate(a, sizeof(a)/sizeof(a[0]));
    if (res) printf("Yes\n");
    else printf("No\n");
    return 0;
}
