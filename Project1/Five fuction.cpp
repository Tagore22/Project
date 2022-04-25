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
	std::cout << "일반 생성자 호출!" << std::endl;
}

testvocSSa::testvocSSa(const testvocSSa& ins) : mNum(ins.Getnum())
{
	std::cout << "복사 생성자 호출!" << std::endl;
}

testvocSSa& testvocSSa::operator=(const testvocSSa& ins)
{
	if (this == &ins)
		return *this;

	testvocSSa temp(ins);
	swap(*this, temp);
	std::cout << "복사 대입 연산자 호출!" << std::endl;
	return *this;
}

testvocSSa::testvocSSa(testvocSSa&& ins) noexcept : testvocSSa()
{
	swap(*this, ins);
	std::cout << "이동 생성자 호출!" << std::endl;
}

testvocSSa& testvocSSa::operator=(testvocSSa&& ins) noexcept
{
	testvocSSa temp(std::move(ins));
	swap(*this, temp);
	std::cout << "이동 대입 연산자 호출!" << std::endl;
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
//1. 사용자 정의 타입(클래스) 객체의 std::swap() 연산은 해당 클래스의 이동 대입 연산자, 혹은 복사 대입 연산자의 무한 루프를 일으키기에 따로 클래스의 각 멤버를 std::swap() 하는 사용자 정의 swap함수를
// 구현해야 한다.
//2. 함수의 반환과정에서 설령 스택 객체가 임시변수로써 반환 된다 할지라도 그 스택 객체가 함수 호출후에 사라지는 객체라면 이 반환과정에서 이동 연산이 이루어진다.(이동 생성자)
//2+. 어차피 해당 스택함수는 사라지며 반환에 사용되는 임시객체는 새로이 생성된다. 이걸 최적화시키기 위해 사라지는 스택함수를 살려서 임시객체 대신 사용하며 이 과정에서 이동 연산이 이루어짐.
//2++. 정당한 연산이기에 스마트 포인터(특히 std::unique_ptr)에도 잘 적용된다.
