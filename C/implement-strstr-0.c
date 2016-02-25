int strStr(char* haystack, char* needle) {
    int needle_len = strlen(needle);
    int limit = strlen(haystack) - needle_len + 1;

    for (int i = 0; i < limit; ++i) {
        if (memcmp(needle, haystack + i, needle_len) == 0) {
            return i;
        }
    }

    return -1;
}
