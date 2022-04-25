#include <iostream>
#include <utility>

class testvocSSa
{
public:
	testvocSSa(int num);
	testvocSSa() = default;
	testvocSSa(const testvocSSa& ins);
	testvocSSa& operator=(const testvocSSa& ins);
	testvocSSa(testvocSSa&& ins) noexcept;
	testvocSSa& operator=(testvocSSa&& ins) noexcept;
	~testvocSSa() = default;
	int Getnum() const;
	void Setnum(int num);
	friend void swap(testvocSSa& a, testvocSSa& b) noexcept;
private:
	int mNum;
};

testvocSSa::testvocSSa(int num) : mNum(num)
{
	std::cout << "�Ϲ� ������ ȣ��!" << std::endl;
}

testvocSSa::testvocSSa(const testvocSSa& ins) : mNum(ins.Getnum())
{
	std::cout << "���� ������ ȣ��!" << std::endl;
}

testvocSSa& testvocSSa::operator=(const testvocSSa& ins)
{
	if (this == &ins)
		return *this;

	testvocSSa temp(ins);
	swap(*this, temp);
	std::cout << "���� ���� ������ ȣ��!" << std::endl;
	return *this;
}

testvocSSa::testvocSSa(testvocSSa&& ins) noexcept : testvocSSa()
{
	swap(*this, ins);
	std::cout << "�̵� ������ ȣ��!" << std::endl;
}

testvocSSa& testvocSSa::operator=(testvocSSa&& ins) noexcept
{
	testvocSSa temp(std::move(ins));
	swap(*this, temp);
	std::cout << "�̵� ���� ������ ȣ��!" << std::endl;
	return *this;
}

int testvocSSa::Getnum() const
{
	return mNum;
}

void testvocSSa::Setnum(int num)
{
	mNum = num;
}

void swap(testvocSSa& a, testvocSSa& b) noexcept
{
	using std::swap;

	swap(a.mNum, b.mNum);
}

testvocSSa testfunc()
{
	testvocSSa temp(1);
	return temp;
}

int FFmain()
{
	testvocSSa ins1(1);
	testvocSSa ins2 = ins1;
	testvocSSa ins3(5);
	ins3 = ins1;

	testvocSSa ins4 = testfunc();
	ins2 = testfunc();
	return 0;
}
//1. ����� ���� Ÿ��(Ŭ����) ��ü�� std::swap() ������ �ش� Ŭ������ �̵� ���� ������, Ȥ�� ���� ���� �������� ���� ������ ����Ű�⿡ ���� Ŭ������ �� ����� std::swap() �ϴ� ����� ���� swap�Լ���
// �����ؾ� �Ѵ�.
//2. �Լ��� ��ȯ�������� ���� ���� ��ü�� �ӽú����ν� ��ȯ �ȴ� ������ �� ���� ��ü�� �Լ� ȣ���Ŀ� ������� ��ü��� �� ��ȯ�������� �̵� ������ �̷������.(�̵� ������)
//2+. ������ �ش� �����Լ��� ������� ��ȯ�� ���Ǵ� �ӽð�ü�� ������ �����ȴ�. �̰� ����ȭ��Ű�� ���� ������� �����Լ��� ����� �ӽð�ü ��� ����ϸ� �� �������� �̵� ������ �̷����.
//2++. ������ �����̱⿡ ����Ʈ ������(Ư�� std::unique_ptr)���� �� ����ȴ�.
