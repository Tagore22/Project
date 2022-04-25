//반복되는 문자의 개수를 세는 방식의 기본적인 문자열 압축 메서드를 작성하라. 예를 들어 문자열 aabccccaaa를 압축하면 a2b1c5a3이 된다. 만약 '압축된' 문자열의 길이가 기존 문자열의 길이보다
//길다면 기존 문자열을 반환해야 한다. 문자열은 알파벳(a~z)으로만 이루어져 있다.
#include <iostream>
#include <string>

std::string IntToChar(int a) // char* itoa(int value, char* str, int radix) value는 int값, str은 변환될 문자열, radix는 2진수인지, 8진수인지등을 결정한다. value값을 radix진수 문자값으로 변환하여
{                            // str안에 넣어 그 포인터를 반환한다. ex) result = name + itoa(age, numstr, 10); 그밖에 방법들은 크롬에 stackoverflow 북마크를 참조.
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
	Compress.append(&Str[0]); //********************************* 왠지 모르겠는데 매개변수의 타입이 포인터형이다**************************************

	char EqualChar = Str[0];
	int Index = 0;

	for (int i = 0; i < Str.length(); i++)
	{
		/*if (Compress.length() > Str.length())  // 압축된 문자열이 기존의 문자열보다 길어질경우 기존 문자열 반환이 안되고 있음. ----> 해결?
		{                                      // 마지막 인덱스 추가가 잘못되고 있음 ex)a 10개짜리 문자열인데도 a11로 반환됨. ----> 해결?
			Compress = Str;                    // int에서 char로 변경될때 순서가 거꾸로 바뀌고 있음. ex) 100 -> 001. ----> 해결?
			return Compress;
		}*/
		if (Str[i] != EqualChar)
		{
			Compress.append(to_string(Index));  // to_string 함수 이거 실화냐 ㅡㅡ
			Compress.append(&Str[i]); // Compress += std::to_string(Index) + Str[i]; 에서 리팩토링했다. 기존의 +=  연산은 Compress에 Index의 변환형을 덧붙이는게 아니라 
			EqualChar = Str[i];                      // 새로운 문자열을 생성하여 Compress와 Index의 변환형을 모두 복사하는 연산이기 때문에 Big(o)의 시간효율이 좋지 않다.
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
	char pivot = Str[0]; //************************** String에서는 char를 받아들이지 못하지만 char에서는 string의 원소값을 그대로 받아 들일수 있다. ************************************
	int Num = 0;

	Exchan.append(Str, 0, 1); // ************************************************************** string.append(string &str, int begin, int end) str의 begin부터 end전까지 덧붙인다.

	for (int i = 0; i < Str.length(); i++)
	{
		if (pivot != Str[i])
		{
			pivot = Str[i];
			Exchan.append(to_string(Num));
			Exchan.append(1, pivot); //*************************************************************** string.append(int num, char c) string의 끝자락에 num만큼 c를 덧붙인다. 
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

int ex1_6main()  //STL 공부 해야겠당
{
	std::string ExStr;

	std::cout << "압축할 문자열 입력" << std::endl;
	std::cin >> ExStr;

	ExStr = CompareChar(ExStr);

	std::cout << "압축된 문자열 : " << ExStr << std::endl;

	return 0;
}