/* #include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int n = 1;
    cin >> n;

    map<string, pair<int, int>> mat_info;
    for (int i = 0; i < n; i++)
    {
        string name;
        int r = 1,
            l = 1;
        cin >> name >> r >> l;
        mat_info[name] = {r, l};
    }

    int m = 1;
    cin >> m;

    while (m--)
    {
        string exp;
        cin >> exp;

        stack<pair<int, int>> unused_mats;
        int all_mul = 0;
        bool is_error = false;

        for (char ch : exp)
        {
            if (isalpha(ch))
            {
                string mat_name(1, ch);
                unused_mats.push(mat_info[mat_name]);
            }

            else if (ch == ')')
            {
                if (unused_mats.size() < 2)
                {
                    continue;
                }

                pair<int, int> mat_r = unused_mats.top();
                unused_mats.pop();
                pair<int, int> mat_l = unused_mats.top();
                unused_mats.pop();

                if (mat_l.second != mat_r.first)
                {
                    is_error = true;
                    break;
                }

                all_mul += mat_l.first * mat_l.second * mat_r.second;

                pair<int, int> res_mat = {mat_l.first, mat_r.second};
                unused_mats.push(res_mat);
            }
        }

        cout << (is_error ? "error" : to_string(all_mul)) << endl;
    }
} */

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    map<string, pair<int, int>> mat_info;
    for (int i = 0; i < n; i++)
    {
        string name;
        int r, c;
        cin >> name >> r >> c;
        mat_info[name] = {r, c};
    }

    cin >> m;
    while (m--)
    {
        string exp;
        cin >> exp;

        stack<pair<int, int>> unused_mats;
        int all_mul = 0;
        bool is_error = false;

        for (int i = 0; i < exp.size(); i++)
        {
            char ch = exp[i];

            if (isalpha(ch))
            { // 矩阵字母
                string mat_name(1, ch);
                unused_mats.push(mat_info[mat_name]);
            }
            else if (ch == ')')
            { // 处理合并矩阵
                if (unused_mats.size() < 2)
                {
                    is_error = true;
                    break;
                }

                pair<int, int> mat_r = unused_mats.top();
                unused_mats.pop();
                pair<int, int> mat_l = unused_mats.top();
                unused_mats.pop();

                if (mat_l.second != mat_r.first)
                {
                    is_error = true;
                    break;
                }

                all_mul += mat_l.first * mat_l.second * mat_r.second;
                pair<int, int> res_mat = {mat_l.first, mat_r.second};
                unused_mats.push(res_mat);
            }
        }

        cout << (is_error ? "error" : to_string(all_mul)) << endl;
    }

    return 0;
}
