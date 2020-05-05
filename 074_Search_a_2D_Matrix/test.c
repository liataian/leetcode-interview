#include <stdio.h>
int main(int argc, char* argv[])
{
    int x[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 987, 9, 9 } }; 
    int(*p)[4] = x;
    printf("p[2][1]=%d\n", p[2][1]); 
    printf("sizeof(p) is %lu , sizeof(*p) is %lu\n", sizeof(p), sizeof(*p)); 
    return 0;
}
