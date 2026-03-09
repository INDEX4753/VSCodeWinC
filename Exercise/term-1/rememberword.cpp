#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>

struct word
{
    int enter_time;
    int id;
};

int main()
{
    int n = 1,
        m = 1;
    std::cin >> n >> m;
    std::vector<int> seq(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> seq[i];
    }
    std::vector<int> ans(n + 1, 0);
    std::deque<word> dq;
    std::unordered_set<int> pre;

    for (int i = 0; i < n; i++)
    {
        int id_of_word = seq[i];
        if (pre.find(id_of_word) != pre.end())
        {
            continue;
        }
        if (dq.size() == m)
        {
            word front = dq.front();
            dq.pop_front();
            pre.erase(front.id);
            ans[front.id] += i + 1 - front.enter_time;
        }
        dq.push_back({i + 1, id_of_word});
        pre.insert(id_of_word);
    }

    int hoi_time = n + 1;
    while (!dq.empty())
    {
        word now = dq.front();
        dq.pop_front();
        ans[now.id] += n + 1 - now.enter_time;
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
        {
            std::cout << i << " " << ans[i] << std::endl;
        }
    }
}