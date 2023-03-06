#include "Class.h"
#include <iostream>
#include <cmath>
int NOD(int x, int y)
{
	if (x == 0) 
		return y;
	while (x != y)
	{
		if (x > y) 
		    x = x - y;
		else 
			y = y - x;
	}
	return x;
}
Fraction& Fraction::reduce()
{
	int res = NOD(*pa, *pb);
	if (res != 0)
	{
		*pa /= res;
		*pb /= res;
	}
	return *this;

}

Fraction::Fraction()
{
	pa = new int;
	*pa = 0;
	pb = new int;
	*pb = 1;
}
Fraction::Fraction(int x, int y)
{
	pa = new int;
	*pa = x;
	pb = new int;
	*pb = y;	
}

Fraction::Fraction(const Fraction& fraction)
{
	pa = new int(*fraction.pa);
	pb = new int(*fraction.pb);
}

Fraction::~Fraction()
{
	delete pa;
	delete pb;
}

Fraction Fraction::operator+(Fraction fraction)
{
	return Fraction(*fraction.pa * *pb + *pa * *fraction.pb, *fraction.pb * *pb).reduce();
}

Fraction Fraction::operator*(Fraction fraction)
{
	return Fraction(*fraction.pa * *pa, *fraction.pb * *pb).reduce();
}

Fraction Fraction::operator/(Fraction fraction)
{
	return Fraction(*fraction.pb * *pa, *fraction.pa * *pb).reduce();
}

Fraction Fraction::operator-(Fraction fraction)
{
	return Fraction((*pa * *fraction.pb) - (*fraction.pa * *pb), *fraction.pb * *pb).reduce();
}

bool Fraction::operator==(Fraction fraction)
{
	if (*pa == *fraction.pa && *pb == *fraction.pb) 
		return 1;
	return 0;
}

bool Fraction::operator<(Fraction fraction)
{
	return ((double(*pa) / *pb) < (double(*fraction.pa) / *fraction.pb));
}

Fraction& Fraction::operator=(Fraction& fraction)
{
	if (this == &fraction) return *this;
	*pa = *fraction.pa;
	*pb = *fraction.pb;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << *fraction.pa << "/" << *fraction.pb << " ";
	return out;
}
std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	in >> *fraction.pa >> *fraction.pb;
	return in;
}
