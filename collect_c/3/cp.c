#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdlib.h>

#define PERMS 0666 /* RW for owner, group, others */

void error(char *, ...);

int main(int argc, char const *argv[])
{
	int fd, td;
	char buf[BUFSIZ];
	int n;

	if (argc != 3) {
		error("Usage: cp from to");
	}

	if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
		error("cp: could not open file %s", *argv);
	}
	if ((td = creat(*++argv, PERMS)) == -1) {
		error("cp: could not create file %s, mode %3o", *argv, PERMS);
	}

	while ((n = read(fd, buf, sizeof buf)) > 0) {
		if (write(td, buf, n) != n) {
			error("cp: write error on file %s", *argv);
		}
	}

	close(fd);
	close(td);

	return 0;
}

void error(char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1); // exit and close all file descriptors
}
