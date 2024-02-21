#include <stdio.h>
int tort_yuzi(int eni, int boyi)
{
	int yuza;
	yuza=eni*boyi;
	return yuza;
}
int main()
{
	int e=10, b=5;
	int yuza=tort_yuzi(e,b);
	printf("%d\n", yuza);

	e=50, b=20;
	yuza=tort_yuzi(e,b);
	printf("%d", yuza);
}