#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>

#define MAXOP 100 
#define NUMBER '0'
#define MATH '1'
#define SIN '2'
#define COS '3'
#define TAN '4'
#define EXP '5'
#define SQRT '6'
#define POW '7'
#define MAXVAL 100 
#define BUFSIZE 100

void push(double); //saves number
double pop(void); //takes out the number
int getop(char []); //get characters, numbers or operands
int getcharf(void); //takes the imput
void ungetch(int); //gets last unsaved charracter
int options(int); //commands
int math(int, char[]); //math
int strindex(char s[], char t[]); //functions

double val[MAXVAL]; //stack
int sp = 0; //val counter
char buf[BUFSIZE]; //last characters
int bufp = 0; //buf counter

/* reverse Polish calculator */
main() {

	int c, cc;
	double op2; //for divisions, substractions amd modulation
	char chars[MAXOP];
	
	printf("-------------------------------\n    AVAILABLE OPERATIONS\n + = adition\n");
	printf(" - = substraction\n * = multplication\n / = division\nsin = sine");
	printf("\ncos = cosine\ntan = tangent\nexp = exponential\nsqrt = square root\npow = power\n");
	printf("-------------------------------\n\tCOMMANDS\nx = print the top values\nd = duplicate the ");
	printf("top value\ns = swap the top 2 values\nc = clear stack\n-------------------------------\n\n");
	
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
			case 'x': 
			case 'd': 
			case 's': 
			case 'c': 
				options(c); break;
			case SIN: 
				push(sin(pop())); break;
			case COS: 
				push(cos(pop())); break;
			case TAN: 
				push(tan(pop())); break;
			case EXP: 
				push(exp(pop())); break;
			case SQRT: 
				push(sqrt(pop())); break;
			case POW: 
				op2 = pop(); push(pow(pop(), op2)); break;
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
	
	if (isalpha(c))
		return math(c, chars);
		
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

int options(int c) {
	
	int cc, op2;
	
	if(c == 'd') {
		val[sp] = val[sp-1]; 
		sp++;
	} else if(c == 's') {
		cc = sp; 
		op2 = val[--sp]; 
		val[sp] = val[--sp]; 
		val[sp] = op2; 
		sp = cc;
	} else if(c == 'c')  
		sp = 0;
	 else if(c == 'x')
		printf("TOPS: %g, %g \n", val[sp-1], val[sp-2]);
}

int math(int c, char chars[]) {
	
	int i = 0, o;
	double op2, n = 0;
	
	chars[i] = c;
	while (isalpha(chars[++i] = c = getcharf()));
	chars[i] = '\0';
	ungetch(c);

	if (strindex(chars, "sin"))
		return SIN;
	if (strindex(chars, "cos"))
		return COS;
	if (strindex(chars, "tan"))
		return TAN;
	if (strindex(chars, "exp"))
		return EXP;		
	if (strindex(chars, "sqrt"))
		return SQRT;
	if (strindex(chars, "pow"))
		return POW;
	if (strindex(chars, "d"))
		return 'd';
	if (strindex(chars, "s"))
		return 's';
	if (strindex(chars, "c"))
		return 'c';
	if (strindex(chars, "x"))
		return 'x';
	
	return '8';
}

int strindex(char s[], char t[]) {
	
	int i, k;
	
	for (i = 0, k = 0; t[k] != '\0' && s[i] == t[k]; i++, k++);
		if (k > 0 && t[k] == '\0' && s[i] == '\0')
			return i + 1;

	return 0;
}

