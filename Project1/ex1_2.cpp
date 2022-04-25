//문자열 두 개가 주어졌을 때 이 둘이 서로 순열 관계에 있는지 확인하는 메서드를 작성하라.

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

	std::cout << "두개의 문자열 입력" << std::endl;
	std::cin >> Str1 >> Str2;

	if (SortPermutation(Str1, Str2))
		std::cout << "순열이 맞음." << std::endl;
	else
		std::cout << "순열이 아님." << std::endl;
	return 0;
}