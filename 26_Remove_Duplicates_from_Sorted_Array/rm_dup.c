#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 0) return 0;
    int length = 1;
    int *ptr = nums;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != *ptr) { //遇到不同值
            ptr++; //ptr前進一步
            *ptr = nums[i]; //將此不同值設在ptr的位置
            length++; //長度加一
        }
    }
	printf("After remove dup : ");
	for (int i=0; i<length; i++)
		printf("%d ", nums[i]);
    return length;
}

void main(){
    int a[] = {0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(a, sizeof(a)/sizeof(a[0]));
    printf("\n length=%d", res);
}

