#include <iostream>

long long factial(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    return factial(n - 1) * n;
}

int main()
{

    int n = 1;
    std::cin >> n;
    for (int i = 0; i <= n; i++)
    {
        std::cout << factial(i) << "\n";
    }
}