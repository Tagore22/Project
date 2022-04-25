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
	MovingTest3 test2 = std::move(test1); //이동 생성자

	//std::cout << test1[0] << std::endl;
	std::cout << test2[0] << std::endl;

	if (test1.GetVector().size() == 0)
		std::cout << "이동생성자는 매개변수를 초기화시킨다(포인터는 null)" << std::endl;

	MovingTest3 test3(7);
	//int* exc = test2.GetPtr();
	test2 = std::move(test3); //이동 대입 연산자

	//std::cout << *(test3.GetPtr()) << std::endl;
	std::cout << test2[0] << std::endl;

	if (test3.GetVector().size() == 0)
		std::cout << "이동 대입연산자는 매개변수를 초기화시키며(포인터는 null), 기존의 포인터를 해제시킨다." << std::endl;



	return 0;
}
//1. std::move()는 단지 좌측값을 우측값으로 캐스팅할뿐, 값에는 변화를 주지 않는다.

//2. 디폴트 이동생성자와 디폴트 이동 대입연산자는 멤버변수가 벡터를 비롯한 STL 컨테이너일 경우, 매개변수를 초기화 시킨다. (포인터의 경우는 null)