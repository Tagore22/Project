/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

string strA, strB;
vector<vector<int>> cashe;

int calcul(int a, int b)
{
    if (a >= strA.size())
        return 0;
    int& ans = cashe[a][b + 1];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = b + 1; i < strB.size(); ++i)
        if (strA[a] == strB[i])
            ans = max(ans, calcul(a + 1, i) + 1);
    ans = max(ans, calcul(a + 1, b));
    return ans;
}

int asdsadsadn()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> strA >> strB;
    cashe.assign(strA.size(), vector<int>(strB.size() + 1, -1));
    int answer = 0;
    for (int i = 0; i < strA.size(); ++i)
        answer = max(answer, calcul(i, -1));
    cout << answer << '\n';
    return 0;
}*/