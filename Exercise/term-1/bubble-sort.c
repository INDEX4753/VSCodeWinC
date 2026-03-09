#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        getchar();

        int a[num];
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &a[j]);
        }
        getchar();

        int judge = 1;
        for (int t = 0; t < num; t++)
        {
            if (a[num - 1] < a[t])
            {
                judge = 0;
            }
        }

        if (judge)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
