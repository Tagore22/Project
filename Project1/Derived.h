#pragma once
#include "Base.h"

class Derived : public Base
{
public:
	using Base::Base;
	Derived(double a);
	double getDouble() const;
private:
	double mdouble;
};

Derived::Derived(double a) : mdouble(a)
{
}

double Derived::getDouble() const
{
	return mdouble;
}
