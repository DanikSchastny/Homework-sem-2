// RationalNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class RationalNumb
{
public:
	


	RationalNumb(); 

	explicit RationalNumb(int);

	RationalNumb(int, int);

	int GetNumerator() const;

	int GetDenominator() const;

	RationalNumb& operator +=(const RationalNumb&);

	RationalNumb& operator +=(int);

	RationalNumb& operator -=(const RationalNumb&);

	RationalNumb& operator -=(int);

	RationalNumb& operator *= (const RationalNumb&);

	RationalNumb& operator *= (int);

	RationalNumb& operator /=(const RationalNumb&);

	RationalNumb& operator /=(int);

	inline RationalNumb& operator ++();

	inline RationalNumb const operator++(int);

	inline RationalNumb& operator --();

	inline RationalNumb const operator --(int);

	inline RationalNumb const operator +(RationalNumb const&) const;

	inline RationalNumb const operator +(int) const;

	friend inline RationalNumb const operator+(int, RationalNumb const&);

	inline RationalNumb const operator - (RationalNumb const&) const;

	inline RationalNumb const operator -(int) const;

	friend inline RationalNumb const operator -(int, RationalNumb const&);

	inline RationalNumb operator * (const RationalNumb&);

	inline RationalNumb operator *(int);

	friend inline RationalNumb operator* (int, const RationalNumb&);

	inline RationalNumb operator /(const RationalNumb&);

	inline RationalNumb operator / (int);

	friend inline RationalNumb operator / (int, const RationalNumb&);

	explicit operator double() const { return (double)this->GetNumerator() / this->GetDenominator(); }

	friend std::istream& operator >> (std::istream& , RationalNumb& r);

	friend inline std::ostream& operator << (std::ostream&, const RationalNumb& r);


private:

	void SetNum(int);

	void SetDenom(int);

	static void Normalize(RationalNumb&);

	static int GSD(int, int);

	int numerator;
	int denominator;
};

#pragma region RNumn

RationalNumb::RationalNumb()
{
	this->SetNum(0);
	this->SetDenom(1);
}

void RationalNumb::SetNum(int x)
{
	this->numerator = x;
}

void RationalNumb::SetDenom(int x)
{
	if (x == 0)
	{
		throw std::invalid_argument("The denominator is 0");
	}
	this->denominator = x;
}

RationalNumb::RationalNumb(int x)
{
	this->SetNum(x);
	this->SetDenom(1);
}

RationalNumb::RationalNumb(int argNum, int argDenom)
{
	this->SetNum(argNum);
	this->SetDenom(argDenom);

	Normalize(*this);
}

int RationalNumb::GetDenominator() const
{
	return this->denominator;
}

int RationalNumb::GetNumerator() const
{
	return this->numerator;
}

int RationalNumb::GSD(int a, int b)
{
	return b ? GSD(b, a%b) : a;
}

void RationalNumb::Normalize(RationalNumb& x)
{
	int gsd = GSD(x.GetDenominator(), x.GetNumerator());

	x.SetNum(x.GetNumerator() / gsd);
	x.SetDenom(x.GetDenominator() / gsd);
}

inline RationalNumb& RationalNumb::operator*=(const RationalNumb& r)
{
	this->SetNum(this->GetNumerator() * r.GetNumerator());
	this->SetDenom(this->GetDenominator() * r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator*=(int a)
{
	this->SetNum(this->GetNumerator() *a);

	Normalize(*this);
}

inline RationalNumb& RationalNumb::operator /= (const RationalNumb& r)
{
	this->SetNum(this->GetNumerator() * r.GetDenominator());
	this->SetDenom(this->GetDenominator() * r.GetNumerator());

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator /= (int a)
{
	this->SetDenom(this->GetDenominator() * a);

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator +=(const RationalNumb& r)
{
	this->SetNum(this->GetNumerator() * r.GetDenominator() + this->GetDenominator()*r.GetNumerator());
	this->SetDenom(this->GetDenominator()* r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator+=(int a)
{
	this->SetNum(this->GetNumerator() + a*this->GetDenominator());

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator-=(const RationalNumb& r)
{
	this->SetNum(this->GetNumerator()* r.GetDenominator() - r.GetNumerator()*this->GetDenominator());
	this->SetDenom(this->GetDenominator() * r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline RationalNumb& RationalNumb::operator-=(int a)
{
	this->SetNum(this->GetNumerator() - a*this->GetDenominator());

	Normalize(*this);
	return(*this);
}

inline RationalNumb& RationalNumb::operator++() //prefix
{
	this->SetNum(this->GetNumerator() + this->GetDenominator());

	Normalize(*this);
	return *this;
} 

inline RationalNumb const RationalNumb::operator++(int) //postfix
{
	RationalNumb r = *this;
	++*this;
	return r;
}

inline RationalNumb& RationalNumb::operator--()
{
	this->SetNum(this->GetNumerator() - this->GetDenominator());
	return *this;
}

inline RationalNumb const RationalNumb::operator--(int)
{
	RationalNumb r = *this;
	--*this;
	return r;
}

inline RationalNumb const RationalNumb::operator +(RationalNumb const& r) const
{
	return RationalNumb(this->GetNumerator() * r.GetDenominator() + r.GetNumerator() * this->GetDenominator(), this->GetDenominator() * r.GetDenominator());
}

inline RationalNumb const RationalNumb::operator+(int a) const
{
	return RationalNumb(this->GetNumerator() + a * this->GetDenominator(), this->GetDenominator());
}

inline RationalNumb const operator + (int a, RationalNumb const& r)
{
	return RationalNumb(a*r.GetDenominator() + r.GetNumerator(), r.GetDenominator());
}

inline RationalNumb const RationalNumb::operator -(RationalNumb const& r) const
{
	return RationalNumb(this->GetNumerator() * r.GetDenominator() - r.GetNumerator() * this->GetDenominator(), this->GetDenominator() * r.GetDenominator());
}

inline RationalNumb const RationalNumb::operator-(int a) const
{
	return RationalNumb(this->GetNumerator() - a * this->GetDenominator(), this->GetDenominator());
}

inline RationalNumb const operator - (int a, RationalNumb const& r)
{
	return RationalNumb(a*r.GetDenominator() - r.GetNumerator(), r.GetDenominator());
}

inline RationalNumb RationalNumb::operator*(const RationalNumb& r)
{
	return RationalNumb(this->GetNumerator() * r.GetNumerator(), this->GetDenominator() * r.GetDenominator());
}

inline RationalNumb RationalNumb::operator*(int a)
{
	return RationalNumb(this->GetNumerator()*a, this->GetDenominator());
}

inline RationalNumb operator*(int a, const RationalNumb& r)
{
	return RationalNumb(a*r.GetNumerator(), r.GetDenominator());
}

inline RationalNumb RationalNumb::operator/(const RationalNumb& r)
{
	return RationalNumb(this->GetNumerator()*r.GetDenominator(), this->GetDenominator() * r.GetNumerator());
}

inline RationalNumb RationalNumb::operator/(int a)
{
	return RationalNumb(a*this->GetDenominator(), this->GetNumerator());
}

inline RationalNumb operator / (int a, const RationalNumb& r)
{
	return RationalNumb(a*r.GetDenominator(), r.GetNumerator());
}

inline std::istream& operator >> (std::istream& is, RationalNumb& r)
{
	char ch;
	int num;
	int denom;
	is >> num;

	r.SetNum(num);
	is.unsetf(std::ios_base::skipws);
	is >> ch;
	if (ch == '/')
	{

		is >> denom;
		r.SetDenom(denom);
	}
	else
	{
		is.putback(ch);
		r.SetDenom(1);
	}
	is.setf(std::ios_base::skipws);
	while (r.GetDenominator() == 0)
	{
		
		is >> denom;
		r.SetDenom(denom);
		is.unsetf(std::ios_base::skipws);

		is >> ch;
		if (ch == '/')
		{
			is >> denom;
			r.SetDenom(denom);
		}
		else
		{
			is.putback(ch);
			r.SetDenom(1);
		}
		is.setf(std::ios_base::skipws);
	}
	RationalNumb::Normalize(r);
	return is;
}

inline std::ostream& operator << (std::ostream& os, const RationalNumb& r)
{
	os << r.GetNumerator();
	if (1 != r.GetDenominator())
	{
		os << '/' << r.GetDenominator();
	}
	return os;
}
#pragma endregion


int main()
{
	
	system("pause");
    return 0;
}

