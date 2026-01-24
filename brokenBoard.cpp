#include <iostream>
#include <list>
#include <string>

int main()
{
    std::string input;
    std::cin >> input;
    std::list<char> slip;
    auto poe = slip.end();

    for (char ch : input)
    {
        if (ch == '[')
        {
            poe = slip.begin();
        }
        else if (ch == ']')
        {
            poe = slip.end();
        }
        else
        {
            poe = slip.insert(poe, ch);
            poe++;
        }
    }

    for (char c : slip)
    {
        std::cout << c;
    }
}