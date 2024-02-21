/*Pattern 10

    1
   21
  321
 4321
54321
     
*/
#include <stdio.h>
#include <conio.h>
void main()
{
  int i, j, k;
  
  for (i = 1; i <= 5; i++)
  {
    for (j = 5; j >= 1; j--)
    {
      if (j <= i)
      {
        printf("%d", j);
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  getch();
}
