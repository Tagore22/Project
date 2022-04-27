#include <iostream>
#include <vector>

using namespace std;

vector<long long> check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    check.assign(m, 0);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
        ++check[sum % m];
    }
    long long answer = 0;
    for (int i = 0; i < m; ++i)
        answer += check[i] * (check[i] - 1) / 2;
    cout << check[0] + answer << '\n';
    return 0;
}