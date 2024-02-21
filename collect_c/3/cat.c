#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files */
int main(int argc, char const *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	const char *prog = argv[0];

	if (argc == 1) {
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) != NULL) {
				filecopy(fp, stdout);
				fclose(fp);
			} else {
				fprintf(stderr, "%s: could not open file %s\n", prog, *argv);
				exit(1); // close all opened files
			}
		}
	}

	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}

	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp) {
	int c;
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
}
