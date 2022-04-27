#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> deq;
string func;
int n;

void calcul()
{
    bool checkR = false;
    for (int i = 0; i < func.size(); ++i)
    {
        if (func[i] == 'R')
        {
            checkR = !checkR;
        }
        else
        {
            if (deq.empty())
            {
                cout << "error" << '\n';
                return;
            }
            else
            {
                if (!checkR)
                    deq.pop_front();
                else
                    deq.pop_back();
            }
        }
    }
    cout << '[';
    while (deq.size() > 1)
    {
        if (!checkR)
        {
            int x = deq.front();
            deq.pop_front();
            cout << x << ',';
        }
        else
        {
            int x = deq.back();
            deq.pop_back();
            cout << x << ',';
        }
    }
    if (deq.size() == 1)
        cout << deq.front();
    cout << ']' << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        while (!deq.empty())
        {
            deq.pop_front();
        }
        cin >> func;
        cin >> n;
        string str;
        cin >> str;
        int now = -1;
        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] >= '0' && str[j] <= '9')
            {
                now = now == -1 ? str[j] - '0' : now * 10 + (str[j] - '0');
            }
            else
            {
                if (now != -1)
                    deq.push_back(now);
                now = -1;
            }
        }
        calcul();
    }
    return 0;
}