#include "Handle_P.h"
#include "Handle_C.h"

Handle_P::Handle_P(int x, double y) : child(new Handle_C(x, y))
{
}

int Handle_P::GetInt() const
{
	return child->GetInt();
}

double Handle_P::GetDouble() const
{
	return child->GetDouble();
}


