/*#include <iostream>
#include <memory>

class SmartInit
{
private:
	std::unique_ptr<int> mSptr;
public:
	SmartInit(std::size_t a);
	SmartInit() = default;
	std::unique_ptr<int>& GetSptr();
};

SmartInit::SmartInit(std::size_t a) : mSptr(std::make_unique<int>(a))
{
}

std::unique_ptr<int>& SmartInit::GetSptr()
{
	return mSptr;
}


int SImain()
{
	if (SmartInit ins1; !ins1.GetSptr())
		std::cout << "스마트포인터 자체가 Null로 초기화 된다." << std::endl;

	SmartInit ins2(7);
	std::cout << ins2.GetSptr() << " " << ins2.GetSptr().get() << std::endl;

	return 0;
}*/
//1. 스마트포인터 타입의 객체 자체도 초기화시 Null을 값으로 가질 수 있다.
//2. 스마트포인터 자체가 해당 객체가 지니고 있는 포인터의 주소값이다.
