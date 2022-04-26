#include <iostream>
#include <stack>

using namespace std;

bool calcul(string& str)
{
    stack<char> sta;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            sta.push(str[i]);
        }
        else
        {
            if (sta.empty())
                return false;
            sta.pop();
        }
    }
    return sta.empty() ? true : false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string str;
        cin >> str;
        string answer = calcul(str) ? "YES" : "NO";
        cout << answer << '\n';
    }
    return 0;
}