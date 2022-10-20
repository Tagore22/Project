/*#include <iostream>

using namespace std;

int sdafsdfsmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    int answer = -1001;
    int check = 0;
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        check = check + x <= 0 ? 0 : check + x;
        answer = max(answer, check);
        cout << "check : " << check << " " << "answer : " << answer << '\n';
    }
    cout << answer << '\n';
    return 0;
}*/