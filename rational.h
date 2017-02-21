#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>


//class for rational numbers
class Rational {
public:
	Rational(const int num, const int den); //set value to any legitimate number
	Rational(const int wholeNumber); //numerator to value of wholeNumber and denominator to 1
//	Rational(const Rational &a); //copy constructor
	Rational(); //sets value to 0
	friend std::ostream& operator <<(std::ostream& stream, const Rational &a);
	friend std::istream& operator >>(std::istream& stream, Rational &a);
	const Rational operator+(const Rational &a) const;
	const Rational operator-(const Rational &a) const;
	const Rational operator*(const Rational &a) const;
	const Rational operator/(const Rational &a) const;
	const bool operator ==(const Rational &a) const;
	const bool operator !=(const Rational &a) const;
	const bool operator <(const Rational &a) const;
	const bool operator >(const Rational &a) const;
	const bool operator <=(const Rational &a) const;
	const bool operator >=(const Rational &a) const;
	double toDouble();
	void giveValue();
	void simplify();
private:

	int numerator;
	int denominator;
};

class devide_by_zero_exception : public std::runtime_error{
public:
	devide_by_zero_exception(): runtime_error("Attempted to divide by zero"){}
};

#endif /* RATIONAL_H_ */
