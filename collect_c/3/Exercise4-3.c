#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define MAXOP 100 
#define NUMBER '0'
#define MAXVAL 100 
#define BUFSIZE 100

void push(double); //saves number
double pop(void); //takes out the number
int getop(char []); //get characters, numbers or operands
int getcharf(void); //takes the imput
void ungetch(int); //gets last unsaved charracter

double val[MAXVAL]; //stack
int sp = 0; //val counter
char buf[BUFSIZE]; //last characters
int bufp = 0; //buf counter

/* reverse Polish calculator */
main() {

	int c, cc;
	double op2; //for divisions, substractions amd modulation
	char chars[MAXOP];

	while ((c = getop(chars)) != EOF) {
		switch (c) {
			case NUMBER: 
				push(atof(chars)); break;
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
			case '%': 
				op2 = pop(); 
				if (op2 != 0) 
					push(((int) pop()) % ((int) op2)); 
				else
					printf("error: zero divisor\n"); break;
			case '\n': 
				printf("      =\t%.8g\n", pop()); break;
			default:
				printf("error: unknown command %s\n", chars); break;
		}
	}
	
	return 0;
} 

void push(double f) {
	
	if (sp < MAXVAL)
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

int getop(char chars[]) {

	int i, c;

	while ((chars[0] = c = getcharf()) == ' ' || c == '\t');
	chars[1] = '\0';

	i = 0;
	if (c == '-')                     
		if (!isdigit(chars[++i] = c = getcharf())) {
			ungetch(c);               
			c = chars[0];
		}

	if (!isdigit(c) && c != '.')
		return c; 
	
	if (isdigit(c)) {
		while (isdigit(chars[++i] = c = getcharf()));
	}
	if (c == '.') 
		while (isdigit(chars[++i] = c = getcharf()));

	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
	
}

int getcharf(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();
	
}

void ungetch(int c) {

	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

