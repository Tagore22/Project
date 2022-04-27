#include <iostream>
#include <queue>

using namespace std;

queue<int> que;

void Qpush(int n)
{
    que.push(n);
}

void Qpop()
{
    int x = que.empty() ? -1 : que.front();
    if (!que.empty())
        que.pop();
    cout << x << '\n';
}

void Qsize()
{
    cout << que.size() << '\n';
}

void Qempty()
{
    int x = que.empty() ? 1 : 0;
    cout << x << '\n';
}

void Qfront()
{
    int x = que.empty() ? -1 : que.front();
    cout << x << '\n';
}

void Qback()
{
    int x = que.empty() ? -1 : que.back();
    cout << x << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (str[0] == 'p' && str[1] == 'u')
        {
            int x;
            cin >> x;
            Qpush(x);
        }
        else if (str[0] == 'p' && str[1] == 'o')
            Qpop();
        else if (str[0] == 's' && str[1] == 'i')
            Qsize();
        else if (str[0] == 'e' && str[1] == 'm')
            Qempty();
        else if (str[0] == 'f' && str[1] == 'r')
            Qfront();
        else
            Qback();
    }
    return 0;
}