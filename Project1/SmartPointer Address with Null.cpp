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
		std::cout << "����Ʈ������ ��ü�� Null�� �ʱ�ȭ �ȴ�." << std::endl;

	SmartInit ins2(7);
	std::cout << ins2.GetSptr() << " " << ins2.GetSptr().get() << std::endl;

	return 0;
}*/
//1. ����Ʈ������ Ÿ���� ��ü ��ü�� �ʱ�ȭ�� Null�� ������ ���� �� �ִ�.
//2. ����Ʈ������ ��ü�� �ش� ��ü�� ���ϰ� �ִ� �������� �ּҰ��̴�.
