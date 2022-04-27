/*#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> answer;
vector<int> sortList;
queue<int> que;
int n, m;

void calcul()
{
    int idx = -1;
    for (int i = 0; i < n; ++i)
    {
        while (true)
        {
            idx = (idx + 1) % n;
            if (sortList[i] == que.front())
            {
                answer[idx] = i + 1;
                int x = que.front();
                que.pop();
                que.push(x);
                break;
            }
            int x = que.front();
            que.pop();
            que.push(x);
        }
    }
    while (!que.empty())
    {
        que.pop();
    }
}

int sdafsdfsdafmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
    {
        cin >> n >> m;
        sortList.assign(n, 0);
        answer.assign(n, 0);
        for (int j = 0; j < n; ++j)
        {
            cin >> sortList[j];
            que.push(sortList[j]);
        }
        sort(sortList.begin(), sortList.end(), greater<>());
        calcul();
        cout << answer[m] << '\n';
    }

    return 0;
}*/