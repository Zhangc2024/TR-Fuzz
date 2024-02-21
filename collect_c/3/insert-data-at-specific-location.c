#include<stdio.h>
 
int main()
{
 int a[10],size,i,num,pos;
 printf("enter size of array");
 scanf("%d",&size);
 printf("enter elements of array : ");
 for ( i = 0; i < size; i++)
 {
    scanf("%d",&a[i]);
 }

 printf("enter data you want to insert");
 scanf("%d",&num);
  printf("enter position");
 scanf("%d",&pos);
 if (pos<=0 || pos > size+1)
 {
    printf("invalid position");
 }
 else {
   for ( i = size-1; i >=pos-1; i--)
 {
    a[i+1] = a[i];
 }
 a[pos-1] = num;
 size++;
   printf("New after insert one element at desired position");
   for (int j = 0; j <size; j++)
 {
    printf(" %d ",a[j]);
 }
 }

 return 0;
}