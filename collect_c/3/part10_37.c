

#include <stdio.h>


int main(void)
{

	int num, i;

	FILE *fp = fopen("numeric.data","wb");

	if (fp == NULL)
	{
		puts("���� 'numeric.data'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("������ ���� : %d", i+1);
		scanf("%d", &num);
		fwrite(&num,sizeof(int),1,fp);
	}

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");


	fp = fopen("numeric.data", "rb");
	if (fp == NULL)
	{
		puts("���� 'numeric.data'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}
	for (i = 0; i < 5;i++)
	{
		fread(&num, sizeof(int), 1, fp);
		printf("���� ���� : %d \n", num);
	}

	

	return 0;
}