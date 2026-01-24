#include <iostream>
#include <cmath>
using namespace std;

const int MAX_X = 1e6 + 10;
long long memo[MAX_X];

long long f(long long x, int k)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < MAX_X && memo[x] != -1)
    {
        return memo[x];
    }
    long long sqrt_x = (long long)sqrt(x);
    long long a = sqrt_x / k;
    long long b = sqrt_x / (2 * k);
    long long x2 = x / 2;

    long long res = f(a, k) + f(b, k) + x2;

    if (x < MAX_X)
    {
        memo[x] = res;
    }
    return res;
}

int main()
{
    for (int i = 0; i < MAX_X; ++i)
    {
        memo[i] = -1;
    }

    long long n;
    int k;
    cin >> n >> k;
    cout << f(n, k) << endl;

    return 0;
}