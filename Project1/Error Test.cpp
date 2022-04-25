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
//1. ���� ó�� �������� throw �Ǵ� ��ü�� �������� ����� �� �ִ�. ����, ������ ����� ���� catch�������� const ���۷��� ��ü�� ����ؾ��Ѵ�.
//2. switch �������� ����ϴ� fallthrough�� ���� �𸣰� �ڵ��������� �տ� __�� ������ ���� ����Ҷ����� �տ� __�� ������ ������ ������ ������ �ʴ´�.