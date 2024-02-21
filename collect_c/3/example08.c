#include <stdio.h>

int main(int argc, char const* argv[]) {
   int x = 0;

   do {
      printf("This printf statement is executed at least once\n");
      x++;
   } while ( x < 10 ); // end do while loop

   while ( x < 10 ) {
      printf("This printf statement is never executed\n");
      x++;
   } // end while loop

   return 0;
} // end main
