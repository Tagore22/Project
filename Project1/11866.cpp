#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
int n, k;

void calcul()
{
    while (que.size() != 1)
    {
        for (int i = 0; i < k - 1; ++i)
        {
            int x = que.front();
            que.pop();
            que.push(x);
        }
        int x = que.front();
        que.pop();
        cout << x << ", ";
    }
    cout << que.front();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        que.push(i);
    cout << "<";
    calcul();
    cout << ">" << '\n';
    return 0;
}