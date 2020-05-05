#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int strstr_test(const char *a, const char *b) {
    int idx;
    int a_len = strlen(a);
    int b_len = strlen(b);
//    printf("a_len=%d,  b_len=%d\n", a_len, b_len);

    if(b_len > a_len) return -1; //illegal case
    if(b_len == 0) return -1; //illegal case
    
    int round = a_len - b_len;

    while(round--) {
//        printf("a=%c, b=%c\n", *a, *b);
        if (*a != *b) {
            if (strlen(a) < strlen(b))
                return -1; //not enough length to match
            a++;
            continue;
        }
        for(int i=0; i<b_len; i++) {
//            printf("a[%d]=%c, b[%d]=%c\n", i, a[i], i, b[i]);
            if (a[i] == b[i]) {
//                printf("Oh.. match one..\n");
            } else {
//                printf("hmm.. not match...\n");
                idx = 0;
                a++;
                break;
            }
        }
    }
    idx = (a_len - strlen(a) == a_len ) ?  -1 : a_len - strlen(a);
//    printf("Yes, we found %s at %d\n", b, idx);
    return idx;
}

int main() {
    clock_t begin = clock();
    const char *a = "helollo"; //Better give a "const" when assigning string literal
    const char *sub_a = "oll";
    
    printf("Try to find the match index of '%s' in '%s'\n", sub_a, a);

    int ret_idx = strstr_test(a, sub_a);
    if (ret_idx != -1) printf("Yeah.. We found it at %d of %s\n", ret_idx, a);
    else printf("No...We can not find it\n");
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Spend %f seconds\n", time_spent);
    return 0;
}
