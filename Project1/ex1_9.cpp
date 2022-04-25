//한 단어가 다른 문자열에 포함되어 있는지 판별하는 isSubstring이라는 메서드가 있다고 치자. s1과 s2의 두 문자열이 주어졌고, s2가 s1을 회전시킨 결과인지 판별하고자 한다(가령 'waterbottle'은
//'erbottlewat'을 회전시켜 얻을 수 있는 문자열이다). isSubstring 메서드를 한 번만 호출해서 판별할 수 있는 코드를 작성하라.
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) //n % i == 인덱스의 무한 회전
{
	if (s1.length() != s2.length() || s2.find(s1[0]) == -1)
		return false;

	int index = s2.find(s1[0]) + 1;

	for (int i = 1; i < s1.length(); i++)
	{
		if (s2[index % s2.length()] != s1[i])
			return false;
		index++;
	}

	return true;
}

bool RotationChar(string s1, string s2)
{
	if (s1.length() == s2.length() && s1.length() != 0)
		return isSubstring(s1 + s1, s2);

	return false;
}

int ex1_9main()
{
	string s1 = "aaabbb";
	string s2 = "aabbba";

	if (isSubstring(s1, s2))
		cout << "문자열의 회전이 맞음" << endl;
	else
		cout << "문자열의 회전이 아님" << endl;

	return 0;
}

