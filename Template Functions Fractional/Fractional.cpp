#include "Fractional.h"

ostream& Fractional::print(ostream& stream) const
{
	stream << getNumerator() << "." << getDenominator();
	return stream;
}

istream& Fractional::scan(istream& stream)
{
	setNumerator(stream);
	setDenominator(stream);
	return stream;
}

Fractional& Fractional::operator= (const Fractional& F)
{
	if (this == &F)
		return *this;
	numerator = F.numerator;
	denominator = F.denominator;
	return (*this);
}

Fractional& Fractional::operator = (double _numerator)
{
	numerator = _numerator;
	double t;
	double* p = &t;
	denominator = (int)(_numerator * 100) % 100;
	return (*this);
}

bool Fractional::operator> (const Fractional& F) const
{
	if (numerator > F.numerator || numerator == F.numerator && denominator > F.denominator) { return true; }
	else return false;
}

bool Fractional::operator< (const Fractional& F) const
{
	return !(*this > F);
}

double operator += (double& i, Fractional& F)
{
	i = i + F.numerator + (F.denominator / 100);
	return (i + F.numerator + F.denominator / 100);
}

ostream& operator << (ostream& stream, const Fractional& F)
{
	return F.print(stream);
}

istream& operator >> (istream& stream, Fractional& F)
{
	return F.scan(stream);
}

