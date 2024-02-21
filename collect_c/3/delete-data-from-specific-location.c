#include<stdio.h>
 
int main()
{
 int a[10],size,i,pos;
 printf("enter size of array");
 scanf("%d",&size);
 printf("enter elements of array : ");
 for ( i = 0; i < size; i++)
 {
    scanf("%d",&a[i]);
 }

  printf("enter position of element you want to delete : ");
 scanf("%d",&pos);
 if (pos<=0 || pos > size)
 {
    printf("invalid position");
 }
 else {
    int item = a[pos-1];
   for ( i = pos-1; i <size-1; i++)
 {
    a[i] = a[i+1];
 }
 printf("You have deleted %d from a[%d] ",item,pos-1);
    size--; 
   printf("New after insert one element at desired position");
   for (int j = 0; j <size; j++)
 {
    printf(" %d ",a[j]);
 }
 
 }

 return 0;
}