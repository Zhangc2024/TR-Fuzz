#include<stdio.h>

int main(void) 
{

	char c;
	int n;
	float f;
	char s[10];
	
	printf("[문자, 정수,  실수, 문자열]의 포맷으로 입력");
	scanf("%c, %d, %f, %s",&c,&n,&f,s);

	printf("입력된 데이터 출력 : %c, %d, %f, %s \n", c,n,f,s);

	return 0;
}