#include <stdio.h>
#include <stdlib.h>

int binary_search(int *nums, int nums_size, int target) {
    int head = 0;
    int last = nums_size-1;

//case1: {4, 5, 6, 7, 0, 1, 2}
//case2: {6, 7, 0, 1, 2, 4, 5}
//case3: {3,1}
    while(head<=last) {
        int mid = (head+last)/2;

        if (target==nums[mid]) //matches
            return mid;

        //Already know target!=nums[mid] here!
        if (nums[mid] >= nums[head]) { //elements on the left side of nums[mid](includes) are sorted and can use binary search for it
            if (target < nums[mid] && target >= nums[head]) { //target is on the left side of nums[mid]
                last = mid-1;
            } else { //target is on the right side of nums[mid]
                head = mid+1;
            }
        } else { //elements on the left side of nums[mid](includes) are not sorted so we use binary search on the right side of nums[mid]
            if (target > nums[mid] && target <= nums[last]) { //target is on the right side of nums[mid] 
                head = mid+1;
            } else { //target is on the left side of nums[mid]
                last = mid-1;
            }
        }
        printf("head=%d, mid=%d, last=%d\n", head, mid, last);
    }
    return -1;
}

int search(int *nums, int numsSize, int target){
    int idx = 0;
   
    idx = binary_search(nums, numsSize, target);

    return idx;
}

int main(){
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    //int nums[7] = {6, 7, 0, 1, 2, 4, 5};
    //int nums[5] = {2,3,4,5,1};
    //int nums[5] = {1,2,3,4,5};
    //int nums[2] = {3, 1};
    int target;

    printf("Current array = { ");
    for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++) {
        printf("%d ", nums[i]);
    }
    printf("}\n");

    printf("Enter a target to search:\n");
    scanf("%d", &target);

    int idx = search(nums, sizeof(nums)/sizeof(nums[0]), target);

    if (idx < 0)
        printf("No match..\n");
    else
        printf("Target value is %d at index %d\n", nums[idx], idx);
}
