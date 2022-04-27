/*#include <iostream>
#include <queue>

using namespace std;

queue<int> que;

int calcul()
{
    while (que.size() != 1)
    {
        que.pop();
        int x = que.front();
        que.pop();
        que.push(x);
    }
    return que.front();
}

int dafsdfdsamain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        que.push(i);
    cout << calcul() << '\n';
    return 0;
}*/