#include <iostream>
#include <utility>
#include <vector>

class MovingTest3
{
private:
	std::vector<int> mIptr;
public:
	MovingTest3(int a = 0);
	int operator[](int a) const;
	std::vector<int>& GetVector();
};

MovingTest3::MovingTest3(int a)
{
	mIptr.push_back(a);
};

int MovingTest3::operator[](int a) const
{
	return mIptr[a];
}

std::vector<int>& MovingTest3::GetVector()
{
	return mIptr;
}


int DMCmain()
{
	MovingTest3 test1(5);
	MovingTest3 test2 = std::move(test1); //�̵� ������

	//std::cout << test1[0] << std::endl;
	std::cout << test2[0] << std::endl;

	if (test1.GetVector().size() == 0)
		std::cout << "�̵������ڴ� �Ű������� �ʱ�ȭ��Ų��(�����ʹ� null)" << std::endl;

	MovingTest3 test3(7);
	//int* exc = test2.GetPtr();
	test2 = std::move(test3); //�̵� ���� ������

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << test2[0] << std::endl;

	if (test3.GetVector().size() == 0)
		std::cout << "�̵� ���Կ����ڴ� �Ű������� �ʱ�ȭ��Ű��(�����ʹ� null), ������ �����͸� ������Ų��." << std::endl;



	return 0;
}
//1. std::move()�� ���� �������� ���������� ĳ�����һ�, ������ ��ȭ�� ���� �ʴ´�.

//2. ����Ʈ �̵������ڿ� ����Ʈ �̵� ���Կ����ڴ� ��������� ���͸� ����� STL �����̳��� ���, �Ű������� �ʱ�ȭ ��Ų��. (�������� ���� null)