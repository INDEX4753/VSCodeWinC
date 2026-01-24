#include <iostream>

int main()
{
    int n = 1;
    int m = 1;
    std::cin >> n >> m;
    int score[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> score[i];
    }

    int down_num = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (score[i] > score[i + 1])
        {
            down_num++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int term = 1;
        std::cin >> term;
        int re_score = 0;
        std::cin >> re_score;
        int idx = term - 1;
        int old_score = score[idx];

        if (idx > 0 && score[idx - 1] > old_score)
            down_num--;
        if (idx < n - 1 && old_score > score[idx + 1])
            down_num--;

        score[idx] = re_score;

        if (idx > 0 && score[idx - 1] > re_score)
            down_num++;
        if (idx < n - 1 && re_score > score[idx + 1])
            down_num++;

        if (!down_num)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
}