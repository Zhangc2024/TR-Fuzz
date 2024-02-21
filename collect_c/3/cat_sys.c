#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

void error(char *, ...);

int main(int argc, char const *argv[])
{
	int fd;
	int filecopy(int fd1, int fd2);

	if (argc == 1) {
		if (filecopy(0, 1) == EOF) {
			error("cat: cant't write to stdout");
		}
		return 0;
	}

	while (--argc > 0) {
		if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
			error("cat: could not open file %s", *argv);
		}
		if (filecopy(fd, 1) == EOF) {
			error("cat: cant't write to stdout");
		}
		close(fd);
	}

	return 0;
}

int filecopy(int fd1, int fd2) {
	char buf[BUFSIZ];
	int n;

	while ((n = read(fd1, buf, sizeof buf)) > 0) {
		if (write(fd2, buf, n) != n) {
			return EOF;
		}
	}

	return 0;
}

void error(char *fmt, ...) {
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
