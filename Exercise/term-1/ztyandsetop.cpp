#include <iostream>
#include <vector>
#include <string>

using namespace std;

using Set = unsigned int;

Set intersect(Set a, Set b)
{
    return a & b;
}

Set unite(Set a, Set b)
{
    return a | b;
}

Set difference(Set a, Set b)
{
    return a & (~b);
}

void printSet(Set s)
{
    vector<int> result;
    for (int i = 0; i < 32; i++)
    {
        if (s & (1U << i))
        {
            result.push_back(i);
        }
    }
    if (result.empty())
    {
        cout << endl;
    }
    else
    {
        for (auto i = 0; i < result.size(); i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << result[i];
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;

    vector<Set> sets(n);

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        cin >> m;
        Set s = 0;
        for (int j = 0; j < m; j++)
        {
            int elem;
            cin >> elem;
            s |= (1U << elem);
        }
        sets[i] = s;
    }

    int q = 1;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x = 1,
            y = 1;
        string op;
        cin >> x >> op >> y;

        Set result;

        if (op == "/\\")
        {
            result = intersect(sets[x], sets[y]);
        }
        else if (op == "\\/")
        {
            result = unite(sets[x], sets[y]);
        }
        else if (op == "-")
        {
            result = difference(sets[x], sets[y]);
        }

        printSet(result);
    }

    return 0;
}