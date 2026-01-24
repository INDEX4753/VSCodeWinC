#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1; // 遇到空格停止
    cin.ignore();

    string s2 = "你好";
    string s3(",");
    string s4("世界！");
    string s5 = s2 + s3 + s4; // 拼接加复制

    cout << s1 << endl;
    cout << s5 << endl;

    string s6;
    getline(cin, s6); // 接收换行为止

    cout << s6 << endl;

    string s7;
    getline(cin, s7, '0'); // 遇到0停止读取
    //------------------------
    auto a = s5.size();
    //------------------------
    auto it1 = s5.begin();
    auto it2 = s5.end();
    for (auto it = it1; it < it2; it++)
    {
        *it = 'x';
    }
    cout << s5 << endl;
}