/*
C Programming powerUp -Page 65
while�� for���� ��ø
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n,che,i;

	fputs("1 �̻��� ���� �Է� : ",stdout);
	while (1)
	{
		che=scanf("%d", &n);
		if (che == EOF) break;
		if (n < 1)
		{
			fputs("1�̻��� �Է��� �ʿ�� �մϴ� �ٽ��Է��ϼ���", stdout);
			continue;
		}


		printf("%d�� ����� \n", n);

		for (i = 1; i <= n; i++) {
			if (!(n%i))
			{
				printf("%d ", i);
			}
		}

		puts("");
	}


}