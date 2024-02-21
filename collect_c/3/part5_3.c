/*
C Programming powerUp -Page 79
문자의 길이순 정렬
2016-06-26
*/

#include<stdio.h>
#define MAX_LEN 100


int strLen(char* str) 
{
	int len = 0;
	while (str[len++] != '\0');
	return len - 1;
}


void swapp(char* st1, char* st2, int s1, int s2) 
{
	char temp[MAX_LEN];
	int i;
	for (i = 0; i <= s1;i++) temp[i] = st1[i];
	for (i = 0; i <= s2; i++) st1[i] = st2[i];
	for (i = 0; i <= s1; i++) st2[i] = temp[i];
}



void bubSort(char (*data)[MAX_LEN], int *size) 
{
	int i, j, temp;

	for (i = 0; i < 5;i++)
	{
		for (j = 0; j < 5 - i - 1;j++)
		{
			if (size[j] > size[j + 1]) 
			{
				swapp(data[j],data[j+1],size[j],size[j+1]);
				temp = size[j];
				size[j] = size[j + 1];
				size[j + 1] = temp;
			}
		}
	}

}

int main(void)
{

	char data[5][MAX_LEN];
	int i, size[5];

	for (i = 0; i < 5; i++) 
	{
		gets(data[i]);
		size[i] = strLen(data[i]);
	}
	bubSort(data, size);

	for (i = 0; i < 5; i++) puts(data[i]);

	



}