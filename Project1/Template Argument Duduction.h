#pragma once
#include <iostream>

template <typename T>
class TAD
{
public:
	TAD(const T& a);
	void Setmem(const T& a);
	T Getmem() const;
private:
	T mA;
};

template <typename T>
TAD<T>::TAD(const T& a) : mA(a)
{
}

template <typename T>
void TAD<T>::Setmem(const T& a)
{
	mA = a;
}

template <typename T>
T TAD<T>::Getmem() const
{
	return mA;
}

