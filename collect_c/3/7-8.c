#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define MAXPG 66	/*	Max Lines one page has	*/
#define MAXBTM 3	/*	Blank Lines one page has at the bottom */
#define MAXTOP 5	/* Heading Lines one page has	*/
#define MAXLEN 1000 /* Max Length of a Line	*/

static size_t lno = 0;
static size_t pgno = 0;

/*	Ex 7-8	*/
int main(int argc, char **argv) {

}

void fileprint(FILE *fp, char *fname) {
	char s[MAXLEN];
	void heading(char*);

	while (fgets(s, MAXLEN, fp)) {
		if (!lno)
			heading(fname);
		if (fputs(s, stdout) == EOF) {
			fprintf(stderr,
					"Error Occured in %s when writing to output file at line %d\n",
					__FILE__, __LINE__ - 2);
			exit(EXIT_FAILURE);
		}

		/*	Update Line Number	*/
		lno++;
		if (!(lno %= (MAXPG - MAXBTM)))
			fprintf(stdout, "\f");
	}

}

/*	Print Heading Lines of a new page
 * Called When line number = 0*/
void heading(char *fname) {
	lno = 3;
	fprintf(stdout, "\n\n%s\tpage\t%d\n", fname, pgno);
	for (; lno < MAXTOP; lno++)
		fprintf(stdout, "\n");
}
