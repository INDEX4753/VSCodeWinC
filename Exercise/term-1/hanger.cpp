#include <iostream>

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int n = 1,
        m = 1,
        oprt = 1;
    std::cin >> n >> m >> oprt;

    for (int i = 0; i < oprt; i++)
    {
        int op = 0;
        std::cin >> op;

        if (!op)
        {
            int x = 1,
                y = 1;
            std::cin >> x >> y;
        }
        else
        {
            int x = 1;
            std::cin >> x;
        }
    }
}