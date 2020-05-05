//解法一
int maxSubArray1(int* nums, int numsSize) {
        if(numsSize == 0) return 0;
        if(numsSize == 1) return nums[0];
        int sum = 0;
        int curMax = nums[0];
        for (int i = 0; i < numsSize; i++) {
            if (sum < 0) sum = 0;
            sum += nums[i];  //包含第i個元素的子集合的合
            if (sum > curMax) curMax = sum;
        }
        return max;
}

