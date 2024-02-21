#include <stdio.h>
int main()
{
  char name[]="salom bolalar";
  int k=0, i;
  for (i=0; name[i]!='\0'; i++)
  { k++; }
  printf("k=%d\n", k);
  name[5]='\0';
  name[0]='\0';
  name[0]='b';
  puts(name);
  printf("%c%c%c%c%c%c%c", name[6], name[7], name[8], name[9], name[10], name[11], name[12]);
  return 0;
}