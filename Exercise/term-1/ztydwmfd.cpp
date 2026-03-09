#include <iostream>
#include <string>
#include <vector>
using namespace std;

void restrLen(int a, int b, vector<unsigned long long> &all_lenth)
{
    all_lenth[1] = a;
    all_lenth[2] = b;
    for (int i = 3; i < 36; i++)
    {
        all_lenth[i] = all_lenth[i - 2] + all_lenth[i - 1];
    }
}

char getChar(int n, unsigned long long k, const string &s, const string &t, const vector<unsigned long long> &len)
{
    while (true)
    {
        if (n == 1)
        {
            return s[k - 1];
        }
        if (n == 2)
        {
            return t[k - 1];
        }

        unsigned long long len_n_2 = len[n - 2];
        if (k <= len_n_2)
        {
            n -= 2;
        }
        else
        {
            k -= len_n_2;
            n -= 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string t;
    cin >> s >> t;

    int enquire_times = 1;
    cin >> enquire_times;

    vector<unsigned long long> all_lenth(36);
    unsigned long long a = s.size();
    unsigned long long b = t.size();
    restrLen(a, b, all_lenth);

    for (int i = 0; i < enquire_times; i++)
    {
        int n = 1;
        unsigned long long k = 1;
        cin >> n >> k;

        string result;

        if (k > all_lenth[35])
        {
            cout << "\n";
            continue;
        }

        for (int j = 0; j < 10; j++)
        {
            unsigned long long current_k = k + j;

            if (current_k > all_lenth[n])
            {
                break;
            }

            result += getChar(n, current_k, s, t, all_lenth);
        }
        cout << result << "\n";
    }
}