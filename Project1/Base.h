#pragma once

class Base
{
public:
	Base(int a);
	Base() = default;
	int GetInt() const;

private:
	int mint;
};

Base::Base(int a) : mint(a)
{
}

int Base::GetInt() const
{
	return mint;
}