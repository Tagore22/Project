#include <iostream>
#include <memory>
#include <utility>


class MovingTest
{
private:
	std::unique_ptr<int> mIptr;
public:
	MovingTest(int a = 0);
	int* GetPtr() const;
};

MovingTest::MovingTest(int a) : mIptr(std::make_unique<int>(a))
{
};

int* MovingTest::GetPtr() const
{
	return mIptr.get();
}


int DMSmain()
{
	MovingTest test1(5);
	MovingTest test2 = std::move(test1); //�̵� ������

	//std::cout << *(test1.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test1.GetPtr())
		std::cout << "�̵������ڴ� �Ű������� �ʱ�ȭ��Ų��. (�����ʹ� null)" << std::endl;

	MovingTest test3(7);
	test2 = std::move(test3); //�̵� ���� ������

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test3.GetPtr())
		std::cout << "�̵� ���Կ����ڴ� �Ű������� �ʱ�ȭ��Ų��. (�����ʹ� null)" << std::endl;


	return 0;
}

//1. std::move()�� ���� �������� ���������� ĳ�����һ�, ������ ��ȭ�� ���� �ʴ´�.

//2. ����Ʈ �̵������ڿ� ����Ʈ �̵� ���Կ����ڴ� ��������� ����Ʈ�������� ���, �Ű������� �ʱ�ȭ ��Ų��. (�������� ���� null)