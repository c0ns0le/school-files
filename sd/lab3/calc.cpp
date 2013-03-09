#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

int extract(Stack<int, 100> &s, int &a, int &b) {
	if (s.isEmpty()) {
		printf("Error.\n");
		return 0;
	}
	a = s.pop();

	if (s.isEmpty()) {
		printf("Error.\n");
		return 0;
	}
	b = s.pop();

	return 1;
}

int main(int argc, char const *argv[])
{
	Stack<int, 100> s;

	char st[10];
	int a, b;
	while (1) {
		scanf("%s", st);
		if (feof(stdin)) {
			break;
		}
		if (strcmp(st, "+") == 0) {
			if (!extract(s, a, b)) {
				printf("Error.\n");
				return 1;
			}
			s.push(a+b);
		} else if (strcmp(st, "-") == 0) {
			if (!extract(s, a, b)) {
				printf("Error.\n");
				return 1;
			}
			s.push(b-a);
		} else if (strcmp(st, "*") == 0) {
			if (!extract(s, a, b)) {
				printf("Error.\n");
				return 1;
			}
			s.push(a*b);
		} else if (strcmp(st, "/") == 0) {
			if (!extract(s, a, b)) {
				printf("Error.\n");
				return 1;
			}
			s.push(b/a);
		} else if (strcmp(st, "^") == 0) {
			if (!extract(s, a, b)) {
				printf("Error.\n");
				return 1;
			}
			s.push(pow(b,a));
		} else {
			s.push(atoi(st));
		}
	}

	a = s.pop();
	if (!s.isEmpty()) {
		printf("Error.\n");
		return 1;
	}

	printf("Rezultat: %d\n", a);

	return 0;
}