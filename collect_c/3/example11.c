#include <stdio.h>

int main(int argc, char const* argv[]) {
   int x;

   for ( x = 10; x > 5; x-- ) {
      if ( x == 7 ) {
         break;
      }

   } // end for loop

   printf("\nThe value of the x variable is: %d\n", x);

   return 0;
}
