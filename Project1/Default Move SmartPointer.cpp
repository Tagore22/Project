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
	MovingTest test2 = std::move(test1); //이동 생성자

	//std::cout << *(test1.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test1.GetPtr())
		std::cout << "이동생성자는 매개변수를 초기화시킨다. (포인터는 null)" << std::endl;

	MovingTest test3(7);
	test2 = std::move(test3); //이동 대입 연산자

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test3.GetPtr())
		std::cout << "이동 대입연산자는 매개변수를 초기화시킨다. (포인터는 null)" << std::endl;


	return 0;
}

//1. std::move()는 단지 좌측값을 우측값으로 캐스팅할뿐, 값에는 변화를 주지 않는다.

//2. 디폴트 이동생성자와 디폴트 이동 대입연산자는 멤버변수가 스마트포인터일 경우, 매개변수를 초기화 시킨다. (포인터의 경우는 null)