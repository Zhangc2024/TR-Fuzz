/*
C Programming powerUp -Page 22
EOF�� �Է� �� �� ���� ���ڸ� �Է� �޴� ����
2016-06-26
*/
#include<stdio.h>

int main(void) {

		
	int count = 0;
	char temp;

	while (1)
	{
		
		fputs("Data input (Ctrl+Z to exit) :", stdout);
		temp= getchar();
		if (temp == EOF) break;
		fflush(stdin); //���μ����Է� ���������
		count++;
	}

	printf("�Էµ� ������ �� : %d \n", count);
	return 0;
}