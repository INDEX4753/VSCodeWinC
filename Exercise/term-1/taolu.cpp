#include <cstdio>
#include <vector>
#include <cstdint>
#include <string>
int main()
{
    int n = 0,
        k = 1,
        d = 0;
    scanf("%d %d %d", &n, &k, &d);

    int p = n % k;

    std::vector<std::string> dnum;

    int max_len = 1;
    for (int i = 0; i < n; i++)
    {
        char buf[65];
        scanf(" %s", buf);
        std::string s = buf;
        dnum.push_back(s);
        int len = s.size();
        max_len = (max_len <= len) ? len : max_len;
    }

    for (int i = 0; i < n; i++)
    {
        auto str_len = dnum[i].size();
        int need_len = (max_len - str_len);
        if (need_len)
        {
            char stuffin = '0';
            std::string ori = dnum[i];
            dnum[i] = std::string(need_len, stuffin) + ori;
        }
    }

    std::vector<std::vector<int>> cnt(max_len, std::vector<int>(d, 0));
    for (const std::string &s : dnum)
    {
        for (int pos = 0; pos < max_len; pos++)
        {
            char ch = s[pos];
            int chint = ch - '0';
            cnt[pos][chint]++;
        }
    }

    std::string result;
    bool lead_zero = true;
    for (int pos = 0; pos < max_len; pos++)
    {
        for (int dig = 0; dig < d; dig++)
        {
            if (cnt[pos][dig] % k == p)
            {
                if (lead_zero && dig == 0)
                    continue;
                lead_zero = false;
                result += (char)(dig + '0');
                break;
            }
        }
    }

    printf("%s", result.c_str());
}