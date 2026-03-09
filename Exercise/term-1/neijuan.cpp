#include <iostream>

int main()
{
    int n = 1;
    int m = 1;
    std::cin >> n >> m;
    int score[n];
    int copy_score[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> score[i];
        copy_score[i] = score[i];
    }
    for (int i = 0; i < m; i++)
    {
        int term = 1;
        std::cin >> term;
        int re_score = 0;
        std::cin >> re_score;
        int idx = term - 1;
        copy_score[idx] = re_score;
        int check = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (copy_score[j] > copy_score[j + 1])
            {
                check = 0;
            }
        }
        if (check)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
}