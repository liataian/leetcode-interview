#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s){

    int total_len = strlen(s)-1;
    int word_len = 0;

    while (total_len>=0 && *(s+total_len)==' ') { //Try to find "first non-space char" from right to left
        total_len--;
    }
    while (total_len>=0 && *(s+total_len)!=' ') { //Try to find "last word" from first non-space char to left
        word_len++;
        total_len--;
    }
    return word_len;
}    

int main() {
    char str[15] = "Hello world ";
    printf("String is \"%s\"\n", str);
    int len = lengthOfLastWord(str);
    printf("len of last word is %d\n", len);
    return 0;
}
