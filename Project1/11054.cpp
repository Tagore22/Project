#include <iostream>
#include <vector>

using namespace std;

vector<int> board;
vector<vector<int>> cashe;
int n;

int calcul(int now, int isUp)
{
    int& ans = cashe[now + 1][isUp];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int i = now + 1; i < n; ++i)
    {
        if (now == -1 || board[now] < board[i])
            if (now == -1 || isUp)
                ans = max(ans, calcul(i, 1) + 1);
        if (now == -1 || board[now] > board[i])
            ans = max(ans, calcul(i, 0) + 1);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, 0);
    cashe.assign(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cout << calcul(-1, 0) - 1 << '\n';
    return 0;
}