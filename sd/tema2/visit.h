#ifndef __VISIT_H
#define __VISIT_H

class Visit {
    public:
        char* url;
        int date;

        Visit();
        Visit(char* url, int date);
        ~Visit();
};

#endif
