int searchInsert(int* nums, int numsSize, int target){
    int prev = 0;
    int current = 0;
    if (target < nums[0]) return 0;
    for (int i=0; i<numsSize; i++) {
       if (target > nums[i]) { //found smaller one
           prev = i;
       } else if (target < nums[i]) { //found bigger one
           current = i;
           if (current - prev == 1)
               return current;
       } else { //found
           current = i;
           return current;
       }
    }
    return numsSize+1;
}
