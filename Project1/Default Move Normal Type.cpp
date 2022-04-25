#include <iostream>
#include <utility>
#include <memory>

class IntMoving
{
private:
	std::size_t mNum;
public:
	IntMoving(std::size_t a = 0);
	std::size_t GetNum() const;
};

IntMoving::IntMoving(std::size_t a) : mNum(a)
{
}

std::size_t IntMoving::GetNum() const
{
	return mNum;
}


int DMNTmain()
{
	IntMoving ins1(7);
	IntMoving ins2 = std::move(ins1);

	std::cout << ins2.GetNum() << " " << ins1.GetNum() << std::endl;

	return 0;
}
//1. �����͸� ������ �⺻ Ÿ���� ����Ʈ �̵������ڰ� ����� �۵����� �ʴ´�.(������ �ʱ�ȭ���� �ʴ´�.)