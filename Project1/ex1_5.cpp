//���ڿ��� �����ϴ� ������� �� ���� ������ �ִ�. ���� ����, ���� ����, ���� ��ü. ���ڿ� �� ���� �־����� ��, ���ڿ��� ���� ����� ���� ���� Ƚ���� 1ȸ �̳����� Ȯ���ϴ� �Լ��� �ۼ��϶�.

#include <iostream>

bool CheckStrEqual(char str1[], char str2[], int StrLength);
bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length);
bool CheckStr(char str1[], char str2[], int Str1Length, int Str2Length);

//BCR = O(A) + 0(B)
// * a-b�� ���밪 <= 1
// * a�� b�� ���̴� 1 -> ũ�Ⱑ ū ���ڿ����� ���غ�����.

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
	return true;       /// <------------ ???? �̰� �ƴѰ�(--------------------------------------------------------- Ʋ �� ------------------------------------------)
}*/

/*bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length) // ���ڼ��� 1�� ���̳���. ��, �������� ��� ���ƾ� ������ 1���� �־��� ���� Ƚ���� �����Ҽ� �ִ�(Ʋ��).
{
	int MinLength = (Str1Length < Str2Length ? Str1Length : Str2Length);

	for (int i = 0; i < MinLength; i++)
	{
		if (str1[i] != str2[i])
			return false; --------------------------------------------------------- Ʋ �� ------------------------------------------------------
	}
	return true;
}*/

bool CheckStrEqual(char str1[], char str2[], int StrLength) // ���ڼ��� ����. ��, ������ ���̰� 1�������� ���ȴ�.
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

bool CheckStrOne(char str1[], char str2[], int Str1Length, int Str2Length) // ���ڼ��� 1�� ���̳���. ��, ��� �� �κ��� �������� ��� ���ڰ� ���̳���.
{                                                                          // �����̶�� ª�� ���ڿ��� ���� �ϳ��� �������� �� ���ڿ��� ��������. �׷��Ƿ�, ���� �ϳ��� �Ѿ�� ���ϸ� �ȴ�.
	int index1 = 0;
	int	index2 = 0;                                                // ������� �� ���ڿ��� ���� �ϳ��� ������ �� ���ڿ��� ��������. �׷��Ƿ�, ���� �ϳ��� �Ѿ�� ���ϸ� �ȴ�.

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
	if (Str1Length - Str2Length == 0) // �� ���ڿ��� ���� ���(��ü).
		return CheckStrEqual(str1, str2, Str1Length);
	else if (Str1Length - Str2Length == 1)
		return CheckStrOne(str2, str1, Str2Length, Str1Length); // �� ���ڿ��� ���̰� 1�̰�, ù��° ���ڿ��� �� �涧.
	else if (Str2Length - Str1Length == 1)
		return CheckStrOne(str1, str2, Str1Length, Str2Length);// �� ���ڿ��� ���̰� 1�̰�, �ι�° ���ڿ��� �� �涧.
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

	while(ShortIndex < ShortStr.length() && LongIndex < LongStr.length()) //�߿��� ���ǽ��̴�. �ڲ� �ؾ������. ��������.
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
	

	std::cout << "30�� �̳��� ���ڿ� 2�� �Է�" << std::endl;
	std::cin >> str1 >> str2;

	if (OneEditStr(str1, str2))
		std::cout << "��ȯ ����" << std::endl;
	else
		std::cout << "��ȯ �Ұ�" << std::endl;

	return 0;
}