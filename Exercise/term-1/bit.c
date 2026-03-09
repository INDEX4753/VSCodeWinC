#include <stdio.h>

int main()
{
    long long int a = 0;
    int b = 0;
    scanf("%lld %d", &a, &b);

    int ans1 = a & b;
    int ans2 = a | b;
    int ans3 = a ^ b;
    int ans4 = ~a;
    int ans5 = a << b;
    int ans6 = a >> b;
    int ans7 = ans6 % 2;
    int ans8 = 0;
    while (a)
    {
        ans8 += a & 1;
        a >>= 1;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8);
}