#include <iostream>
#include <string>
#include <stack>
#include <utility>

char shiftCipherChar(char ch, int k)
{
    int offset = ch - 'a';
    int new_offset = (offset + k) % 26;
    return (char)('a' + new_offset);
}

std::string recurCipherOptimized(const std::string &s)
{
    int L = s.length();
    if (L == 0)
    {
        return "";
    }

    std::string result = s;
    std::stack<std::pair<int, int>> subproblems;
    subproblems.push({0, L - 1});

    while (!subproblems.empty())
    {
        auto range = subproblems.top();
        subproblems.pop();

        int start = range.first;
        int end = range.second;
        int current_len = end - start + 1;

        if (current_len <= 0)
        {
            continue;
        }

        if (current_len == 1)
        {
            result[start] = shiftCipherChar(result[start], 1);
            continue;
        }

        int mid_idx = start + current_len / 2;
        int right_start = mid_idx;
        int right_end = end;

        int l_right = right_end - right_start + 1;

        for (int i = right_start; i <= right_end; i++)
        {
            result[i] = shiftCipherChar(result[i], l_right);
        }

        int left_start = start;
        int left_end = mid_idx - 1;

        if (left_end >= left_start)
        {
            subproblems.push({left_start, left_end});
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::string encoded_ch = recurCipherOptimized(s);
    std::cout << encoded_ch << std::endl;
}