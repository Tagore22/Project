#pragma once
#include "Mama.h"

class Kin : public Mama
{
public:
	virtual ~Kin() = default;
	virtual void MamaSaid() const override;
	void KinSaid() const;
private:
	int old = 0;
};
