#include <iostream>
#include <cmath>

using namespace std;

const int multiNum = 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int answer = 0;
    for (int i = 0; i < multiNum; ++i)
    {
        int x = str[i] - '0';
        answer += pow(x, multiNum);
    }
    cout << answer << '\n';
    return 0;
}