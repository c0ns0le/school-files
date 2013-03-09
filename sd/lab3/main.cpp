#include <iostream>
#include "stack.h"
#include <stdio.h>
#include <string.h>

int precedence(char c) {
	static int p = 2;
	switch(c) {
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return ++p;
		case '(': return 0;
		case ')': return 0;
	}
}

int main(int argc, char const *argv[])
{
	// Stack<int, 2> s;
	// s.push(3);
	// s.push(5);
	// s.push(2);
	// std::cout << s.peek() << std::endl;
	// std::cout << s.pop() << std::endl;
	// std::cout << s.pop() << std::endl;
	// std::cout << s.isEmpty() << std::endl;

	Stack<char, 100> c;

	char st[10], p;
	while (1) {
		scanf("%s", st);
		if (feof(stdin)) {
			break;
		}
		if (strcmp(st, "(") == 0) {
			c.push('(');
		} else if (strcmp(st, ")") == 0) {
			while ( !c.isEmpty() && (p = c.pop()) != '(') {
				printf("[%c]", p);
			}
		} else if (strcmp(st, "+") == 0) {
			while ( !c.isEmpty() && precedence(c.peek()) >= precedence('+') ) {
				printf("[%c]", c.pop());
			}
			c.push('+');
		} else if (strcmp(st, "-") == 0) {
			while ( !c.isEmpty() && precedence(c.peek()) >= precedence('-') ) {
				printf("[%c]", c.pop());
			}
			c.push('-');
		} else if (strcmp(st, "*") == 0) {
			while ( !c.isEmpty() && precedence(c.peek()) >= precedence('*') ) {
				printf("[%c]", c.pop());
			}
			c.push('*');
		} else if (strcmp(st, "/") == 0) {
			while ( !c.isEmpty() && precedence(c.peek()) >= precedence('/') ) {
				printf("[%c]", c.pop());
			}
			c.push('/');
		} else if (strcmp(st, "^") == 0) {
			while ( !c.isEmpty() && precedence(c.peek()) >= precedence('^') ) {
				printf("[%c]", c.pop());
			}
			c.push('^');
		} else {
			// este numar
			printf("[%s]", st);
		}
	}
	do {
		printf("[%c]", c.pop());
	} while (!c.isEmpty());

	return 0;
}