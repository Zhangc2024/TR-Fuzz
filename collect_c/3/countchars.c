# include <stdio.h>

/* coount chars in input */

int main()
{
  /* long nc; */

  /* nc = 0; */
  /* while (getchar() != EOF) */
  /*   ++nc; */

  double nc;

  for(nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}
