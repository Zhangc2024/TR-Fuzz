#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define MAX 100 
#define NUMBER '0' 

void push(double);
double pop(void);
int getop(char []);

int sp = 0; 
double val[MAX]; 

main() {

	int type;
	double op2;
	char s[MAX];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER: 
				push(atof(s)); break;
			case '+': 
				push(pop() + pop()); break;
			case '*': 
				push(pop() * pop()); break;
			case '-': 
				op2 = pop(); push(pop() - op2); break;
			case '/': 
				op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else
					printf("error: zero divisor\n"); break;
			case '\n': 
				printf("\t%.8g\n", pop()); break;
			default:
				printf("error: unknown command %s\n", s); break;
		}
	}
	
	return 0;
} 

void push(double f) {
	
	if (sp < MAX)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
		
}

double pop(void) {
	
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
	
} 

int getop(char s[]) {
	
	static int getch = 0;
	int i, c;
	
	if(getch)
		c = getch;
	else 
		c = getchar();
	
	while ((s[0] = c) == ' ' || c == '\t')
		c = getchar();
	s[1] = '\0';
	getch = 0;
	if (!isdigit(c) && c != '.')
		return c; 
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getchar()));
	if (c == '.') 
		while (isdigit(s[++i] = c = getchar()));
			s[i] = '\0';

	if (c != EOF)
		getch = c;
		
	return NUMBER;
	
}

