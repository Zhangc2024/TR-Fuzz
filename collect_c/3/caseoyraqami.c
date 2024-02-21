#include <stdio.h>
int main()
{
	int oy;
	printf("Oyni raqam sifatida kiriting: ");
	scanf("%d", &oy);
	switch(oy)
	{
		case 12: case 1: case 2: printf("Qish\n"); break;
		case 3 ... 5: printf("Bahor\n"); break;
		case 6 ... 8: printf("Yoz\n"); break;
		case 9 ... 11: printf("Kuz\n"); break;
	}
	return 0;
}
