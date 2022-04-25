#include <iostream>

template <typename T = int, std::size_t a = 5, std::size_t b = 7>
class DefaultDeclare
{
public:
	DefaultDeclare(std::size_t a = 0);
private:
	std::size_t mNum;
};

template <typename T, std::size_t a, std::size_t b>
DefaultDeclare<T, a, b>::DefaultDeclare(std::size_t a) : mNum(a)
{
}

int Tmain()
{
	DefaultDeclare a;
	DefaultDeclare<double, 3, 4> b;

	return 0;
}
//1. Ŭ���� ���ø����� ������ �Ű������� Ŭ�����ȿ� T ����� �ʱ�ȭ��Ű�� �������� ���ø� �Ű����� ��ü�� ����Ʈ ���� �ִٸ� �����ȣ(<>)�� ������� �ʾƵ� �ȴ�.
//2. ���ø� �Ű������� ����Ʈ ���� �������� �������� �Ű������� Ŭ�����ȿ� T ��������� �ʱ�ȭ ��Ų�ٸ� �����ȣ(<>)�� ������� �ʾƵ� �ȴ�.
//3. std::size_t�� <iostream>�� �ִ�.