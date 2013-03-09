#ifndef __STACK__H
#define __STACK__H

#include <iostream>
 
// Primul argument al template-ului este tipul de date T
// Al doilea argument este dimensiunea maxim a stivei N
template<typename T, int N>
class Stack {
	public:
		// constructor
		Stack() {
			this->topLevel = -1;
		}
 
		// destructor
		~Stack() {
		}
 
		// operator de adaugare
		void push(T x) {
			this->topLevel++;
			if (this->topLevel > N-1) {
				std::cout << "Error: stack is full" << std::endl;
				this->topLevel = N-1;
				return;
			}
			this->stackArray[this->topLevel] = x;
		}
 
		// operatorul de stergere
		T pop() {
			if (this->topLevel < 0) {
				std::cout << "Error: stack is empty" << std::endl;
				T x;
				return x;
			}
			return this->stackArray[this->topLevel--];
		}
 
		// operatorul de consultare
		T peek() {
			if (this->topLevel < 0) {
				std::cout << "Error: stack is empty" << std::endl;
				T x;
				return x;
			}
			return this->stackArray[this->topLevel];
		}
 
		// operatorul de verificare dimensiune
		int isEmpty() {
			if (this->topLevel < 0) {
				return 1;
			}
			return 0;
		}
 
	private:
		// vectorul de stocare
		T stackArray[N];
 
		// pozitia in vector a varfului stivei
		int topLevel;
};
 
#endif // __STACK__H