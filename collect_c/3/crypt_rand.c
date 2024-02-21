/* c-examples by A.A.Shtanyuk */
/* crypt_rand.c  -  encrypting with xor and rand() */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int ch1,ch2;
	clock_t start,finish;
	double duration;

	if(argc<4) {
		puts("Usage: crypt file1 file2 file3");
		exit(1);
	}

	fp1=fopen(argv[1],"rb");
	fp2=fopen(argv[2],"wb");
	start = clock();
	srand(33);
	while((ch1=fgetc(fp1))!=EOF)
	{
		ch2=ch1^rand();
		fputc(ch2,fp2);
	}
	fcloseall();
	printf("Encrypted!\n");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%5.1f seconds\n", duration );

	
	fp1=fopen(argv[2],"rb");
	fp2=fopen(argv[3],"wb");
	start = clock();
	srand(33);
	while((ch1=fgetc(fp1))!=EOF)
	{
		ch2=ch1^rand();
		fputc(ch2,fp2);
	}
	fcloseall();
	printf("Decrypted!\n");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%5.1f seconds\n", duration );

	return 0;
}


