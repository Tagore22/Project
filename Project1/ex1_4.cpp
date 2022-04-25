//주어진 문자열이 회문(palindrome)의 순열인지 아닌지 확인하는 함수를 작성하라. 회문이란 앞으로 읽으나 뒤로 읽으나 같은 단어 혹은 구절을 의미하며, 순열이란 문자열을 재배치하는 것을 뜻한다.
//회문이 꼭 사전에 등장하는 단어로 제한될 필요는 없다.

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

bool ArrayCheckPalindrome(std::string Str)     // 1. 문자열을 문자 단위로 배열에 삽입. 2. 배열을 돌면서 홀수인 인덱스가 둘 이상인지 확인.
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
				Bit |= mask;         // 처음으로 해당 문자가 들어왔을 때는 | 연산으로 홀수로 만듬.
			else
				Bit &= ~mask;        // 두번째로 해당 문자가 들어왔을 때는 ~해서 & 연산으로 짝수로 만들어 무마시킴.
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

	std::cout << "문자열 입력" << std::endl;
	std::cin >> Str;

	if (BitCheckPalindrome(Str))
		std::cout << "회문의 순열이 맞음" << std::endl;
	else
		std::cout << "회문의 순열이 아님" << std::endl;

	return 0;
}