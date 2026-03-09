#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int opr[n+1][k+1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            scanf("%d", &opr[i][j]);
        }
    }

    int score[1000];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &score[i]);
    }

    for (int i = 0; i <n; i++)
    {
        int stdNum = opr[i][0];
        int idx = stdNum - 1;
        if(opr[i][idx + 1] > score[idx])
        {
            for (int j = 0; j < k; j++)
            {
                score[j] = opr[i][j + 1];
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", score[i]);
    }
    printf("\n");

    return 0;
}
