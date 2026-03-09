#include <iostream>
#include <cstdint>
#include <cmath>

int main()
{
    int n = 1;
    std::uint64_t k = 1;
    std::uint64_t one = 1;
    std::cin >> n >> k;
    for (int i = n; i > 0; i--)
    {
        std::uint64_t half = one << (i - 1);
        if (k < half)
        {
            std::cout << "0";
        }
        else
        {
            std::cout << "1";
            k = 2 * half - 1 - k;
        }
    }
    std::cout << std::endl;
}
