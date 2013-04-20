#include "visit.h"
#include <string.h>
#include <stdlib.h>

Visit::Visit() {
    this->url[0] = '\0';
    this->date = -1;
}

Visit::Visit(char* url, int date) {
    strcpy(this->url, url);
    this->date = date;
}
