#include <iostream>
#include <stack>
#include <string>

using namespace std;

string check1 = "([";
string check2 = ")]";

bool calcul(string& str)
{
    stack<char> sta;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == check1[0] || str[i] == check1[1])
        {
            sta.push(str[i]);
        }
        else if (str[i] == check2[0] || str[i] == check2[1])
        {
            if (sta.empty())
            {
                return false;
            }
            else
            {
                char now = sta.top();
                if (check1.find(now) != check2.find(str[i]))
                    return false;
                sta.pop();
            }
        }
    }
    return sta.empty() ? true : false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string str;
        getline(cin, str);
        if (str.size() == 1 && str[0] == '.')
            break;
        string answer = calcul(str) ? "yes" : "no";
        cout << answer << '\n';
    }
    return 0;
}*/