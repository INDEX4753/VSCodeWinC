#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }

    for (int e : vec)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    for (int &e : vec)
    {
        e = 1;
    }

    for (int e : vec)
    {
        std::cout << e << " ";
    }

    std::cout << std::endl;
}