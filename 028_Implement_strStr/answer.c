int strStr(char* haystack, char* needle) {
    int lh = strlen(haystack);
    int ln = strlen(needle);
    
    if((lh == 0 && ln == 0) || ln == 0 || needle == haystack)
      return 0;
    for (int i = 0; i <=(lh-ln); i++) {
        if(haystack[i] == needle[0])
            if(strncmp((haystack+i), needle, ln) == 0)
                return i;
    }
    return -1;
}
