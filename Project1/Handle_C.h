#pragma once
#include "int_C.h"
#include "Double_C.h"

class Handle_C
{
private:
	int_C IntX;
	Double_C DoubleY;
public:
	explicit Handle_C(int x = 0, double y = 0);
	int GetInt() const;
	double GetDouble() const;
};
