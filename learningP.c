#include <stdio.h>
#define TASK_NUM 26

int main()
{
    int all_days = 365;
    scanf("%d", &all_days);
    getchar(); // o

    int b[TASK_NUM] = {0};
    for (int i = 0; i < TASK_NUM; i++)
    {
        scanf("%d", &b[i]);
    }
    getchar(); // o

    int a[all_days][TASK_NUM];
    for (int i = 0; i < all_days; i++)
    {
        for (int j = 0; j < TASK_NUM; j++)
        {
            scanf("%d", &a[i][j]);
        }
        getchar();
    } // o

    int power = 0;
    int last[TASK_NUM] = {0};
    int choice[all_days];

    for (int d = 1; d <= all_days; d++)
    {
        int delta[TASK_NUM] = {0};
        for (int c = 0; c < TASK_NUM; c++)
        {
            int forgetNum = 0;
            for (int i = 0; i < TASK_NUM; i++)
            {
                forgetNum += b[i] * (d - last[i]);
            } // o
            delta[c] = a[d - 1][c] - forgetNum + b[c] * (d - last[c]);
        } // o

        int max = -1e9;
        for (int i = 0; i < TASK_NUM; i++)
        {
            if (delta[i] > max)
            {
                max = delta[i];
                choice[d - 1] = i;
            }
        } // o
        int opt = choice[d - 1];
        last[opt] = d;

        power += max; // o
    }

    printf("%d\n", power);
    for (int i = 0; i < all_days; i++)
    {
        printf("%d\n", choice[i] + 1);
    } // o
}
