/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#ifndef _ALGORITHM_H
#define _ALGORITHM_H 1

#include <string>
#include "hashtable.h"

class Algorithm
{
public: 
	/** Definiti membrii de care aveti nevoie*/
    HashTable* h;

public:
	Algorithm(void);
	~Algorithm(void);
	/** Proceseaza o comanda PUT */
	void indexSite(const std::string &row);
	
	/** Proceseaza o comanda GET */
	void getSites(const std::string &row);
	
	/** Proceseaza o comanda SITE */
	void wordInSite(const std::string &row);
	
	/** Proceseaza fiecare comanda primita de la input, pana cand se intalneste EOF */
	void resolve();
};

#endif
