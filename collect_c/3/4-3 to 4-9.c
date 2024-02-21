#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER 0
#define MATHFUNC 1

double val[MAXVAL];
int valp = 0;
void push(double d) {
	if (valp >= MAXVAL)
		puts("Stack full.");
	else
		val[valp++] = d;
}
double pop() {
	if (valp == 0) {
		puts("Stack Empty");
		return .0;
	} else
		return val[--valp];
}

int buf[BUFSIZ];
int bufp = 0;
/*Pop a character from the stack; if stack is empty, get it from getchar()	*/
int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}
/*Push a char to the stack */
void ungetch(int c) {
	if (bufp >= BUFSIZ)
		puts("Ungetch:Too many chars.");
	else
		buf[bufp++] = c;
}

/* Ex-4.7 */
void ungets(char s[]) {
	int n = strlen(s);
	while (n > 0)
		ungetch(s[--n]);
}
int getop(char s[]) {
	int c, i, type;
	/*Consume Blanks	*/
	while ((c = getch()) == ' ' || c == '\t')
		;

	i = 0;
	s[i] = type = c;

	/*	Ex-4-5	*/
	/*	Check whether a command or math function	*/
	if (islower(c)) {
		while (islower(s[++i] = getch()))
			;

		if (i == 3) /* A Math Function	*/
			type = MATHFUNC;
	}
	/* Handling Minus sign */
	else if (c == '-' && isdigit(s[++i] = getch()))
		/*Next is a Negative Number not Sign */
		c = s[i];

	/*	Check whether an operation or a variable */
	else if (c != '-' && !isdigit(c)) {
		return type;
	}

	/*	Get the Integer Part	*/
	if (isdigit(c)) {

		while (isdigit(s[++i] = getch()))
			;

		/*Get the Fraction Part	*/
		if (s[i] == '.')
			while (isdigit(s[++i] = getch()))
				;
		type = NUMBER;
	}

	/*Push Back */
	ungetch(s[i]);

	s[i] = '\0';
	return type;
}

double atof2(char *s) {
	double val, pow;
	int i, exp, sign;

	/*	Consuming all whiteblanks */
	for (i = 0; isspace(s[i]); i++)
		;

	/*	Sign of the number	 */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;

	/*	Calculate the integer part	*/
	for (val = 0.; isdigit(s[i]); i++) {
		val = val * 10. + s[i] - '0';
	}

	/*	Detect Fraction	*/
	if (s[i] == '.')
		i++;
	for (pow = 1.; isdigit(s[i]); i++) {
		pow *= 10.;
		val = val * 10. + s[i] - '0';
	}

	val = sign * val / pow;

	/*	Detect Scientific Notation	*/
	if (s[i] == 'e' || s[i] == 'E') {
		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			i++;
	}

	/*	Calculate exponent	*/
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + s[i] - '0';

	if (sign == -1)
		while (exp-- > 0)
			val /= 10.;
	else
		while (exp-- > 0)
			val *= 10.;

	return val;
}

/* Handle Math Function sin, cos, tan, exp, pow */
void mathfunc(char s[]) {
	double op2;

	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "tan") == 0)
		push(tan(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else
		printf("Error : %s is not supported.\n", s);
}

void calculator() {
	int type;
	double op1, op2, cval;
	char s[BUFSIZ], var = 0;
	double vars[26] = { .0 }; /* Variables store value */

	while ((type = getop(s)) != EOF)
		switch (type) {
		case NUMBER:
			push(atof2(s));
			break;

			/*	Basic Arithmetic Operations	*/
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			push(pop() / op2);
			break;
		case '%': /* Ex-4-4 */
			op2 = pop();
			push(fmod(pop(), op2));
			break;
		case MATHFUNC: /* sin exp pow */
			mathfunc(s);
			break;

			/*	Assign Value to Variable	*/
		case '=':
			pop(); /* Get Origin Value */

			if (var < 'A' || var > 'Z')
				puts("No such variable.");
			else {
				vars[var - 'A'] = pop();
				var = 0.;
			}

			break;
			/*	Stack Command */
		case '?': /*print top element */
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c': /*clear*/
			valp = 0;
			break;
		case 'd': /*copy top element */
			push((op2 = pop()));
			push(op2);
			break;
		case 's': /* swap top 2 elements */
			op2 = pop();
			push((op1 = pop()));
			push(op2);
			break;

		case '\n': /* End of Expression */
			printf("\t%.8g\n", (cval = pop()));
			break;

		default:
			if (type >= 'A' && type <= 'Z') {
				push(vars[type - 'A']);
				var = type;
			} else if (type == 'v')
				push(cval);
			else
				printf("Error: Unknown Cmd.");
			break;
		}
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	calculator();

	return EXIT_SUCCESS;
}
