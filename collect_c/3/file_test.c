#include "file.c"

int main(int argc, char const *argv[])
{
	int c;
	FILE *f1, *f2;

	if ((f1 = fileopen("file.c", "r")) == NULL) {
		write(2, "error: could not open the first file", 36);
		return 1;
	}
	if ((f2 = fileopen("file.c.out", "w")) == NULL) {
		write(2, "error: could not create the second file", 39);
		return 2;
	}

	while ((c = getc(f1)) != EOF) {
		putc(c, f2);
	}

	fclose(f1);
	fclose(f2);

	return 0;
}