int getCommonPrefixLength(char *x, char *y) {
    int prefix_len = 0;

    while (x[prefix_len] && x [prefix_len] == y[prefix_len]) {
        ++prefix_len;
    }

    return prefix_len;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return strdup("");
    }

    char *prefix = strdup(strs[0]);

    for (int i = 1; i < strsSize; ++i) {
        int prefix_len = getCommonPrefixLength(prefix, strs[i]);
        prefix[prefix_len] = 0;
    }

    return prefix;
}
