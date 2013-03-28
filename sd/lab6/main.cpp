#include "hashtable.h"
#include "ctype.h"
#include "stdlib.h"

#define HMAX 10

int hash(char *str) {
    unsigned int i, s=0;
    for (i=0; i<strlen(str); i++) {
        s+=str[i];
    }
    return s % HMAX;
}

int main() {
    Hashtable<char*,int> h(HMAX, hash);

    char left[10], right[10];
    char *p;
    while (scanf("%s = %s", left, right) > 0) {
        if (isdigit(right[0])) { // un numar in dreapta
            p = strdup(left);
            h.put(p, atoi(right));
            printf("%s=%d\n", left, atoi(right));
        } else {   // o var in dreapta
            if (h.hasKey(right)) {
                p = strdup(left);
                h.put(p, h.get(right));
                printf("%s=%d\n", left, h.get(right));
            } else {
                printf("%s is not declared\n", right);
            }
        }
    }

    return 0;
}
