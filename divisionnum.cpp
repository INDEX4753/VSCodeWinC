#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdint>

std::string transnum(std::uint64_t n, std::uint64_t d);

int main()
{
    std::uint64_t n = 1, d = 1;
    std::cin >> n >> d;
    if (d == 0)
    {
        return -1;
    }
    if (n % d == 0)
    {
        std::cout << n / d << ".0" << std::endl;
    }
    else
    {
        std::cout << transnum(n, d) << std::endl;
    }
}

std::string transnum(std::uint64_t n, std::uint64_t d)
{
    // deal with integer part
    std::string result;
    std::uint64_t integer_part = n / d;
    result += std::to_string(integer_part);

    // add decimal point
    result += '.';

    // deal with num after point
    std::unordered_map<std::uint64_t, int> poslist;
    std::uint64_t pos = n % d;
    while (pos != 0)
    {
        if (poslist.count(pos))
        {
            result.insert(poslist[pos], "(");
            result += ")";
            break;
        }

        poslist[pos] = result.length();

        pos *= 10;

        result += std::to_string(pos / d);

        pos %= d;
    }

    return result;
}