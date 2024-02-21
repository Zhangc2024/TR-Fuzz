/* fsize: print file sizes in a directory recursively */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* flags to read and write */
#include <sys/types.h>	/* typedefs */
#include <sys/stat.h>	/* structure returned by stat */
#include <sys/dir.h>	/* local directory structure */
#include <stdlib.h>
#include "dirent.h"

#define MAX_PATH 1024

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

int main(int argc, char const *argv[])
{
	if (argc == 1) { /* default: current directory */
		fsize(".");
	} else {
		while (--argc > 0) {
			fsize((char *) *++argv);
		}
	}
	return 0;
}

/* fsize: print size of file "name" */
void fsize(char *name) {
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8lld %s\n", stbuf.st_size, name);
}

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *)) {
	char name[MAX_PATH];
	Dirent *dp;
	DIRD *dfd;

	if ((dfd = opend(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}

	while ((dp = readd(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0
		 || strcmp(dp->name, "..") == 0) {
			continue; /* skip self and parent */
		}

		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s is too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closed(dfd);
}

int fstat(int fd, struct stat *);

/* opend: open a directory for readd calls */
DIRD *opend(char *dirname) {
	int fd;
	struct stat stbuf;
	DIRD *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
	 || fstat(fd, &stbuf) == -1
	 || (stbuf.st_mode & S_IFMT) != S_IFDIR
	 || (dp = (DIRD *)malloc(sizeof(DIRD))) == NULL) {
		return NULL;
	}

	dp->fd = fd;
	return dp;
}

/* closed: close directory opened by opend */
void closed(DIRD *dp) {
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

/* readd: read directory entries in sequence */
Dirent *readd(DIRD *dp) {
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, NAME_MAX);
		d.name[NAME_MAX] = '\0';
		return &d;
	}

	return NULL;
}
