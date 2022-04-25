//�־��� ���ڿ��� ȸ��(palindrome)�� �������� �ƴ��� Ȯ���ϴ� �Լ��� �ۼ��϶�. ȸ���̶� ������ ������ �ڷ� ������ ���� �ܾ� Ȥ�� ������ �ǹ��ϸ�, �����̶� ���ڿ��� ���ġ�ϴ� ���� ���Ѵ�.
//ȸ���� �� ������ �����ϴ� �ܾ�� ���ѵ� �ʿ�� ����.

#include <iostream>
#include <string>

const int RANGE = 'z' - 'a';

int CheckChar(char character)
{
	int First = 'a';
	int Last = 'z';
	int Check = character - 'a';

	return Check >= First && Check <= Last ? Check : -1;
}

int* MakeArray(std::string Str)
{
	int list[RANGE+1];

	for (int i = 0; i < RANGE; i++)
		list[i] = 0;
	
	int result = 0;
	for (int i = 0; i < Str.length(); i++)
	{
		result = CheckChar(Str[i]);
		if (result != -1)
			list[result]++;
	}
	return list;
}

bool ArrayCheckPalindrome(std::string Str)     // 1. ���ڿ��� ���� ������ �迭�� ����. 2. �迭�� ���鼭 Ȧ���� �ε����� �� �̻����� Ȯ��.
{
	int * Checklist = MakeArray(Str);
	bool answer = false;

	for (int i = 0; i < RANGE; i++)
	{
		if (Checklist[i] % 2 == 1)
		{
			if (answer)
				return false;
			answer = true;
		}
	}
	return true;
}

int MakeBit(std::string Str)
{
	int Bit = 0;

	int result = 0;
	int mask = 0;
	for (int i = 0; i < Str.length(); i++)
	{
		result = CheckChar(Str[i]);
		if (result != -1)
		{
			mask = 1 << result;

			if ((Bit & mask) == 0) 
				Bit |= mask;         // ó������ �ش� ���ڰ� ������ ���� | �������� Ȧ���� ����.
			else
				Bit &= ~mask;        // �ι�°�� �ش� ���ڰ� ������ ���� ~�ؼ� & �������� ¦���� ����� ������Ŵ.
		}			
	}
	return Bit;
}

bool BitCheckPalindrome(std::string Str)
{
	int CheckBit = MakeBit(Str);

	return (CheckBit & (CheckBit - 1)) > 0 ? false : true; //000100 - 1 = 000011
}                                                          //000100 & 000011 = 0

int ex1_4main()
{
	std::string Str;

	std::cout << "���ڿ� �Է�" << std::endl;
	std::cin >> Str;

	if (BitCheckPalindrome(Str))
		std::cout << "ȸ���� ������ ����" << std::endl;
	else
		std::cout << "ȸ���� ������ �ƴ�" << std::endl;

	return 0;
}