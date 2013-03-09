#Specifica compilatorul
CC=g++
#Specifica optiunile de compilare
CXXFLAGS=-Wall

#Specifica bibliotecile de care depinde executabilul
# lm => biblioteca de math
LDFLAGS= -lm

#Regula din care rezulta executabilul
#Se expandeaza automat la
#$(CC) $(LDFLAGS) -o $^ $@
#unde: $^ => numele regulei
#      $@ => lista de reguli obligatorii
lab2: lab2.o Complex.o

#Regulile din care rezulta fisierele obiect
#Se expandeaza automat la
#$(CC) $(CXXFLAGS ) -c -o $^ $<
#unde: $^ => numele regulei
#      $< => numele fisierelor de care depinde
Complex.o: Complex.cpp
lab2.o: lab2.cpp


.PHONY: clean
#Regula de clean
clean:
	rm -fr *.o lab2