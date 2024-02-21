#include <stdio.h>

int main(int argc, char const* argv[]) {
   int x;

   for ( x = 10; x > 5; x-- ) {
      if ( x == 7 ) {
         continue;
      }

      printf("\nThe value of the x variable is %d", x);

   }

   printf("\n");

   return 0;
}
