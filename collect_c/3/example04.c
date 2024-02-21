#include <stdio.h>

int main(int argc, char const* argv[]) {
   int iResponse = 0;

   printf("Enter a number: ");
   scanf("%d", &iResponse);

   if ( iResponse < 1 || iResponse > 10 ) {
      printf("\nNumber not in range\n");
   }
   else {
      printf("\nThank you\n");
   }

   return 0;
}
