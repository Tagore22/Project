#include <iostream>
#include <exception>
#include <stdexcept>

void errortest(int a)
{
	switch (a)
	{
	case 1:
	case 2:
		throw int(5);
	case 3:
		std::cout << "Diffrent!" << std::endl;
		[[fallthrough]];
	case 4:
		throw int(7);
	default:
		break;
	}
}

void RuntimeErrortest()
{
	throw std::runtime_error("RunTime Error");
}

int ETmain()
{
	int Error12 = 1;
	int Error34 = 3;
	int nonError = 5;
	try
	{
		errortest(nonError);
		RuntimeErrortest();
	}
	catch (int a)
	{
		std::cerr << "Error! : " << a << std::endl;;
	}
	catch (const std::exception& a)
	{
		std::cerr << "Error! : " << a.what() << std::endl;;
	}
	return 0;
}
//1. 에러 처리 과정에서 throw 되는 객체는 다형성을 사용할 수 있다. 또한, 다형성 사용을 위해 catch구문에서 const 레퍼런스 객체를 사용해야한다.
//2. switch 구문에서 사용하는 fallthrough는 왠지 모르게 자동생성에는 앞에 __가 붙지만 막상 사용할때에는 앞에 __를 지워야 컴파일 에러가 나오지 않는다.