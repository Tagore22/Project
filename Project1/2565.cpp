/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cashe;
vector<pair<int, int>> board;
int n;

int calcul(int num)
{
    int& ans = cashe[num + 1];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int i = num + 1; i < n; ++i)
        if (num == -1 || (board[num].first > board[i].first && board[num].second > board[i].second) || (board[num].first < board[i].first && board[num].second < board[i].second))
            ans = max(ans, calcul(i) + 1);
    return ans;
}

int dasfasdfmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cashe.assign(n + 1, -1);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        board.push_back(make_pair(a, b));
    }
    sort(board.begin(), board.end());
    cout << n - calcul(-1) + 1 << '\n';
    return 0;
}*/