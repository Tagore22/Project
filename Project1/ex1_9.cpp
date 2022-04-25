//�� �ܾ �ٸ� ���ڿ��� ���ԵǾ� �ִ��� �Ǻ��ϴ� isSubstring�̶�� �޼��尡 �ִٰ� ġ��. s1�� s2�� �� ���ڿ��� �־�����, s2�� s1�� ȸ����Ų ������� �Ǻ��ϰ��� �Ѵ�(���� 'waterbottle'��
//'erbottlewat'�� ȸ������ ���� �� �ִ� ���ڿ��̴�). isSubstring �޼��带 �� ���� ȣ���ؼ� �Ǻ��� �� �ִ� �ڵ带 �ۼ��϶�.
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) //n % i == �ε����� ���� ȸ��
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
		cout << "���ڿ��� ȸ���� ����" << endl;
	else
		cout << "���ڿ��� ȸ���� �ƴ�" << endl;

	return 0;
}

