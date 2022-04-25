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
	MovingTest2 test2 = std::move(test1); //이동 생성자

	//std::cout << *(test1.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test1.GetPtr())
		std::cout << "이동생성자는 매개변수를 초기화시킨다(포인터는 null)" << std::endl;

	MovingTest2 test3(7);
	int* exc = test2.GetPtr();
	test2 = std::move(test3); //이동 대입 연산자

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << *(test2.GetPtr()) << std::endl;

	if (!test3.GetPtr())
		std::cout << "이동 대입연산자는 매개변수를 초기화시키며(포인터는 null), 기존의 포인터를 해제시킨다." << std::endl;



	return 0;
}

//1. std::move()는 단지 좌측값을 우측값으로 캐스팅할뿐, 값에는 변화를 주지 않는다.

//2. 디폴트 이동생성자와 디폴트 이동 대입연산자는 일반포인터에는 제대로 작동하지 않는다.