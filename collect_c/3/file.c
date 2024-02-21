#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define PERMS 		0666 /* RW for owner, group and others */

#ifndef NULL
#define NULL 		0
#endif

#define EOF 		(-1)
#define BUFSIZ 		1024
#define OPEN_MAX 	20 /* max files open at once */

typedef struct _iobuf {
	int 	cnt;
	char 	*ptr;
	char 	*base;
	int 	flag;
	int 	fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin 	(&_iob[0])
#define stdout 	(&_iob[1])
#define stderr 	(&_iob[2])

enum _flags {
	_READ 	= 01,
	_WRITE  = 02,
	_UNBUF	= 04,
	_EOF	= 010, // 8
	_ERR	= 020  // 16
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)		(((p)->flag & _EOF) != 0)
#define ferror(p)	(((p)->flag & _ERR) != 0)
#define fileno(p)	((p)->fd)

#define getc(p)		(--(p)->cnt >= 0 \
					? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)	(--(p)->cnt >= 0 \
					? *(p)->ptr++ = (x) : _flushbuf(x, p))

#define getchar()	getc(stdin)
#define putchar(x)	putc(x, stdout)

#define fflush(p)	(_flushbuf(0, p))
#define fclose(p)	{if ((p->flag & _WRITE) != 0) _flushbuf(0, p); {p->flag = 0; free(p->base); p->base = p->ptr = NULL; }}

/* fileopen: open a file, return a file ptr to it */
FILE *fileopen(char *name, char *mode) {
	FILE *ptr;

	for (ptr = _iob; ptr < _iob + OPEN_MAX; ptr++) {
		if ((ptr->flag & (_READ | _WRITE)) == 0) {
			// found an empty slot
			break;
		}
	}

	if (ptr >= _iob + OPEN_MAX) {
		return NULL;
	}

	if (*mode == 'r') {
		ptr->fd = open(name, O_RDONLY, 0);
		ptr->flag = _READ;
	} else if (*mode == 'w') {
		ptr->fd = creat(name, PERMS);
		ptr->flag = _WRITE;
	} else if (*mode == 'a') {
		if ((ptr->fd = open(name, O_WRONLY, 0)) == -1) {
			ptr->fd = creat(name, PERMS);	
		}
		ptr->flag = _WRITE;
		if (ptr->fd == -1) {
			return NULL;
		}
		lseek(ptr->fd, 0L, 2); // seek to the end of the file
	} else {
		// unknown mode
		return NULL;
	}

	if (ptr->fd == -1) {
		return NULL;
	}

	ptr->cnt = 0;
	ptr->base = ptr->ptr = NULL;

	return ptr;
}

int _fillbuf(FILE *p) {
	int bufsize = (p->flag & _UNBUF) ? 1 : BUFSIZ;
	int n;
	char buf[bufsize];

	if ((p->flag & (_READ | _EOF | _ERR )) != _READ) { // not readable, or EOF or ERR occured
		return EOF;
	}

	if ((n = read(p->fd, buf, bufsize)) > 0) {
		p->cnt = n-1;
		p->base = (char *)malloc(n + 1);
		strcpy(p->base, buf);
		p->ptr = p->base;
	}

	if (n == 0) {
		p->flag |= _EOF;
		return EOF;
	}
	if (n < 0) {
		p->flag |= _ERR;
		return EOF;
	}

	return *p->ptr++;
}

int _flushbuf(int c, FILE *p) {
	int bufsize = (p->flag & _UNBUF) ? 1 : BUFSIZ;
	int n;

	if ((p->flag & (_WRITE | _ERR)) != _WRITE) { // not writable or ERR occured
		return EOF;
	}

	if (p->base != NULL) {
		n = p->ptr - p->base;
		if (write(p->fd, p->base, n) != n) {
			p->flag |= _ERR;
		}
	} else {
		p->base = (char *)malloc(bufsize);
	}
	
	p->ptr = p->base;
	p->cnt = bufsize - 1;
	*p->ptr++ = c;

	return c;
}

/* init stdin, stdout and stderr */
FILE _iob[OPEN_MAX] = {
	{ 0, (char *) 0, (char *) 0, _READ, 0 },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
