#include <stdio.h>

int main(void) {

	int tot = 0, temp,ret;

	while (1)
	{
		fputs("Data input (Ctrl+Z to exit) :", stdout);
		ret=scanf("%d", &temp);
		if (ret == -1) break;
		tot += temp;
	}
	printf("�� �� : %d \n", tot);


	return 0;
}