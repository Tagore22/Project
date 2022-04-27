#include <iostream>
#include <deque>

using namespace std;

deque<int> deq;

void Dpush_front(int x)
{
    deq.push_front(x);
}

void Dpush_back(int x)
{
    deq.push_back(x);
}

void Dpop_front()
{
    int x = deq.empty() ? -1 : deq.front();
    if (!deq.empty())
        deq.pop_front();
    cout << x << '\n';
}

void Dpop_back()
{
    int x = deq.empty() ? -1 : deq.back();
    if (!deq.empty())
        deq.pop_back();
    cout << x << '\n';
}

void Dsize()
{
    cout << deq.size() << '\n';
}

void Dempty()
{
    int x = deq.empty() ? 1 : 0;
    cout << x << '\n';
}

void Dfront()
{
    int x = deq.empty() ? -1 : deq.front();
    cout << x << '\n';
}

void Dback()
{
    int x = deq.empty() ? -1 : deq.back();
    cout << x << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (str == "push_back")
        {
            int x;
            cin >> x;
            Dpush_back(x);
        }
        else if (str == "push_front")
        {
            int x;
            cin >> x;
            Dpush_front(x);
        }
        else if (str == "pop_front")
            Dpop_front();
        else if (str == "pop_back")
            Dpop_back();
        else if (str == "size")
            Dsize();
        else if (str == "empty")
            Dempty();
        else if (str == "front")
            Dfront();
        else
            Dback();
    }
    return 0;
}