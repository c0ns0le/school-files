#include "visit.h"
#include <string.h>
#include <stdlib.h>

Visit::Visit() {
    this->url = NULL;
    this->date = 0;
}

Visit::Visit(char* url, int date) {
    this->url = strdup(url);
    this->date = date;
}
    
Visit::~Visit() {
    //free(this->url);
}
