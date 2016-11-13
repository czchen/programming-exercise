char* longestPalindrome(char* s) {
    int ans_start = 0;
    int ans_end = 0;
    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        int start = i;
        int end = i;

        while (start > 0 && end < len - 1) {
            if (s[start - 1] == s[end + 1]) {
                --start;
                ++end;
            } else {
                break;
            }
        }

        if (end - start > ans_end - ans_start) {
            ans_start = start;
            ans_end = end;
        }
    }

    for (int i = 0; i < len - 1; ++i) {
        int start = i + 1;
        int end = i;

        while (start > 0 && end < len - 1) {
            if (s[start - 1] == s[end + 1]) {
                --start;
                ++end;
            } else {
                break;
            }
        }

        if (end - start > ans_end - ans_start) {
            ans_start = start;
            ans_end = end;
        }
    }

    char *ans = malloc(ans[0] * (ans_end - ans_start + 1 + 1));
    if (!ans) {
        return ans;
    }

    memcpy(ans, s + ans_start, ans_end - ans_start + 1);
    ans[ans_end - ans_start + 1] = 0;

    return ans;
}
