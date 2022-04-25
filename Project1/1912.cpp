/*#include <iostream>

using namespace std;

int sadsadsadsadsadsadmain()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int answer = -1001;
    int check = 0;
    for (int i = 0; i < n; ++i)
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