/*
C Programming powerUp -Page 97
Function with String
2016-06-26
*/


#include <stdio.h>
#define MAX_LEN 100


int ChaNumOfString(char*, char);


int main(void) 
{

	char str[MAX_LEN];
	char cmp;
	fputs("��� ���ڿ� �Է� : ",stdout);
	gets(str);
	fputs("���� �� ���� �Է� : ",stdout);
	cmp=getchar();

	printf("%c�� ���� : %d \n", cmp, CharNumOfString(str,cmp));


	return 0;
}

int CharNumOfString(char* str, char cmp)
{
	int sum = 0;
	int i = 0;
	while (str[i]!='\0') 
	{
		if (str[i++] == cmp) sum++;
	}



	return sum;

}
