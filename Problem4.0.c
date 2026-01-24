#include <stdio.h>
#include <string.h>

int main()
{
    char S[1001]; // 主字符串，长度不超过1000
    int M;
    scanf("%s", S);
    scanf("%d", &M);

    for (int m = 0; m < M; ++m)
    {
        int l, r;
        char t[41]; // 模式串长度不超过40
        scanf("%d %d %s", &l, &r, t);

        int len_S = strlen(S);
        int len_t = strlen(t);
        int len_sub = r - l + 1; // 子串长度

        // 模式串长度大于子串长度，直接输出0
        if (len_t > len_sub)
        {
            printf("0\n");
            continue;
        }

        int start = l - 1; // 子串在S中的起始索引（0-based）
        int end = r - 1;   // 子串在S中的结束索引（0-based）
        int count = 0;     // 匹配次数

        // 遍历子串中所有可能的起始位置i
        for (int i = start; i <= end - len_t + 1; ++i)
        {
            int is_match = 1;
            // 检查从i开始的len_t个字符是否与t匹配
            for (int j = 0; j < len_t; ++j)
            {
                if (S[i + j] != t[j])
                {
                    is_match = 0;
                    break;
                }
            }
            if (is_match)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}