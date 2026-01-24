//---------------------------------------------------------------------------------------------------------------
//  This is a program which takes an integer as input and returns the sum of each individual digit in the integer.
//  (e.g. 357 = 3 + 5 + 7 = 15).
//  Print the answer for input 93427 (which is 25).
//  Assume the input values are positive.
//  Author: Liu Zehao
//---------------------------------------------------------------------------------------------------------------
#include <iostream>
//---------------------------------------------------------------------------------------------------------------
int digsum(int n)
{
    if (n % 10 == n)
        return n;
    return digsum(n / 10) + n % 10;
}
//---------------------------------------------------------------------------------------------------------------
int main()
{
    int n, sum = 0;
    std::cin >> n;
    std::cout << digsum(n) << "\n";
}