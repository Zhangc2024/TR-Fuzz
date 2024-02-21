#include <stdio.h>
#include <stdlib.h>

int faktoriyel(int sayi)
{
	int sonuc;
	if(sayi==0)
	{
		sonuc=1;
		//return sonuc;
		printf("**%d\n",sonuc);
	}
	else
	{	
	sonuc=sayi*faktoriyel(sayi-1);
	printf("********%d\n",sonuc);
	}
	return sonuc;
}	
int main()
{
	int sayi,sonuc;
	printf("Bir sayi gir: ");
	scanf("%d",&sayi);
	sonuc=faktoriyel(sayi);
	printf("%d!=%d",sayi,sonuc);
	return 0;
}
