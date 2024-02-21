#include <stdio.h>

/* count characters in input; 2nd verssion */
int main()
{
  double nc;

  for (nc = 0; getchar() != EOF; ++nc) {;}
  printf("%.0f\n", nc);
  
}
