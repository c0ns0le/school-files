#ifndef _VECTOR_H
#define _VECTOR_H 1

template<typename T>
class Vector
{
private:
    int nr;
    T * elements;
    
public:		
	//TODO 2.1 => Constructor vid
	Vector(void) {
	    this->nr = 0;
	    this->elements = NULL;
	}
	//TODO 2.2 => Constructor numar elemente
	Vector(int n) {
	    this->nr = n;
	    this->elements = new T[n];
	}
	//TODO 2.3 => Destructor
	~Vector(void) {
	    this->nr = 0;
	    delete this->elements;
	}
	//TODO 2.4 => Functie membru determinare dimensiune vector
	int getNr(void) {
	    return this->nr;
	}
	//TODO 2.5 => Functie membru operator atribuire
	T& operator=(const T& v) {
	    this->nr = v.nr;
	    if (this->elements) {
		delete this->elements;
	    }
	    this->elements = new T[this->nr];
	    int i;
	    for (i = 0; i < this->nr; i++) {
	    	this->elements[i] = v.elements[i];
	    }
	}
	//TODO 2.6 => Functie membru operator indexare
	T& operator[](int n) {
	    return this->elements[n];
	}
	//TODO 2.7 => Functie friend operator egalitate
	friend int operator==(Vector<T>, Vector<T>);
	//TODO 2.8 => Functie friend operator <<
	friend std::ostream& operator<<(std::ostream&, Vector<T>);
	//TODO 2.9 => Functie friend operator >>
	friend std::istream& operator<<(std::istream&, Vector<T>);
	//TODO 3 => Functie membru sort(), ce realizeaza sortarea componentelor
	void sort(void) {
	    // sort
	}
};

int operator==(Vector<T>& a, Vector<T>& b) {
    if (a.nr != b.nr) {
	return 0;
    }
    int i;
    for (i = 0; i < a.nr; i++) {
	if (a.elements[i] != b.elements[i]) {
		return 0;
	}
    }
    return 1;
}

std::ostream& operator<<(std::ostream& f, Vector<T>& v) {
    int i;
    for (i = 0; i < v.nr; i++) {
    	f << v.elements[i] << " ";
    }
    f << std::endl;

    return f;
}

std::istream& operator<<(std::istream& f, Vector<T>& v) {
    f >> v.nr;
    int i;
    for (i = 0; i < v.nr; i++) {
    	f >> v.elements[i];
    }

    return f;
}

#endif	

/** Observatie: Nu exista Vector.cpp, intrucat este o clasa template*/
