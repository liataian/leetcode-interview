//解法二 (maxSub[i] = maxSub[i-1] > 0 ? nums[i]+maxSub[i-1] : nums[i])
int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    int curMax = nums[0]; //截至目前元素前的最大合
    int sum = nums[0]; //含目前元素後的合
    for(int i = 1; i < numsSize; i++){
        //如果sum是負的sum+nums[i]一定比較小，此時選擇nums[i]等於把sum設為0
        sum = max(sum + nums[i], nums[i]); 
        if(sum > curMax) curMax = sum; //決一死戰
    }
    return curMax;
}

