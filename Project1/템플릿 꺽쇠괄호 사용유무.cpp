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
//1. 클래스 템플릿에서 생성자 매개변수가 클래스안에 T 멤버를 초기화시키지 않을지라도 템플릿 매개변수 자체에 디폴트 값이 있다면 꺽쇠괄호(<>)를 사용하지 않아도 된다.
//2. 템플릿 매개변수에 디폴트 값이 없을지라도 생성자의 매개변수가 클래스안에 T 멤버변수를 초기화 시킨다면 꺽쇠괄호(<>)를 사용하지 않아도 된다.
//3. std::size_t는 <iostream>에 있다.