#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1000

int vals[MAXLINE];
int *pval = vals;

#define push(v)	(*pval++ = v)
#define pop()	(*--pval)

int getline1(char *line, int max) {
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';

	return i;
}

/*	Ex 5-10 */
int main(int argc, char *argv[]) {
	int c;	//store first char
	int op2;
	while (--argc > 0) {
		switch ((c = (*++argv)[0])) {
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
		default:
			/*c is a digit */
			if (isdigit(c))
				push(atoi(*argv));
			else
				perror("Illegal Argument.\n");
		}
	}
	printf("%d", pop());

}
