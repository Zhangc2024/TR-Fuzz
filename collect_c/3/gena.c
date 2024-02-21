/* c-examples by A.Shtanyuk */
/* gena.c - file generation with random set of characters */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{	
	FILE *fp;
	int ch,mod;
	long num,i;
	fp=fopen(argv[1],"wb");
	num=atol(argv[2]);  // the file size
	mod=atoi(argv[3]);  // random range
	srand(time(NULL));

	for(i=0;i<num;i++)
	{
		ch=rand()%mod;
		fputc(ch,fp);
	}
	fclose(fp);
    return 0;
}


