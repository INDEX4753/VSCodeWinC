#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SetStackAutomaton
{
private:
    map<set<int>, int> set_id;
    vector<set<int>> id_set;
    stack<int> st;
    bool error_flag;
    int getSetId(const set<int> &s)
    {
        if (set_id.find(s) == set_id.end())
        {
            int new_id = id_set.size();
            set_id[s] = new_id;
            id_set.push_back(s);
        }
        return set_id[s];
    }

public:
    SetStackAutomaton()
    {
        error_flag = false;
        set<int> empty_set;
        set_id[empty_set] = 0;
        id_set.push_back(empty_set);
    }

    bool isError() const
    {
        return error_flag;
    }

    void push()
    {
        if (error_flag)
        {
            return;
        }
        st.push(0);
        cout << id_set[st.top()].size() << endl;
    }

    void dup()
    {
        if (error_flag)
        {
            return;
        }
        if (st.empty())
        {
            error_flag = true;
            cout << "ERROR" << endl;
            return;
        }
        int top_id = st.top();
        st.push(top_id);
        cout << id_set[st.top()].size() << endl;
    }

    void union_()
    {
        if (error_flag)
        {
            return;
        }
        if (st.size() < 2)
        {
            error_flag = true;
            cout << "ERROR" << endl;
            return;
        }

        int a_id = st.top();
        st.pop();
        int b_id = st.top();
        st.pop();
        const set<int> &a_set = id_set[a_id];
        const set<int> &b_set = id_set[b_id];
        set<int> union_set;
        set_union(a_set.begin(), a_set.end(), b_set.begin(), b_set.end(),
                  inserter(union_set, union_set.begin()));

        int union_id = getSetId(union_set);
        st.push(union_id);
        cout << id_set[union_id].size() << endl;
    }

    void intersect()
    {
        if (error_flag)
        {
            return;
        }
        if (st.size() < 2)
        {
            error_flag = true;
            cout << "ERROR" << endl;
            return;
        }

        int a_id = st.top();
        st.pop();
        int b_id = st.top();
        st.pop();
        const set<int> &a_set = id_set[a_id];
        const set<int> &b_set = id_set[b_id];
        set<int> intersect_set;
        set_intersection(a_set.begin(), a_set.end(), b_set.begin(), b_set.end(),
                         inserter(intersect_set, intersect_set.begin()));

        int intersect_id = getSetId(intersect_set);
        st.push(intersect_id);
        cout << id_set[intersect_id].size() << endl;
    }

    void add()
    {
        if (error_flag)
        {
            return;
        }
        if (st.size() < 2)
        {
            error_flag = true;
            cout << "ERROR" << endl;
            return;
        }

        int a_id = st.top();
        st.pop();
        int b_id = st.top();
        st.pop();

        set<int> add_set = id_set[b_id];
        add_set.insert(a_id);

        int add_id = getSetId(add_set);
        st.push(add_id);
        cout << id_set[add_id].size() << endl;
    }
};

int main()
{
    SetStackAutomaton automaton;
    int times;
    cin >> times;

    while (times--)
    {
        if (automaton.isError())
        {
            string temp;
            cin >> temp;
            continue;
        }

        string cmd;
        cin >> cmd;
        if (cmd == "PUSH")
        {
            automaton.push();
        }
        else if (cmd == "DUP")
        {
            automaton.dup();
        }
        else if (cmd == "UNION")
        {
            automaton.union_();
        }
        else if (cmd == "INTERSECT")
        {
            automaton.intersect();
        }
        else if (cmd == "ADD")
        {
            automaton.add();
        }
    }
}