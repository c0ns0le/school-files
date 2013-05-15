/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "algorithm.h"

using namespace std;

/**Functia de hash*/
unsigned int hashFunction(char* key)
{
	unsigned int hash = 5381;

    unsigned int size = strlen(key);

	for (unsigned i=0;i<size;i++)
		hash = ((hash << 5) + hash) + (int)key[i];

	return hash;
}


/**
 * Constructor
 * inițializează un HashTable folosind hashFunction și având 10 găleți
 */
Algorithm::Algorithm(void)
{
    h = new HashTable(hashFunction, 10);
}

/**
 * Destructor
 */
Algorithm::~Algorithm(void)
{
    delete h;
}

/**
 * procesează o comandă de tip PUT
 */
void Algorithm::indexSite(const std::string &row)
{
	char *row_tok=strdup(row.c_str());
	char *command=strtok(row_tok," ");
	if (strcmp(command,"PUT")!=0)
	{
		free(row_tok);
		return;
	}
	
	char *site=strtok(NULL," ");
	char *word=strtok(NULL," ");

	while(word)
	{
        /* Adaug în tabel */
        h->add(word, site);
		word=strtok(NULL," ");
	}
	free(row_tok);

    /* Dacă s-a atins factorul de umplere */
    if (h->crowdy()) {
        h = extend(h);
    }
}

/**
 * procesează o comandă de tip GET
 */
void Algorithm::getSites(const std::string &row)
{
	char *row_tok=strdup(row.c_str());
	char *command=strtok(row_tok," ");
	if (strcmp(command,"GET")!=0)
	{
		free(row_tok);
		return;
	}
	
	char *word=strtok(NULL," ");
    
    /* O listă auxiliară, pentru intersecții */
    SiteList* intersection = NULL;

    if (word == NULL) {
        printf("Error!\n");
    }

    if (h->get(word) == NULL) {
        cout << "SITE_NOT_FOUND" << endl;
        free(row_tok);
        return;
    } else {
        intersection = h->get(word)->duplicate();
    }

	while(word)
	{
        if (h->get(word) == NULL) {
            cout << "SITE_NOT_FOUND" << endl;
            delete intersection;
            free(row_tok);
            return;
        } else {
            /* Intersectez cu noua listă */
            intersection->intersectWith(h->get(word));
        }

		word=strtok(NULL," ");
	}

    intersection->print();

    delete intersection;
	free(row_tok);
}

/**
 * procesează o comandă de tip SITE
 *
 * intersecțiile se realizează similar cu cele de la GET
 */
void Algorithm::wordInSite(const std::string &row)
{
	char *row_tok=strdup(row.c_str());
	char *command=strtok(row_tok," ");
	if (strcmp(command,"SITE")!=0)
	{
		free(row_tok);
		return;
	}
	
	char *site=strtok(NULL," ");
	char *word=strtok(NULL," ");
	
    SiteList* intersection = NULL;

    if (word == NULL) {
        cout << "WORD_NOT_FOUND" << endl;
        free(row_tok);
        return;
    }

    if (h->get(word) == NULL) {
        cout << "WORD_NOT_FOUND" << endl;
        free(row_tok);
        return;
    }

    intersection = h->get(word)->duplicate();

	while(word)
	{
        if (h->get(word) == NULL) {
            cout << "WORD_NOT_FOUND" << endl;
            delete intersection;
            free(row_tok);
            return;
        }

        intersection->intersectWith(h->get(word));

		word=strtok(NULL," ");
	}

    SiteNode* p = intersection->first;
    while (p != NULL) {
        if (strcmp(p->site, site)==0) {
            cout << "WORD_FOUND" << endl;
            delete intersection;
            free(row_tok);
            return;
        }
        p = p->next;
    }

    cout << "WORD_NOT_FOUND" << endl;

    delete intersection;
	free(row_tok);
}

void Algorithm::resolve()
{
	string row;
	while ( std::cin.good() )
	{
		std::getline(std::cin,row);
		//nu iau in considerare linii cu mai putin de 3 caractere
		if (row.size()<3)
			continue;
		switch(row[0])
		{
		//PUT
		case 'P':
			indexSite(row);
			break;
		//GET
		case 'G':
			getSites(row);
			break;
		//SITE
		case 'S':
			wordInSite(row);
			break;
		default:
			cout<<"Invalid option"<<endl;
		}
	}
}
