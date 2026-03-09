#include <iostream>
#include <vector>
using namespace std;

struct Operation
{
    int op;
    long long t;
    int item_id;
};

int main()
{
    long long N = 0, M = 0, T = 0;
    cin >> N >> M >> T;
    vector<long long> Time(N + 1, 0);
    vector<long long> last_start(N + 1, 0);
    vector<int> waiting;
    vector<bool> in_waiting(N + 1, false);
    vector<Operation> operations(M);

    for (int i = 0; i < M; i++)
    {
        cin >> operations[i].op >> operations[i].t;
        if (operations[i].op == 0)
        {
            cin >> operations[i].item_id;
        }
        else
        {
            operations[i].item_id = 0;
        }
    }

    for (const auto &op_k : operations)
    {
        long long t_k = op_k.t;
        int item = op_k.item_id;

        for (int i = 1; i <= N; i++)
        {
            if (Time[i] == 0 && !in_waiting[i])
            {
                if (last_start[i] + T <= t_k)
                {
                    Time[i] = last_start[i] + T;
                }
            }
        }

        if (op_k.op == 0)
        {

            if (Time[item] == 0 && !in_waiting[item])
            {
                waiting.push_back(item);
                in_waiting[item] = true;
            }
        }
        else
        {
            if (!waiting.empty())
            {
                long long new_start = t_k;
                for (int id : waiting)
                {
                    last_start[id] = new_start;
                    in_waiting[id] = false;
                }
                waiting.clear();
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (Time[i] == 0)
        {
            Time[i] = last_start[i] + T;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << Time[i] << " ";
    }
    cout << endl;

    return 0;
}