#include <fcntl.h>
#include <stdio.h>
#include "unistd.h"
#define PERMS 066

/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flag.is_read == 0 && fp->flag.is_write == 0)
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt  = 0;
    fp->base = NULL;
    fp->flag.is_unbuf = 0;
    fp->flag.is_buf = 1;
    fp->flag.is_eof = 0;
    fp->flag.is_err = 0;
    if (*mode == 'r') {
        fp->flag.is_read = 1;
        fp->flag.is_write = 0;
    } else {
        fp->flag.is_read = 0;
        fp->flag.is_write = 1;
    }

    return fp;
}


/* _fillbuf: allocate and fill input buff */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if (fp->flag.is_read == 0 ||
        fp->flag.is_eof == 1 ||
        fp->flag.is_err == 1 )
        return EOF;
    bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag.is_eof = 1;
        else
            fp->flag.is_err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}