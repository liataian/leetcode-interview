#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int idx = m+n-1;
    int i = m-1;
    int j = n-1;
    while (i>=0 && j>=0) {
        if (nums2[j] >= nums1[i]) {
            nums1[idx] = nums2[j];
            j--;
            //printf("idx=%d, j=%d\n", idx, j);
        } else if (nums2[j] <= nums1[i]) {
            nums1[idx] = nums1[i];
            i--;
            //printf("idx=%d, i=%d\n", idx, i);
        }
        idx--;
    }
    printf("idx=%d, i=%d, j=%d\n", idx, i, j);
    while(i<0 && j>=0){
        nums1[idx--] = nums2[j--];
    }
}

int main() {
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,5,6};
    merge(a, sizeof(a)/sizeof(a[0]), 3, b, sizeof(b)/sizeof(b[0]), 3);
    for (int i=0;i<sizeof(a)/sizeof(a[0]); i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
