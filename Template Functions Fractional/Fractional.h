#pragma once

#include "Configuration.h"

// Класс типа "Дробное число"
class Fractional
{
	// Поля с числителем и знаменателем
	int numerator;
	int denominator;
public:
	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	void setNumerator(istream& stream) { stream >> numerator; }
	void setDenominator(istream& stream) { stream >> denominator; }

	// Методы ввода/вывода полей
	ostream& print(ostream& stream) const;
	istream& scan(istream& stream);

	// Перегрузка операции присваивания
	Fractional& operator = (const Fractional& F);

	// Перегрузка операции присваивания для генерации случайных значений полей
	Fractional& operator = (double _numerator);

	// Перегрузка операций сравнения
	bool operator > (const Fractional& F) const;
	bool operator < (const Fractional& F) const;

	friend double operator += (double& i, Fractional& F);
	
	// Перегрузка потоков ввода/вывода полей
	friend ostream& operator << (ostream& stream, const Fractional& F);
	friend istream& operator >> (istream& stream, Fractional& F);
};
