#include <stdio.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize){
    int i=0;
    int j=sSize-1;
    while(i<j) {
        swap(s+i, s+j);
        i++;
        j--;
    }
}

int main(){
    char a[] = {'h', 'e', 'l', 'l', 'o'};
    printf("Before: a=%s\n", a);
    reverseString(a, sizeof(a)/sizeof(a[0]));
    printf("After: a=%s\n", a);
    return 0;
}
