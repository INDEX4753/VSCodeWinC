#include <stdio.h>
#include <string.h>

#define MAX_N 150000
#define MAX_DIGITS 64
#define MAX_D 8

int main()
{
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    const int p_val = n % k;

    static char all_chars[MAX_N * MAX_DIGITS] = {0};
    static int lens[MAX_N] = {0};
    static int cnt[MAX_DIGITS][MAX_D] = {0};
    char result[MAX_DIGITS + 1] = {0};

    int max_len = 0;
    int char_pos = 0;

    for (int i = 0; i < n; ++i)
    {
        char buf[MAX_DIGITS + 1];
        scanf(" %s", buf);
        int len = strlen(buf);
        lens[i] = len;

        if (len > max_len)
        {
            max_len = len;
        }

        memcpy(all_chars + char_pos, buf, len);
        char_pos += len;
    }

    char_pos = 0;
    for (int i = 0; i < n; ++i)
    {
        int len = lens[i];
        int pad = max_len - len;
        for (int pos = 0; pos < max_len; ++pos)
        {
            int dig;

            if (pos < pad)
            {
                dig = 0;
            }
            else
            {
                dig = all_chars[char_pos + (pos - pad)] - '0';
            }
            cnt[pos][dig]++;
        }
        char_pos += len;
    }

    int res_idx = 0;
    int lead_zero = 1;
    for (int pos = 0; pos < max_len; ++pos)
    {
        for (int dig = 0; dig < d; ++dig)
        {

            if (cnt[pos][dig] % k == p_val)
            {
                if (lead_zero)
                {
                    if (dig == 0)
                    {
                        continue;
                    }
                    lead_zero = 0;
                }
                result[res_idx++] = '0' + dig;
                break;
            }
        }
    }

    if (res_idx == 0)
    {
        result[res_idx++] = '0';
    }
    result[res_idx] = '\0';

    printf("%s\n", result);
    return 0;
}
