//
// Created by abyssovo on 2025/11/7.
//
#include <iostream>
using namespace std;

int main()
{
    bool b = true;
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        b = true;
    }
    else
    {
        b = false;
    }
    cout << b << endl;
    return 0;
}