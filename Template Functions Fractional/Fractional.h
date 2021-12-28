#pragma once

#include "Configuration.h"

// ����� ���� "������� �����"
class Fractional
{
	// ���� � ���������� � ������������
	int numerator;
	int denominator;
public:
	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	void setNumerator(istream& stream) { stream >> numerator; }
	void setDenominator(istream& stream) { stream >> denominator; }

	// ������ �����/������ �����
	ostream& print(ostream& stream) const;
	istream& scan(istream& stream);

	// ���������� �������� ������������
	Fractional& operator = (const Fractional& F);

	// ���������� �������� ������������ ��� ��������� ��������� �������� �����
	Fractional& operator = (double _numerator);

	// ���������� �������� ���������
	bool operator > (const Fractional& F) const;
	bool operator < (const Fractional& F) const;

	friend double operator += (double& i, Fractional& F);
	
	// ���������� ������� �����/������ �����
	friend ostream& operator << (ostream& stream, const Fractional& F);
	friend istream& operator >> (istream& stream, Fractional& F);
};
