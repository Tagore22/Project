#include "Kin.h"
#include <iostream>

void Kin::MamaSaid() const
{
	KinSaid();
	std::cout << "I am Kin" << std::endl;
	std::cout << old << std::endl;
}

void Kin::KinSaid() const
{
	std::cout << "Hi" << std::endl;
}