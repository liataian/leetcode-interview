#include <stdio.h>

//Binary search function
int bs(int *a, int matrixColSize, int target) {
	printf("Start search:........\n");
        int head = 0;
        int last = matrixColSize-1;
#if 0
        //DEBUG
        for (int j=0; j<matrixColSize; j++) {
            printf("a[%d]=%d\n", j, a[j]);
        }
#endif

#if 1
        printf("Start search:\n");
        while (head <= last) {
                int mid = (head+last)/2;
                printf("Current head=%d, last=%d, mid=%d\n", head, last, mid);
                if (a[mid] > target) {
                        last = mid-1;
                } else if (a[mid] < target) {
                        head = mid+1;
                } else if (a[mid] == target) {
                        printf("Found idx of %d is %d\n", target, mid);
                        return 1;
                }
        }
        printf("Can not find idx of %d\n", target);
#endif
        return 0;
}

int searchMatrix(int** matrix, int[] *ptr2, int matrixSize, int* matrixColSize, int target){
    if (matrixSize*(*matrixColSize)<0) return 0;
    printf("matrixSize=%d, matrixColSize=%d\n", matrixSize, *matrixColSize);

#if 0
    //DEBUG
    for (int i=0; i<matrixSize; i++) {
	printf("i=%d, matrix[%d]=%d\n", i, i, matrix[i]);
        for (int j=0;j<*matrixColSize; j++) {
          printf("matrix[%d][%d]=%d\n", i, j, matrix[i][j]);
        }
    }
#endif
    
    for (int j=0; j<matrixSize; j++) {
	printf("Round %d\n", j+1);
	//Check each line using binary search
        if (bs(matrix[j], *matrixColSize, target)) {
            printf("Found!!!\n");
            return 1;
        }
    }
    return 0;
}

int main() {
   int matrix[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
   int matrixColSize = 4;
   int *ptr = &matrix[0][0];
   int (*ptr2)[4] = matrix;
   int target = 50;
   int res = searchMatrix(&ptr, &ptr2, 3, &matrixColSize, target);
   if (res==0) printf("Can not find target index\n");
   return 0;
}
