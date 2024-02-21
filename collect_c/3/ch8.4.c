#include <stdio.h>
#include <fcntl.h>
#include "unistd.h"

int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) > 0)
        return read(fd, buf, n);
    else
        return -1;
}

main(){
    int fd;
    int n;
    char buf[BUFSIZ];
    int a;

    if ((fd = open("a", O_RDONLY)) == -1)
        printf("cat: can't open a");
    else {
        a = get(fd, 1, buf, 3);
        printf("read %d", a);
    }
}
