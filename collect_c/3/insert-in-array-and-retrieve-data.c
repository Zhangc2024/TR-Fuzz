//Insert elements in array and retrieve data
#include<stdio.h>
 
int main()
{
 int num[20];
 printf("enter elements of array :\n");
 for (int i = 0; i < 20; i++)
 {
    printf("num[%d] -> ",i);
    scanf("%d",&num[i]);
 }
 printf("final array is num[20] = {");
  for (int i = 0; i < 20; i++)
 {
    printf(" %d, ",num[i]);

 }
 printf("}");

 
 
 return 0;
}