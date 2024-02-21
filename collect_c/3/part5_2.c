/*
C Programming powerUp -Page 79
문자의 유형 분류
2016-06-26
*/

#include<stdio.h>
#define MAX_LEN 100


int strLen(char* str) {

	int len = 0;
	while (str[len++] != '\0');
	return len-1;
}


int main(void)
{

	char string[100];
	int len,i;
	int diff = 'A' - 'a';

	fputs("문자열 입력 : ",stdout);
	gets(string);

	len= strLen(string);

	for (i = 0; i < len; i++) {
		if (string[i] >= 'a' && string[i] <= 'z') string[i] += diff;
		else if (string[i] >= 'A' && string[i] <= 'Z') string[i] -= diff;
		else;
	}

	puts(string);
	return 0;


}