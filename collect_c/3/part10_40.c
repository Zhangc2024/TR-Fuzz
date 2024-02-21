/*
C Programming powerUp -Page 253
File Copy
2016-06-27
*/


#include <stdio.h>
#define MAX_STR 100

int main(void)
{

	int readCnt;
	char src[MAX_STR];
	char dest[MAX_STR];
	char dataBuff[MAX_STR];


	FILE *fp_src;
	FILE *fp_dest;

	fputs("원본 파일 이름 : ",stdout);
	gets(src);

	fputs("복사본 이름 : ",stdout);
	gets(dest);

	fp_src = fopen(src,"rb");
	if (fp_src == NULL) return -1;
	fp_dest = fopen(dest, "wb");
	if (fp_dest == NULL) return -1;

	while (1)
	{
		readCnt = fread(dataBuff, 1, MAX_STR, fp_src);
		if (readCnt < 1) break;
		fwrite(dataBuff, 1, readCnt, fp_dest);
	}
	puts("복사 완료!");
	fclose(fp_src);
	fclose(fp_dest);



	return 0;
}