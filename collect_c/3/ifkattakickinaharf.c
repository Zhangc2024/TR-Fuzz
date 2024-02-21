#include <stdio.h>
int main()
{
	char harf;
	printf("Harfni kiriting: \n");
	scanf("%c", &harf);
	if (harf>64 && harf<91)
	{
		harf+=32;
	}
	else if (harf>96 && harf<123)
	{
		harf-=32;
	}
	
	printf("Harf = %c\n", harf);
	return 0;
}
