#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100
#define LINES 100
#define DEFLINES 10

void error(char*);
int getline1(char*, int);

/*	Ex 5-13 tail -n	*/
int main(int argc, char *argv[]) {
	int n, spcs, cur, last = 0, len, nlines = 0;
	char *linesptr[LINES]; /* Pointers to lines */
	char line[MAXLEN]; /* 	Current Line Read	*/
	char *buf;/*	Memory alloced to store lines */
	char *p;
	char *bufend;
	/* Check Format */
	if (argc == 1)
		n = DEFLINES;
	else if (argc == 2 && (*++argv)[0] == '-')
		n = atoi(++*argv);
	else
		error("Format : tail -n");

	/* Check if n is in correct range */
	if (n < 0 || n > LINES)
		n = LINES;

	/*	Alloc Spaces for lines	*/
	if (!(buf = malloc(spcs = n * MAXLEN)))
		error("Not enough memory.");
	p = buf;
	bufend = buf + spcs;

	/*	Read Lines Main Loop	*/
	while ((len = getline1(line, MAXLEN)) > 0) {
		/*	buffer wrap up	*/
		if (p + len + 1 > bufend)
			p = buf;

		/*	wrap up lines	*/
		if (last >= MAXLEN)
			last = 0;

		/*	Store Line	*/
		linesptr[last++] = p;
		strcpy(p, line);
		p += len + 1;
		nlines++;
	}

	/*	Check if n is in correct range	*/
	n = (n > nlines) ? nlines : n;

	/*	Set first line printed	*/
	if ((cur = last - n) < 0)
		cur += LINES;

	/*	Print Loop	*/
	for (; cur != last; cur = (cur + 1) % LINES)
		printf("%s", linesptr[cur]);


	free(buf);
	return EXIT_SUCCESS;
}

/*	Print Error Msg and Exit 	*/
void error(char *s) {
	puts(s);
	exit(1);
}

int getline1(char dst[], int max) {
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		dst[i] = c;

	if (c == '\n')
		dst[i++] = c;

	dst[i] = '\0';

	return i;
}
