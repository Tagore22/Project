#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> check;
stack<int> board;
string answer = "";

bool calcul()
{
    stack<int> sta;
    for (int i = 0; i < check.size(); ++i)
    {
        while (true)
        {
            if (sta.empty() || sta.top() != check[i])
            {
                if (board.empty())
                {
                    return false;
                }
                else
                {
                    int x = board.top();
                    board.pop();
                    sta.push(x);
                    answer += "+";
                }
            }
            else if (sta.top() == check[i])
            {
                sta.pop();
                answer += "-";
                break;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    check.assign(n, 0);
    for (int i = n; i >= 1; --i)
        board.push(i);
    for (int i = 0; i < n; ++i)
        cin >> check[i];
    if (calcul())
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}