#ifndef __INVERTEDINDEX_H__
#define __INVERTEDINDEX_H__

#include <stdio.h>
#include <string.h>

#define DELIM   " \r\n\t.,?!;:'\"\\/[]{}()"

/* Vector de întregi
 * v   - vectorul
 * n   - numărul de elemente
 * cap - capacitatea vectorului
 * */
typedef struct Array {
    int     *v;
    int     n, cap;
} Array_t;

/* O intrare în Map_t */
typedef struct Entry {
    char    *word;
    Array_t   documents;
} Entry_t;

/* Nod pentru o listă simplu înlănțuită */
typedef struct Node {
    struct Node    *next;
    Entry_t          data;
} Node_t;

/* Reține o mapare Cheie - Valoare (în cazul nostru char* - Array_t)
 *
 * buckets - vector de liste simplu înlănțuite.
 * size    - mărimea lui buckets.
 */
typedef struct Map {
    Node_t    **buckets;
    int     size;
} Map_t;

const Array_t emptyArray = {NULL, 0, 0};

/* contructor; aloca memorie pentru un element */
Array_t* new_array(void) {
  Array_t *a = malloc(sizeof(Array_t));
  a->n = 0;
  a->cap = 1;
  a->v = malloc(sizeof(int));
  
  return a;
}

/* adauga id-ul docID in array-ul a */
void add_id(Array_t *a, int docID) {
  /* verific daca nu este deja in array
   * ar trebui sa fie pe ultima pozitie */
  if ( a->n > 0 && a->v[a->n - 1] == docID ) {
    return;
  }
  
  /* adaugare */
  (a->n)++;
  if ( a->n > a->cap ) {
    a->cap *= 2;
    a->v = realloc(a->v, a->cap * sizeof(int));
  }
  a->v[a->n - 1] = docID;
}

/* Întoarce o valoare reprezentând întregul asociat unui șir de caractere
 *
 * Se folosește pentru a decide în ce bucket din Map_t va ajunge șirul de
 * caractere.
 * e.g. "ana" va ajunge în buckets[hash("ana") % size]
 */
unsigned long hash(unsigned char *str) {
	unsigned long hash = 5381;
	int c;

	while(c = *str++) {
 		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return hash;
}

/* constructor */
Node_t* new_node(char *key, int docID) {
  Node_t *node = malloc( sizeof( Node_t ) );

  node->next = NULL;
  node->data.word = strdup(key);
  node->data.documents = *new_array();
  node->data.documents.n = 1;
  node->data.documents.v[0] = docID;

  return node;
}

/* Adauga id-ul unui fisier la valorile cheii key din dictionar.
 * Se folosește următoarea rutină:
 *
 * Se parcurge lista aflată în buckets[hash(key) % size]
 *
 * Dacă se întâlnește un Entry_t având cheia key, se adaugă în Array_t-ul din
 * Entry_t.
 *
 * Altfel, se adaugă în listă un nou Entry_t având cheia key și un Array_t ce
 * conține doar docID.
 */
void put_doc(Map_t *map, char *key, int docID) {
  Node_t *p = map->buckets[hash(key) % map->size];
  Node_t *previous = NULL;

  if ( p == NULL ) {
    map->buckets[hash(key) % map->size] = new_node(key, docID);
  } else {

    while ( p != NULL ) {
      if ( strcmp(key, p->data.word) == 0 ) {
        /* adaug docID-ul aici */
        add_id( &p->data.documents, docID );
        return;
      }
      previous = p;
      p = p->next;
    }

    previous->next = new_node(key, docID);
  }
}

/* Returneaza un Array_t cu ID-urile documentelor în care apare cheia key */
Array_t get_docs(Map_t *map, char *key) {
  Node_t *p = map->buckets[hash(key) % map->size];
  
  while ( p != NULL ) {
    if ( strcmp(key, p->data.word) == 0 ) {
      return p->data.documents;
    }
    p = p->next;
  }

  return emptyArray;
}

/* Realizeaza intersectia a doua multimi de indici de fisiere. */
Array_t intersection(const Array_t files1, const Array_t files2) {
  /* cele doua siruri de indici sunt sortate */
  Array_t *result = new_array();
  
  int i = 0, j = 0;
  while ( i < files1.n && j < files2.n ) {
    if ( files1.v[i] < files2.v[j] ) {
      ++i;
    } else if ( files1.v[i] > files2.v[j] ) {
      ++j;
    } else {
      add_id(result, files1.v[i]);
      ++i; ++j;
    }
  }

  return *result;
}
  

/* Realizeaza reuniunea a doua multimi de indici de fisiere. */
Array_t reunion(const Array_t files1, const Array_t files2) {
  /* cele doua siruri de indici sunt sortate */
  Array_t *result = new_array();
  
  int i = 0, j = 0;
  while ( i < files1.n && j < files2.n ) {
    if ( files1.v[i] < files2.v[j] ) {
      add_id(result, files1.v[i]);
      ++i;
    } else if ( files1.v[i] > files2.v[j] ) {
      add_id(result, files2.v[j]);
      ++j;
    } else {
      add_id(result, files1.v[i]);
      ++i; ++j;
    }
  }
  while ( i < files1.n ) {
    add_id(result, files1.v[i++]);
  }
  while ( j < files2.n ) {
    add_id(result, files2.v[j++]);
  }
  
  return *result;
}

/* Elibereaza memoria folosita de dictionarul map */
void free_memory(Map_t *map) {
  int i;
  Node_t *p, *next;

  for ( i = 0; i < map->size; ++i ) {
    p = map->buckets[i];

    while ( p != NULL ) {
      next = p->next;

      free(p->data.word);
      free(p->data.documents.v);
      free(p);

      p = next;
    }
  }

  free(map->buckets);
}

/* Estimeaza dimensiunea potrivita pentru hash table */
int estimate_table_size(void) {
  FILE *fi = fopen("input.in", "r"), *f;
  int n, i, file_size, estimated_size = 0;

  fscanf(fi, " %d ", &n);

  char filename[30], *p;
  for ( i=0; i<n; i++ ) {
    /* citire filename */
    fgets(filename, sizeof(filename), fi);

    /* eliminare newline */
    p = strchr(filename, '\n');
    if ( p != NULL ) {
        *p = '\0';
    }
    p = strchr(filename, '\r');
    if ( p != NULL ) {
        *p = '\0';
    }

    /* deschiderea fisierului #i */
    f = fopen(filename, "rb");

    /* determinare dimensiune in octeti,
       tinand cont de faptul ca sunt 6 caractere per cuvant, in medie */
    fseek(f, 0L, SEEK_END);
    file_size = ftell(f);
    estimated_size += file_size / 6;

    fclose(f);
  }

  fclose(fi);

  /* un raport dimensiune/estimare de 1.25, pentru eficienta */
  return estimated_size * 125 / 100;
}

/* Scrie continutul array-ului array pe o linie, in fisierul f */
void print_array(FILE *f, Array_t array) {
  int i;
  for (i = 0; i < array.n; i++) {
    fprintf(f, " %d", array.v[i]);
  }
  fprintf(f, "\n");
}

/* Functia ce va contine rezolvarea problemei. Tot aici va fi construit si
 * dictionarul pe baza regulilor stabilite. */
void solve() {
  /* initializare dictionar */
  Map_t map;
  map.size = estimate_table_size();
  map.buckets = calloc(map.size, sizeof(Node_t *));

  /* fisier de intrare */
  FILE *fi = fopen("input.in", "r");

  /* numar de fisiere */
  int n;
  fscanf(fi, " %d ", &n);

  /* procesare fisiere */
  int i;
  FILE *f;
  char filename[30], *word, line[1000000], *p;
  for ( i=0; i<n; i++ ) {
    /* citire filename */
    fgets(filename, sizeof(filename), fi);

    /* eliminare newline */
    p = strchr(filename, '\n');
    if ( p != NULL ) {
        *p = '\0';
    }
    p = strchr(filename, '\r');
    if ( p != NULL ) {
        *p = '\0';
    }

    /* deschiderea fisierului #i */
    f = fopen(filename, "r");

    /* citire linie cu linie */
    while ( fgets(line, sizeof(line), f) != NULL ) {

      /* tokenizare */
      word = strtok(line, DELIM);
      while ( word != NULL ) {
      	/* adaugare cuvant */
      	put_doc(&map, word, i);

      	word = strtok(NULL, DELIM);
      }
    }

    /* inchidere fisier */
    fclose(f);
  }

  /* deschidere fisier de iesire */
  FILE *fo = fopen("output.out", "w");

  /* numar de query-uri */
  int m;
  fscanf(fi, "%d\n", &m);

  /* procesare query-uri */
  int operation;
  Array_t total = emptyArray;
  char query[1000];
  for ( i=0; i<m; i++ ) {
    /* citire query */
    fgets(query, sizeof(query), fi);

    /* eliminare newline */
    p = strchr(query, '\n');
    if ( p != NULL ) {
        *p = '\0';
    }
    p = strchr(query, '\r');
    if ( p != NULL ) {
        *p = '\0';
    }

    /* afisare "query:" */
    fprintf(fo, "%s:", query);

    /* tokenizare */
    word = strtok(query, " \r\n");
    total = get_docs(&map, word);

    while ( ( word = strtok(NULL, " \r\n") ) != NULL ) {

        if ( strcmp(word, "&") == 0 ) {
            /* urmeaza o intersectie */
            operation = 1;
        } else if ( strcmp(word, "|") == 0 ) {
            /* urmeaza o reuniune */
            operation = 2;
        }

        word = strtok(NULL, " \r\n");

        switch ( operation ) {
            case 1: total = intersection(total, get_docs(&map, word)); break;
            case 2: total = reunion(total, get_docs(&map, word)); break;
        }
    }

    print_array(fo, total);
  }

  fclose(fo);
  
  /* eliberare memorie */
  free_memory(&map);
}
	

#endif
