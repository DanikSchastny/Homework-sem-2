// Quadratic_equations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<cmath>

class QuadrEquat
{
public:

	inline void Check();

	inline double firstRoot();

	inline double secondRoot();

	double* roots();

	QuadrEquat();

	QuadrEquat(double, double, double);

	inline double GetA();

	inline double GetB();

	inline double GetC();

private:

	inline void SetA(double);

	inline void SetB(double);

	inline void SetC(double);

	double a, b, c;
};


inline void QuadrEquat::Check()
{
	if (this->GetB() * this->GetB() - 4 * GetA() * GetC() < 0)
	{
		throw std::invalid_argument("The roots don't exist, because D is < 0!");
	}
}

inline double QuadrEquat::GetA()
{
	return this->a;
}

inline double QuadrEquat::GetB()
{
	return this->b;
}

inline double QuadrEquat::GetC()
{
	return this->c;
}

inline double QuadrEquat::firstRoot()
{
	this->Check();

	return ((sqrt(this->GetB() * this->GetB() - 4 * GetA() * GetC()) - GetB()) / (2 * GetA()));
}

inline double QuadrEquat::secondRoot()
{
	this->Check();

	return ((-sqrt(this->GetB() * this->GetB() - 4 * GetA() * GetC()) - GetB()) / (2 * GetA()));
}

double* QuadrEquat::roots()
{
	this->Check();

	if ((this->GetB() * this->GetB() - 4 * GetA() * GetC() )!=0)
	{
		double roots[2];
		roots[0] = this->firstRoot();
		roots[1] = this->secondRoot();

		return roots;
	}

	else
	{
		double roots[1];
		roots[0] = this->firstRoot();

		return roots;
	}
}

inline void QuadrEquat::SetA(double x)
{
	this->a = x;
}

inline void QuadrEquat::SetB(double x)
{
	this->b = x;
}

inline void QuadrEquat::SetC(double x)
{
	this->c = x;
}

QuadrEquat::QuadrEquat()
{
	this->SetA(0);
	
	this->SetB(0);

	this->SetC(0);
}

QuadrEquat::QuadrEquat(double x, double y, double z)
{
	this->SetA(x);

	this->SetB(y);

	this->SetC(z);
}

int main()
{
    return 0;
}

