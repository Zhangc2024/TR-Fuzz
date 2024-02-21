#include <stdio.h>
int main()
{
	int meva, o=0, a=0, ana=0, b=0, g=0, chek=0; char sym;
	printf("Do'konimizga xush kelibsiz!\nBizning do'konimizda quyidagi eng sara mahsulotlar bor:\n");
	begin:
	printf("1-olma 12000 so'm\n2-anor 30000 so'm\n3-ananas 65000 so'm\n4-banan 20000 so'm\n5-gilos 98000 so'm\n");
	scanf("%d", &meva);
	switch (meva)
	{
		case 1: chek+=12000; o++; break;
		case 2: chek+=30000; a++; break;
		case 3: chek+=65000; ana++; break;
		case 4: chek+=20000; b++; break;
		case 5: chek+=98000; g++; break;
	}
	printf("Yana mahsulot tanlaysimi? h-HA\ty-YO'Q\n");
	scanf("%c", &sym);
	switch (sym)
	{
		case 'h': case 'H': goto begin;
		case 'y': case 'Y': printf("Siz olmadan ");
		printf("Siz ");
		if (o!=0)
		{
			printf("Olmadan %d ta %d so'm\n", o, o*12000);
		}
		if (a!=0)
		{
			printf("Anordan %d ta %d so'm\n", a, a*30000);
		}
		if (ana!=0)
		{
			printf("Ananasdan %d ta %d so'm\n", ana, ana*65000);
		}
		if (b!=0)
		{
			printf("Banandan %d ta %d so'm\n", b, b*20000);
		}
		if (g!=0)
		{
			printf("Gilosdan %d ta %d so'm\n", g, g*98000);
		}
		printf("Mahsulot tanladingiz va umumiy hisobda %d so'm bo'ldi\n", chek);
	}
	return 0;
}