#include <iostream>
#include <stack>

using namespace std;

stack<int> sta;

int adfasdfsdafmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, x;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> x;
        if (x != 0)
            sta.push(x);
        else
            sta.pop();
    }
    int answer = 0;
    while (!sta.empty())
    {
        int x = sta.top();
        sta.pop();
        answer += x;
    }
    cout << answer << '\n';
    return 0;
}