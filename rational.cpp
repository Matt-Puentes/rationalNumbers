// rational.cpp  Andrew Levy  Matthew Puentes

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>


#include "rational.h"

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

double getDouble(int x) {
	double a = x;
	return a;
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(const int wholeNumber) {
	numerator = wholeNumber;
	denominator = 1;
}

void Rational::giveValue() {
	std::cout << numerator;
	std::cout << "/";
	std::cout << denominator << std::endl;
}

void Rational::simplify() {
	if (denominator == 0) {
		perror("ERROR: Denominator = 0");
		exit(0);
	}
	int factor = gcd(numerator, denominator);
	numerator = numerator / factor;
	denominator = denominator / factor;
	if (denominator != abs(denominator)) {
		denominator = abs(denominator);
		numerator = 0 - numerator;
	}
}

Rational::Rational(const int num, const int den) {
	numerator = num;
	denominator = den;
}

std::ostream& operator <<(std::ostream& stream, const Rational &a){
	stream << a.numerator << "/" << a.denominator;
	return stream;
}

std::istream& operator >>(std::istream& stream, Rational &a){
	int num;
	char c;
	int denum;
	stream >> std::ws;

	if(!(std::isdigit(stream.peek())) && stream.peek() != '-'){
		throw devide_by_zero_exception();
	}
	stream >> num;
	if(stream.peek() != '/'){
		a = * (new Rational(num));
		return stream;
	}
	stream >> c >> denum;
	a = *(new Rational(num, denum));
	return stream;
}

const Rational Rational::operator +(const Rational &a) const {
	int sumNum = numerator * a.denominator + a.numerator * denominator;
	int sumDen = denominator * a.denominator;
	Rational rat(sumNum, sumDen);
	rat.simplify();
	return rat;
}

const Rational Rational::operator -(const Rational &a) const {
	int sumNum = numerator * a.denominator - a.numerator * denominator;
	int sumDen = denominator * a.denominator;
	Rational rat(sumNum, sumDen);
	rat.simplify();
	return rat;
}

const Rational Rational::operator *(const Rational &a) const {
	int sumNum = numerator * a.numerator;
	int sumDen = denominator * a.denominator;
	Rational rat(sumNum, sumDen);
	rat.simplify();
	return rat;
}

const Rational Rational::operator /(const Rational &a) const {
	int sumNum = numerator * a.denominator;
	int sumDen = denominator * a.numerator;
	Rational rat(sumNum, sumDen);
	rat.simplify();
	return rat;
}

const bool Rational::operator ==(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A == B) {
		return true;
	} else {
		return false;
	}
}

const bool Rational::operator !=(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A == B) {
		return false;
	} else {
		return true;
	}
}

const bool Rational::operator <(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A < B) {
		return true;
	} else {
		return false;
	}
}

const bool Rational::operator >(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A >= B) {
		return true;
	} else {
		return false;
	}
}

const bool Rational::operator <=(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A < B) {
		return true;
	} else {
		return false;
	}
}

const bool Rational::operator >=(const Rational &a) const {
	double A, B;
	A = getDouble(numerator) / getDouble(denominator);
	B = getDouble(a.numerator) / getDouble(a.denominator);
	if (A >= B) {
		return true;
	} else {
		return false;
	}
}

double Rational::toDouble() {
	double n, d, y;
	n = numerator;
	d = denominator;
	y = n / d;
	return y;
}
