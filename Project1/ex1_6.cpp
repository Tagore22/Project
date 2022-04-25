//�ݺ��Ǵ� ������ ������ ���� ����� �⺻���� ���ڿ� ���� �޼��带 �ۼ��϶�. ���� ��� ���ڿ� aabccccaaa�� �����ϸ� a2b1c5a3�� �ȴ�. ���� '�����' ���ڿ��� ���̰� ���� ���ڿ��� ���̺���
//��ٸ� ���� ���ڿ��� ��ȯ�ؾ� �Ѵ�. ���ڿ��� ���ĺ�(a~z)���θ� �̷���� �ִ�.
#include <iostream>
#include <string>

std::string IntToChar(int a) // char* itoa(int value, char* str, int radix) value�� int��, str�� ��ȯ�� ���ڿ�, radix�� 2��������, 8������������ �����Ѵ�. value���� radix���� ���ڰ����� ��ȯ�Ͽ�
{                            // str�ȿ� �־� �� �����͸� ��ȯ�Ѵ�. ex) result = name + itoa(age, numstr, 10); �׹ۿ� ������� ũ�ҿ� stackoverflow �ϸ�ũ�� ����.
	const int MAKECHAR = 48;
	std::string IntToChar;
	int Reminder = 0;

	while (a > 0)
	{
		Reminder = a % 10;
		a /= 10;
		IntToChar += static_cast<char>(Reminder + MAKECHAR);
	}

	char temp;

	for (int i = 0; i < IntToChar.length() / 2; i++)
	{
		temp = IntToChar[i];
		IntToChar[i] = IntToChar[IntToChar.length() - 1 - i];
		IntToChar[IntToChar.length() - 1 - i] = temp;
	}

	return IntToChar;
}

std::string ChangeStr(std::string Str)
{
	using namespace std;
	string Compress;
	Compress.append(&Str[0]); //********************************* ���� �𸣰ڴµ� �Ű������� Ÿ���� ���������̴�**************************************

	char EqualChar = Str[0];
	int Index = 0;

	for (int i = 0; i < Str.length(); i++)
	{
		/*if (Compress.length() > Str.length())  // ����� ���ڿ��� ������ ���ڿ����� �������� ���� ���ڿ� ��ȯ�� �ȵǰ� ����. ----> �ذ�?
		{                                      // ������ �ε��� �߰��� �߸��ǰ� ���� ex)a 10��¥�� ���ڿ��ε��� a11�� ��ȯ��. ----> �ذ�?
			Compress = Str;                    // int���� char�� ����ɶ� ������ �Ųٷ� �ٲ�� ����. ex) 100 -> 001. ----> �ذ�?
			return Compress;
		}*/
		if (Str[i] != EqualChar)
		{
			Compress.append(to_string(Index));  // to_string �Լ� �̰� ��ȭ�� �Ѥ�
			Compress.append(&Str[i]); // Compress += std::to_string(Index) + Str[i]; ���� �����丵�ߴ�. ������ +=  ������ Compress�� Index�� ��ȯ���� �����̴°� �ƴ϶� 
			EqualChar = Str[i];                      // ���ο� ���ڿ��� �����Ͽ� Compress�� Index�� ��ȯ���� ��� �����ϴ� �����̱� ������ Big(o)�� �ð�ȿ���� ���� �ʴ�.
			Index = 1;
			continue;
		}
		Index++;
	}

	Compress.append(std::to_string(Index));

	return Compress.length() > Str.length() ? Str : Compress;
}


std::string Compress(std::string Str)
{
	using namespace std;
	
	string Exchan;
	char pivot = Str[0]; //************************** String������ char�� �޾Ƶ����� �������� char������ string�� ���Ұ��� �״�� �޾� ���ϼ� �ִ�. ************************************
	int Num = 0;

	Exchan.append(Str, 0, 1); // ************************************************************** string.append(string &str, int begin, int end) str�� begin���� end������ �����δ�.

	for (int i = 0; i < Str.length(); i++)
	{
		if (pivot != Str[i])
		{
			pivot = Str[i];
			Exchan.append(to_string(Num));
			Exchan.append(1, pivot); //*************************************************************** string.append(int num, char c) string�� ���ڶ��� num��ŭ c�� �����δ�. 
			Num = 1;
		}
		else
		{
			Num++;
		}
	}
	Exchan.append(to_string(Num));
	return Exchan;
}

std::string CompareChar(std::string Str)          
{
	std::string Compression = Compress(Str);

	return Compression.length() > Str.length() ? Str : Compression;
}

int ex1_6main()  //STL ���� �ؾ߰ڴ�
{
	std::string ExStr;

	std::cout << "������ ���ڿ� �Է�" << std::endl;
	std::cin >> ExStr;

	ExStr = CompareChar(ExStr);

	std::cout << "����� ���ڿ� : " << ExStr << std::endl;

	return 0;
}