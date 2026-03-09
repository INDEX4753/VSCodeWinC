#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_result = INT_MAX;

void backtrack(vector<int> current, int step, const vector<char> &ops)
{

    if (step == 3)
    {
        if (current[0] < min_result)
        {
            min_result = current[0];
        }
        return;
    }

    char op = ops[step];
    int n = current.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {

            int res;
            if (op == '+')
            {
                res = current[i] + current[j];
            }
            else
            {
                res = current[i] * current[j];
            }

            vector<int> new_current;
            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                {
                    new_current.push_back(current[k]);
                }
            }
            new_current.push_back(res);
            backtrack(new_current, step + 1, ops);
        }
    }
}

int main()
{
    vector<int> nums(4);
    vector<char> ops(3);

    for (int i = 0; i < 4; ++i)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        cin >> ops[i];
    }

    backtrack(nums, 0, ops);

    cout << min_result << endl;

    return 0;
}