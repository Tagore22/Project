/*#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> calCashe(500, vector<int>(500, -1));
vector<vector<int>> findCashe(500, vector<int>(500, -1));
vector<vector<int>> board;
int n;

int calculMax(int y, int x)
{
    if (y == n - 1)
        return board[y][x];
    int& ans = calCashe[y][x];
    if (ans != -1)
        return ans;
    ans = max(calculMax(y + 1, x), calculMax(y + 1, x + 1)) + board[y][x];
    cout << "calAnswer is : " << ans << '\n';
    return ans;
}

int findWay(int y, int x)
{
    if (y == n - 1)
        return 1;
    int& ans = findCashe[y][x];
    if (ans != -1)
        return ans;
    ans = 0;
    int calLeft = calculMax(y + 1, x);
    cout << "calLeft : " << calLeft << " ";
    int calRight = calculMax(y + 1, x + 1);
    cout << "calRight : " << calRight << '\n';
    if (calLeft >= calRight)
        ans += findWay(y + 1, x);
    if (calLeft <= calRight)
        ans += findWay(y + 1, x + 1);
    cout << y << ", " << x << "의 최대값 : " << ans << '\n';
    return ans;
}

int mmdafdsfsdafain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> board[i][j];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << board[i][j] << " ";
        cout << '\n';
    }
    cout << calculMax(0, 0) << '\n';
    return 0;
}*/