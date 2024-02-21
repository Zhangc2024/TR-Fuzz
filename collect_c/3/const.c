#include <stdio.h>

void func(const int  *a,int size);

int main()
{
	
	int array[5]={1,2,3,4,5};
	func(array,5);
	return 0;
	
}
void func(const int  *a,int size)
{
	a[2]=5;
}
