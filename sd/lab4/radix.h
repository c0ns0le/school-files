#include "queue.h"
#include <string.h>

#define N_DIGITS 5

struct Number {
public:
    int number;
    int digits[N_DIGITS];
};

void setupNumber(Number &n) {
    memset(n.digits, 0, N_DIGITS*sizeof(int));
    int m = n.number, i = 0;
    while (m != 0) {
        n.digits[i++] = m % 10;
        m /= 10;
    }
}

void RadixSort(int vector[], int length) {
    Queue<Number, 100> digits[10];
    Queue<Number, 100> numbers;
    
    Number n;
    int i, j;
    for (i = 0; i<length; i++) {
        n.number = vector[i];
        setupNumber(n);
        numbers.enqueue(n);
    }
    
    for (i = 0; i<N_DIGITS; i++) {
        printf("Digit: %d\n", i);
        while ( !numbers.isEmpty() ) {
            n = numbers.dequeue();
            digits[n.digits[i]].enqueue(n);            
            printf("numbers size: %d \n", numbers.size);
        }
        for (j = 0; j < 10; j++) {
            while ( !digits[j].isEmpty() ) {
                printf("digits[%d] size: %d \n", j, numbers.size);
                numbers.enqueue(digits[j].dequeue());
            }
        }
    }
    printf("aici!\n");
    for (i = 0; i<length; i++) {
        vector[i] = numbers.dequeue().number;
    }
}