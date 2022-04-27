/*#include <iostream>
#include <stack>

using namespace std;

stack<int> sta;
string str;

void sdafdsSpush(int x)
{
    sta.push(x);
}

void asdfdsSpop()
{
    int x = -1;
    if (!sta.empty())
    {
        x = sta.top();
        sta.pop();
    }
    cout << x << '\n';
}

void sdafSsize()
{
    cout << sta.size() << '\n';
}

void adfdsSempty()
{
    int x = sta.empty() ? 1 : 0;
    cout << x << '\n';
}

void asdfdStop()
{
    int x = -1;
    if (!sta.empty())
        x = sta.top();
    cout << x << '\n';
}


int adsfasdfdsafmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        if (str[0] == 'p' && str[1] == 'u')
        {
            int x;
            cin >> x;
            Spush(x);
        }
        else if (str[0] == 'p' && str[1] == 'o')
            Spop();
        else if (str[0] == 's' && str[1] == 'i')
            Ssize();
        else if (str[0] == 'e' && str[1] == 'm')
            Sempty();
        else
            Stop();
        str.clear();
    }
    return 0;
}*/