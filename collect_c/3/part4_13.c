/*
C Programming powerUp -Page 65
while과 for문의 중첩
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n,che,i;

	fputs("1 이상의 정수 입력 : ",stdout);
	while (1)
	{
		che=scanf("%d", &n);
		if (che == EOF) break;
		if (n < 1)
		{
			fputs("1이상의 입력을 필요로 합니다 다시입력하세요", stdout);
			continue;
		}


		printf("%d의 약수들 \n", n);

		for (i = 1; i <= n; i++) {
			if (!(n%i))
			{
				printf("%d ", i);
			}
		}

		puts("");
	}


}