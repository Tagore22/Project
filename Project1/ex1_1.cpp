//���ڿ��� �־����� ��, �� ���ڿ��� ���� ���ڰ� �ߺ��Ǿ� �����ϴ��� Ȯ���ϴ� �˰����� �ۼ��϶�. �ڷᱸ���� �߰��� ������� �ʰ� Ǯ �� �ִ� �˰��� ���� ����϶�.

#include <iostream>
#include <string>

bool ArrayCheckStr(std::string Str)  //BCR Big(N) ���� Big(N) ���� Big(N)
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

bool BitCheckStr(std::string Str) //BCR Big(N) ���� Big(N) ���� Big(N)
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

	std::cout << "���ڿ� �Է�" << std::endl;
	std::cin >> ExStr;

	if (BitCheckStr(ExStr))
		std::cout << "�ߺ� ����." << std::endl;
	else
		std::cout << "�ߺ� ����." << std::endl;
	return 0;
}