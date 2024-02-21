#include <stdio.h>

int main (void)
{
FILE *stream;
char tempstring[] = "String to be written";
if( (stream = tmpfile()) == NULL ) {
perror("Could not open new temporary file\n");
return (-1);
}
printf( "Temporary file %d was created\n"); 

/* write data to tmp file */
/* ... */
_rmtmp();
/*The temp file created in the above code is always readable and
writable by all users. */
}

