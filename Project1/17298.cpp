#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> check;
vector<int> answer;

void calcul()
{
    stack<int> sta;
    for (int i = check.size() - 1; i >= 0; --i)
    {
        while (!sta.empty() && sta.top() <= check[i])
            sta.pop();
        if (sta.empty())
            answer[i] = -1;
        else
            answer[i] = sta.top();
        sta.push(check[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    check.assign(n, 0);
    answer.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> check[i];
    calcul();
    for (int i = 0; i < n; ++i)
        cout << answer[i] << " ";
    cout << '\n';
    return 0;
}