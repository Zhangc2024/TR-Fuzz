#include <stdio.h>

int power();

int main()
{
  int i;

  for (i = 1; i < 10; ++i)
      printf("%d %d\n", i, power(2, i));
  return 0;
}

/* power: raise base to n-th power; n >= 0 */
/* (old-style version) */
int power(base, n)
int base, n;
{
  int i, p;
  
  p = 1;

  for (i = 1; i <= n; ++i)
    p = p * base;
  
  return p;
}
