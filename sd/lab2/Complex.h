#ifndef _COMPLEX_H
#define _COMPLEX_H 1

#include <iostream>

class Complex
{
private:
    double re;
    double im;

public:	
	//TODO 1.1 => Constructor vid
	Complex(void);

	//TODO 1.2 => Constructor cu coordonate
	Complex(double, double);

	double size(void);

	//TODO 1.3 => Functii membru ce intor partea reala respectic imaginara
	double getRe(void);
	double getIm(void);

	//TODO 1.4 => Functie membru operator <
	//int operator<(const Complex&);

	//TODO 1.5 => Functie membru operator >
	//int operator>(const Complex&);

	//TODO 1.6 => Functie membru operator ==
	//int operator==(const Complex&);

	//TODO 1.7 => Functii membru operatori +,-
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);

	//TODO 1.8 => Functie friend operator <<
	friend std::ostream& operator<<(std::ostream&, const Complex&);

	//TODO 1.9 => Functie friend operator >>
	friend std::istream& operator>>(std::istream&, const Complex&);
};
#endif	

/** Observatie: Definitiile functiilor se scriu in Complex.cpp, intrucat nu este o clasa template*/
