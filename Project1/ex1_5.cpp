//문자열을 편집하는 방법에는 세 가지 종류가 있다. 문자 삽입, 문자 삭제, 문자 교체. 문자열 두 개가 주어졌을 때, 문자열을 같게 만들기 위한 편집 횟수가 1회 이내인지 확인하는 함수를 작성하라.

#include <iostream>

bool CheckStrEqual(char str1[], char str2[], int StrLength);
bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length);
bool CheckStr(char str1[], char str2[], int Str1Length, int Str2Length);

//BCR = O(A) + 0(B)
// * a-b의 절대값 <= 1
// * a와 b의 차이는 1 -> 크기가 큰 문자열에서 비교해봐야함.

/*bool CheckStr(char str1[], char str2[], int Str1Length, int Str2Length)
{
	if (abs(Str1Length - Str2Length) > 1)
		return false;

	int MaxLength = (Str1Length >= Str2Length ? Str1Length : Str2Length);
	bool CanNot = false;

	for (int i = 0; i < MaxLength; i++)
	{
		if (str1[i] != str2[i])
		{
			if (CanNot)
				return false;

			CanNot = true;
		}
	}
	return true;       /// <------------ ???? 이게 아닌가(--------------------------------------------------------- 틀 림 ------------------------------------------)
}*/

/*bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length) // 문자수가 1개 차이난다. 즉, 나머지가 모두 같아야 나머지 1개를 주어진 편집 횟수로 교정할수 있다(틀림).
{
	int MinLength = (Str1Length < Str2Length ? Str1Length : Str2Length);

	for (int i = 0; i < MinLength; i++)
	{
		if (str1[i] != str2[i])
			return false; --------------------------------------------------------- 틀 림 ------------------------------------------------------
	}
	return true;
}*/

bool CheckStrEqual(char str1[], char str2[], int StrLength) // 문자수가 같다. 즉, 문자의 차이가 1개까지만 허용된다.
{
	bool Cannot = false;

	for (int i = 0; i < StrLength; i++)
	{
		if (str1[i] != str2[i])
		{
			if (Cannot)
				return false;
			Cannot = true;
		}
	}
	return true;
}

bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length) // 문자수가 1개 차이난다. 즉, 어느 한 부분을 기점으로 모든 문자가 차이난다.
{                                                                          // 삽입이라면 짧은 문자열의 문자 하나의 삽입으로 두 문자열은 같아진다. 그러므로, 공간 하나만 넘어가서 비교하면 된다.
	int index1 = 0;
	int	index2 = 0;                                                // 삭제라면 긴 문자열의 문자 하나의 삭제로 두 문자열은 같아진다. 그러므로, 공간 하나만 넘어가서 비교하면 된다.

	while (index1 < Str1Length && index2 < Str2Length)
	{
		if (str1[index1] != str2[index2])
		{
			if (index1 != index2)
				return false;
			index2++;
		}
		else
		{
			index1++;
			index2++;
		}
	}
	return true;
}

bool CheckStr(char str1[], char str2[], int Str1Length, int Str2Length)
{
	if (Str1Length - Str2Length == 0) // 두 문자열이 같을 경우(교체).
		return CheckStrEqual(str1, str2, Str1Length);
	else if (Str1Length - Str2Length == 1)
		return CheckStrOne(str2, str1, Str2Length, Str1Length); // 두 문자열의 차이가 1이고, 첫번째 문자열이 더 길때.
	else if (Str2Length - Str1Length == 1)
		return CheckStrOne(str1, str2, Str1Length, Str2Length);// 두 문자열의 차이가 1이고, 두번째 문자열이 더 길때.
	else
		return false;
}

bool CharReplacement(std::string Str1, std::string Str2)
{
	bool Check = false;

	for (int i = 0; i < Str1.length(); i++)
	{
		if (Str1[i] != Str2[i])
		{
			if (Check)
				return false;
			Check = true;
		}
	}
	return true;
}
bool CharInsertDelete(std::string ShortStr, std::string LongStr)
{
	int ShortIndex = 0;
	int LongIndex = 0;

	while(ShortIndex < ShortStr.length() && LongIndex < LongStr.length()) //중요한 조건식이다. 자꾸 잊어버린다. 주의하자.
	{
		if (ShortStr[ShortIndex] != LongStr[LongIndex])
		{
			if (ShortIndex != LongIndex)
				return false;
			else
				LongIndex++;
		}
		ShortIndex++;
		LongIndex++;
	}
	return true;
}

bool OneEditStr(std::string Str1, std::string Str2)
{
	if (Str1.length() == Str2.length())
		return CharReplacement(Str1, Str2);
	else if (Str1.length() - 1 == Str2.length())
		return CharInsertDelete(Str2, Str1);
	else if (Str2.length() - 1 == Str1.length())
		return CharInsertDelete(Str1, Str2);
	else
		return false;
}

int ex1_5main()
{
	std::string str1;
	std::string str2;
	

	std::cout << "30자 이내의 문자열 2개 입력" << std::endl;
	std::cin >> str1 >> str2;

	if (OneEditStr(str1, str2))
		std::cout << "변환 가능" << std::endl;
	else
		std::cout << "변환 불가" << std::endl;

	return 0;
}