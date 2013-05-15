/**
  *    Duma Andrei Dorian
  *    315 CA
  */

#include "visit.h"
#include <string.h>

Visit::Visit() {
    this->url[0] = '\0';
    this->date = -1;
}

Visit::Visit(char* url, int date) {
    strcpy(this->url, url);
    this->date = date;
}
