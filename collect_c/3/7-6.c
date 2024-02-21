#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define MAXLEN	1000
/*	Ex 7-6	 */
int main(int argc, char *argv[]) {

	FILE *fp1, *fp2;
	char *f1, *f2, s1[MAXLEN], s2[MAXLEN];

	/*	Check number of arguments	*/
	if (argc != 3) {
		perror("Expects two files.");
		exit(EXIT_FAILURE);
	}

	/*	Open Files	*/
	if (!(fp1 = fopen(argv[1], "r"))) {
		/*	Error Occurs	*/
		fprintf(stderr, "%s cant open file %s at line %d\n", __FILE__, argv[1],
		__LINE__ - 3);
		exit(EXIT_FAILURE);
	}

	if (!(fp2 = fopen(argv[2], "r"))) {
		/*	Error Occurs	*/
		fprintf(stderr, "%s cant open file %s at line %d\n", __FILE__, argv[2],
		__LINE__ - 3);
		exit(EXIT_FAILURE);
	}

	/*	Compare lines	*/
	while ((f1 = fgets(s1, sizeof(s1), fp1))
			&& (f2 = fgets(s2, sizeof(s2), fp2)) && strcmp(s1, s2) == 0)
		;

	/*Check Failures	*/
	if (ferror(fp1)) {
		fprintf(stderr, "%s cant read file %s at line %d", __FILE__, argv[1],
		__LINE__ - 6);
		exit(EXIT_FAILURE);
	}
	if (ferror(fp2)) {
		fprintf(stderr, "%s cant read file %s at line %d", __FILE__, argv[2],
		__LINE__ - 12);
		exit(EXIT_FAILURE);
	}

	/*	Print Compare Results	*/
	if (feof(fp1) && feof(fp2))
		printf("Two files same.\n");
	else if (feof(fp2))
		printf("File1:%s\nFile2 reaches the end.\n", s1);
	else if (feof(fp1))
		printf("File1 reaches the end\nFile2: %s\n", s2);
	else
		printf("File1: %s\nFile2: %s\n", s1, s2);

	return EXIT_SUCCESS;
}
