#include <stdio.h>
int sonlar(int n)
{
  if (n>0)
  {
    sonlar(n-1);
    if (n%2==0)
    { printf("%i ",n); }   
  }
  if (n<0)
  {
    printf("Siz manfiy son kiritdingiz!");
  }
  if (n==0)
  {
    printf("0");
  }
}

int main ()
{
  int son,k=0;
  printf("son="); scanf("%i",&son);
  sonlar(son);
  puts("");
return 0;
}