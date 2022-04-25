#pragma once
#include <memory>

class Interface_P
{
public:
	static std::shared_ptr<Interface_P> FactoryFunction (int x = 0, double y = 0);
	virtual int GetInt() const = 0;
	virtual double GetDouble() const = 0;
	virtual ~Interface_P();
};
