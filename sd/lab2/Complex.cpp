#include "Complex.h"
#include <math.h>

#define EPS 0.001

Complex::Complex(void) {
	this->re = 0;
	this->im = 0;
}

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}

double Complex::getRe(void) {
	return this->re;
}

double Complex::getIm(void) {
	return this->im;
}
/*
int Complex::operator<(const Complex& c) {
	if (this->size() < c.size()) {
		return 1;
	}
	return 0;
}

int Complex::operator>(const Complex& c) {
	if (this->size() > c.size()) {
		return 1;
	}
	return 0;
}

int Complex::operator==(const Complex& c) {
	if (fabs( this->size() - c.size() ) < EPS) {
		return 1;
	}
	return 0;
}*/

double Complex::size(void) {
	return (this->re)*(this->re) + (this->im)*(this->im);
}

Complex Complex::operator+(const Complex& c) {
	Complex r;
	r.re = this->re + c.re;
	r.im = this->im + c.im;

	return r;
}

Complex Complex::operator-(const Complex& c) {
	Complex r;
	r.re = this->re - c.re;
	r.im = this->im - c.im;

	return r;
}
std::ostream& operator<<(std::ostream& f, const Complex& c) {
	f << "(" << c.re << "," << c.im << ")" << std::endl;
	return f;
}

std::istream& operator>>(std::istream& f, const Complex& c) {
	f >> c.re >> c.im;
	return f;
}
