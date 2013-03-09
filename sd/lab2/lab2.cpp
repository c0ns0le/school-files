#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Complex.h"
 
int main()
{
	//vector vid
	Vector<Complex> numbers;
	
	//deschidere fisier input
	std::ifstream in;
	in.open("numbers.in");
	
	//TODO 2.9 Citire vector din fisier (se apeleaza operatorul >>)
	//in>>numbers;
	
	//Inchidere fisier
	in.close();
	
	//TODO 2.6 && 1.9 Scriu primul element din vector la iesirea standard
	//cout<<numbers[0]
	//TODO 3 sortare vector (MergeSort sau QuickSort)
	//numbers.sort();
	
	//TODO 2.8 Afisare vector la iesirea standard
	//cout<<numbers;
	
	//TODO 2.6 && 1.9 Scriu primul element din vector la iesirea standard
	//cout<<numbers[0]
	
	return 0;
}

