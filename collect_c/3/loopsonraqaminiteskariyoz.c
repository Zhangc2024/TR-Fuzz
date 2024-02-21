#include <stdio.h>
int main()
{
	int n, teskari=0;
	printf("Raqamni kiriting: ");
	scanf("%d", &n);
	while (n!=0)
	{
		teskari=teskari*10;
		teskari=teskari+n%10;
		n=n/10;
	}
	printf("Teskari yozilganda : %d\n", teskari);
	
	return 0;
}
