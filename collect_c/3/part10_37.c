

#include <stdio.h>


int main(void)
{

	int num, i;

	FILE *fp = fopen("numeric.data","wb");

	if (fp == NULL)
	{
		puts("파일 'numeric.data'가 열리지 않았습니다.");
		return -1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("저장할 숫자 : %d", i+1);
		scanf("%d", &num);
		fwrite(&num,sizeof(int),1,fp);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");


	fp = fopen("numeric.data", "rb");
	if (fp == NULL)
	{
		puts("파일 'numeric.data'가 열리지 않았습니다.");
		return -1;
	}
	for (i = 0; i < 5;i++)
	{
		fread(&num, sizeof(int), 1, fp);
		printf("읽은 숫자 : %d \n", num);
	}

	

	return 0;
}