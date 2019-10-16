#if 0
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
#endif

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *arr = (int *)malloc(2*sizeof(int));
    if (arr == NULL) return NULL;
    int i=0;
    int j=numbersSize-1;
    while (i<=j) {
        if (numbers[i]+numbers[j] > target) { //加起來大於target，右pointer往左移動
            j--;
	} else if (numbers[i]+numbers[j] < target) { //加起來小於target，左pointer往右移動
            i++;
       	} else if (numbers[i]+numbers[j] == target){ //加起來等於target
            printf("Found! i=%d, j=%d\n", i, j);
            arr[0] = i+1;
	    arr[1] = j+1;
	    *returnSize = 2;
	    return arr;
        }
    }
    printf("Not found...\n");
    return NULL;
}

int main() {
    int numbers[4] = {2, 7, 11, 15};
    int target = 9;
    int *returnS = (int *)malloc(sizeof(int));
    int *res = NULL;
    res = twoSum(numbers, sizeof(numbers)/sizeof(numbers[0]), target, returnS);
    if (res != NULL) {
    	for (int i=0; i<*returnS; i++) {
        	printf("res[%d]=%d\n", i, res[i]);
    	}
    }
    free(returnS);
    free(res);
    return 0;
}

