#include <stdio.h>

int main()
{
    int rmb = 0;
    scanf("%d", &rmb);

    int n50 = rmb/50;
    int n20 = (rmb%50)/20;
    int n10 = (rmb%50%20)/10;
    int n5 = (rmb%50%20%10)/5;
    int n1 = (rmb%50%20%10%5);

    printf("%d\n%d\n%d\n%d\n%d\n", n50, n20, n10, n5, n1);

    return 0;
}
