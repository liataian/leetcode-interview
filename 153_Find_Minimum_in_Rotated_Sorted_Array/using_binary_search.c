#include <stdio.h>
#include <stdlib.h>

//2,3,4,5,1
//1,2,3,4,5

int binary_search(int *nums, int nums_size) {
    int head = 0;
    int last = nums_size-1;

    if (nums_size==2) { //If only 2 elements, just compare it.
        if (nums[head] > nums[last])
            return last;
        else
            return head;
    }

    if (nums[head]<nums[last]) //if array never rotate, first element must be a smallest element.
        return head;

    while(head<last) {
        int mid = (head+last)/2;
        if (nums[mid] >= nums[head]) { //minimum must at right side e.g {2,4,5,6,7,0,1} or {2,3,4,5,1}
            if (nums[mid] > nums[mid+1]) {
                printf("Found min value %d at idx %d\n", nums[mid+1], mid+1);
                return mid+1;
            }
            head = mid+1;
        } else  { //minimum must at left side, e.g {6,7,0,1,2,4,5} or {4,5,1,2,3}
            if (nums[mid-1] > nums[mid]) {
                printf("Found min value %d at idx %d\n", nums[mid], mid);
                return mid;
            }
            last = mid;
        }
    }
    return 0;
}

int findMin(int* nums, int numsSize){
    int idx = 0;
    if (numsSize == 1) return nums[idx];
   
    idx = binary_search(nums, numsSize);

    return nums[idx];
}

int main(){
    //int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    int nums[7] = {6, 7, 0, 1, 2, 4, 5};
    //int nums[5] = {2,3,4,5,1}; 
    //int nums[5] = {1,2,3,4,5};
    int min = findMin(nums, sizeof(nums)/sizeof(nums[0]));
    printf("min value is %d\n", min);
}
