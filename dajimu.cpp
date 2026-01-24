#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void hanoi(int n, stack<string> &src, stack<string> &dest, stack<string> &aux, string srcName, string destName, string auxName)
{
    if (n == 1)
    {
        string block = src.top();
        src.pop();
        dest.push(block);
        cout << "Move" << " " << block << " " << "from" << " " << srcName << " " << "to" << " " << destName << "." << endl;
    }
    else
    {
        hanoi(n - 1, src, aux, dest, srcName, auxName, destName);
        hanoi(1, src, dest, aux, srcName, destName, auxName);
        hanoi(n - 1, aux, dest, src, auxName, destName, srcName);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string A_name, B_name, C_name;
    getline(cin, A_name);
    getline(cin, B_name);
    getline(cin, C_name);

    vector<string> blocks;
    for (int i = 0; i < n; i++)
    {
        string block;
        getline(cin, block);
        blocks.push_back(block);
    }

    stack<string> stackA, stackB, stackC;
    for (string block : blocks)
    {
        stackA.push(block);
    }

    hanoi(n, stackA, stackB, stackC, A_name, B_name, C_name);

    return 0;
}