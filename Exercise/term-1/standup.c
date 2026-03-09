#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }

    int delta = 0,
        sum = a[0],
        num = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < i + 1)
        {
            delta = i + 1 - sum;
            sum += a[i + 1] + delta;
            num += delta;
        }
        else
        {
            sum += a[i + 1];
        }
        // 测试代码是否正确
        // printf("%d ", num);
    }

    printf("%d", num);
    return 0;
}