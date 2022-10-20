#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int N;

void MakeAnswer()
{
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] |= board[i][k] & board[k][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}