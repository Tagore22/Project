#pragma once
#include <memory>

class Handle_C;
class int_C;
class double_C;

class Handle_P
{
private:
	std::shared_ptr<Handle_C> child;

public:
	explicit Handle_P(int x = 0, double y = 0);
	int GetInt() const;
	double GetDouble() const;
};

