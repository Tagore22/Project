#include "Handle_C.h"

Handle_C::Handle_C(int x, double y) : IntX(x), DoubleY(y)
{
}

int Handle_C::GetInt() const
{
	return IntX.GetX();
}

double Handle_C::GetDouble() const
{
	return DoubleY.GetY();
}