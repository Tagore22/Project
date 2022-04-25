#include <iostream>
#include <utility>
#include <memory>

class MovingTest2
{
private:
	int* mIptr;
public:
	MovingTest2(int a);
	MovingTest2() = default;
	~MovingTest2();
	MovingTest2(MovingTest2&& ins) noexcept;
	MovingTest2& operator=(MovingTest2&& ins) noexcept;
	int* GetPtr() const;
	friend void swap(MovingTest2& ins1, MovingTest2& ins2) noexcept;
};

MovingTest2::MovingTest2(int a) : mIptr(new int(a))
{
};

MovingTest2::~MovingTest2()
{
	delete mIptr;
}

MovingTest2::MovingTest2(MovingTest2&& ins) noexcept : MovingTest2()
{
	swap(*this, ins);
};

MovingTest2& MovingTest2::operator=(MovingTest2&& ins) noexcept
{
	MovingTest2 Mvt(std::move(ins));
	swap(*this, Mvt);
	return *this;
}

void swap(MovingTest2& ins1, MovingTest2& ins2) noexcept
{
	using std::swap;

	swap(ins1.mIptr, ins2.mIptr);
}


int* MovingTest2::GetPtr() const
{
	return mIptr;
}


int DMNmain()
{
	MovingTest2 test1(5);
	MovingTest2 test2 = std::move(test1); //�̵� ������

	//std::cout << *(test1.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test1.GetPtr())
		std::cout << "�̵������ڴ� �Ű������� �ʱ�ȭ��Ų��(�����ʹ� null)" << std::endl;

	MovingTest2 test3(7);
	int* exc = test2.GetPtr();
	test2 = std::move(test3); //�̵� ���� ������

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test3.GetPtr())
		std::cout << "�̵� ���Կ����ڴ� �Ű������� �ʱ�ȭ��Ű��(�����ʹ� null), ������ �����͸� ������Ų��." << std::endl;



	return 0;
}

//1. std::move()�� ���� �������� ���������� ĳ�����һ�, ������ ��ȭ�� ���� �ʴ´�.

//2. ����Ʈ �̵������ڿ� ����Ʈ �̵� ���Կ����ڴ� �Ϲ������Ϳ��� ����� �۵����� �ʴ´�.