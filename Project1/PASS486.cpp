/*#include <iostream>
#include <vector>

using namespace std;

const int maxNum = 10000000;
vector<int> cashe(maxNum + 1, 0);

void makeCashe()
{
	for (int i = 1; i <= maxNum; ++i)
		for (int j = i; j <= maxNum; j += i)
			++cashe[j];
}


int asdfsafsdafdmain()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	makeCashe();

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int answer = 0;
		for (int j = lo; j <= hi; ++j)
			if (cashe[j] == n)
				++answer;
		cout << answer << '\n';
	}
	return 0;
}*/