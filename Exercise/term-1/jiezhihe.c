#include <stdio.h>

int main()
{
    const int MOD = 10007;
    int n;
    scanf("%d", &n);
    long long n_j_m = 1, sum = 0;
  
    for(int i = 1; i <= n; i++)
    {
        n_j_m = (n_j_m * i) % MOD;
        sum = (sum + n_j_m) % MOD;
    }

    printf("%lld", sum);
    return 0;
}