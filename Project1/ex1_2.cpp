//���ڿ� �� ���� �־����� �� �� ���� ���� ���� ���迡 �ִ��� Ȯ���ϴ� �޼��带 �ۼ��϶�.

#include <iostream>
#include <string>
#include <algorithm>

bool ArrayPermutation(std::string Str1, std::string Str2)
{
	if (Str1.length() != Str2.length())
		return false;
	const int StrLength = 128;
	int StrArray[StrLength];

	for (int i = 0; i < StrLength; i++)
		StrArray[i] = 0;

	for (int i = 0; i < Str1.length(); i++)
		StrArray[Str1[i]]++;
	for (int i = 0; i < Str2.length(); i++)
		StrArray[Str2[i]]--;
	for (int i = 0; i < StrLength; i++)
	{
		if (StrArray[i] != 0)
			return false;
	}
	return true;
}

bool SortPermutation(std::string Str1, std::string Str2)
{
	if (Str1.length() != Str2.length())
		return false;
	std::sort(Str1.begin(), Str1.end());
	std::sort(Str2.begin(), Str2.end());

	return Str1 == Str2 ? true : false;
}


int ex1_2main()
{
	std::string Str1, Str2;

	std::cout << "�ΰ��� ���ڿ� �Է�" << std::endl;
	std::cin >> Str1 >> Str2;

	if (SortPermutation(Str1, Str2))
		std::cout << "������ ����." << std::endl;
	else
		std::cout << "������ �ƴ�." << std::endl;
	return 0;
}