#include <stdio.h>

int getSum(int a, int b){
    if(b == 0) return a;
    int sum = a^b; //get sum without carry
    int carry = ((a&b)&0xffffffff)<<1; //get carry and move left
    return getSum(sum, carry); //until no carry
}

int main(){
    int res = getSum(-1,5);
    printf("res=%d\n", res);
}
