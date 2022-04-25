//문자열이 주어졌을 때, 이 문자열에 같은 문자가 중복되어 등장하는지 확인하는 알고리즘을 작성하라. 자료구조를 추가로 사용하지 않고 풀 수 있는 알고리즘 또한 고민하라.

#include <iostream>
#include <string>

bool ArrayCheckStr(std::string Str)  //BCR Big(N) 실제 Big(N) 공간 Big(N)
{                                  
	const int STRLENGTH = 128;
	if (Str.length() > STRLENGTH)
		return false;
	bool CharStr[STRLENGTH];
	int Index;

	for (int i = 0; i < STRLENGTH; i++)
		CharStr[i] = false;

	for (int i = 0; i < Str.length(); i++)
	{
		Index = Str[i] - 'a';

		if (CharStr[Index])
			return false;

		CharStr[Index] = true;
	}
	return true;
}

bool BitCheckStr(std::string Str) //BCR Big(N) 실제 Big(N) 공간 Big(N)
{
	int sum = 0;
	int bit;

	for (int i = 0; i < Str.length(); i++)
	{
		bit = Str[i] - 'a';
		if ((sum & (1 << bit)) > 0)
			return false;
		sum |= 1 << bit;
	}
	return true;
}

int ex1_1main()
{
	std::string ExStr;

	std::cout << "문자열 입력" << std::endl;
	std::cin >> ExStr;

	if (BitCheckStr(ExStr))
		std::cout << "중복 없음." << std::endl;
	else
		std::cout << "중복 있음." << std::endl;
	return 0;
}