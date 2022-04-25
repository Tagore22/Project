#pragma once
#include "Interface_P.h"
#include "int_C.h"
#include "Double_C.h"

class Interface_C : public Interface_P
{
private:
	int_C IntX;
	Double_C DoubleY;
public:
	Interface_C(int x = 0, double y = 0);
	virtual int GetInt() const;
	virtual double GetDouble() const;
	virtual ~Interface_C();
};