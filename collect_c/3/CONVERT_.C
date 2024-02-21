#include<stdio.h>
int main()
{
  char a[]="KAR%T*HIK";
  int i;
  for( i=0;a[i]!='\0';i++)
  {
	if(a[i]>='A' && a[i]<='Z')
	{
	   a[i]=a[i]+32;
	}
  }
  printf("the string after converting to lower case:%s",a);
  getch();
  return 0;
}