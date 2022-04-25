#include "Interface_C.h"

std::shared_ptr<Interface_P> Interface_P::FactoryFunction(int x, double y)
{
	return std::shared_ptr<Interface_P>(new Interface_C(x, y));
}

Interface_P::~Interface_P()
{
}

Interface_C::Interface_C(int x, double y) : IntX(x), DoubleY(y)
{
}

int Interface_C::GetInt() const
{
	return IntX.GetX();
}

double Interface_C::GetDouble() const
{
	return DoubleY.GetY();
}

Interface_C::~Interface_C()
{
}