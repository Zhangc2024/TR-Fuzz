/*
C Programming powerUp -Page 75
문자의 유형 분류
2016-06-26
*/

#include<stdio.h>

int main(void)
{

	char cur;

	while (1) {
		
		cur=getchar();
		fflush(stdin);
		if (cur >= 'a' && cur <= 'z') puts("입력하신 문자는 알파벳 소문자입니다.");
		else if (cur >= 'A' && cur <= 'Z') puts("입력하신 문자는 알파벳 대문자입니다.");
		else if (cur >= '0' && cur <= '9') puts("입력하신 문자는 아라비아 숫자입니다.");
		else if (cur == EOF) break;
		else puts("특수 문자를 입력하셨군요.");
		
	}
	puts("프로그램을 종료합니다.");
}