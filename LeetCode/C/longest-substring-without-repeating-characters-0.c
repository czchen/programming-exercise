int max(int x, int y)
{
    return (x > y) ? x : y;
}

int lengthOfLongestSubstring(char* s)
{
    char *head;
    char *end;

    int cnt[0x100] = { 0 };

    head = s;
    end = s;

    int ans = 0;

    for (; end[0]; ++end) {
        if (cnt[end[0]]) {
            ans = max(ans, end - head);

            for (; head < end; ++head) {
                --cnt[head[0]];
                if (head[0] == end[0]) {
                    ++head;
                    break;
                }
            }

        }

        ++cnt[end[0]];
    }

    ans = max(ans, end - head);

    return ans;
}

