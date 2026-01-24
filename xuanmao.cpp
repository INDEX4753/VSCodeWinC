#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;
long long max_sum;
vector<int> v;
vector<long long> pow3;

void backtrack(int index, int selected, long long current_sum)
{
    if (selected == k)
    {
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            return;
        }
    }
    if (index >= n)
    {
        return;
    }

    int remaining = k - selected - 1;
    long long weight = pow3[remaining];
    backtrack(index + 1, selected + 1, current_sum + (long long)v[index] * weight);
    backtrack(index + 1, selected, current_sum);
}

int main()
{
    cin >> n >> k;
    pow3.resize(k + 1);
    pow3[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        pow3[i] = pow3[i - 1] * 3;
    }
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    max_sum = LLONG_MIN;

    backtrack(0, 0, 0);
    cout << max_sum << endl;
}