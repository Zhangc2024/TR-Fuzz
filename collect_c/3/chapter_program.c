#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const* argv[]) {
   int iRandomNum = 0;
   srand(time(0));

   iRandomNum = ( rand() % 4 + 1 );

   printf("\nFortune Cookie - Chapter Program\n");

   switch ( iRandomNum ) {
      case 1:
         printf("\nYou will meet a new friend today!\n");
         break;
      case 2:
         printf("You will enjoy a long and happy life.\n");
         break;
      case 3:
         printf("\nOpportunity knocks softly. Can you hear it?\n");
         break;
      case 4:
         printf("\nYou'll be finacially rewarded for your good deeds.\n");
         break;
   } // end switch

   printf("\nLucky Lotto numbers\n");
   printf("%2d ", rand() % 49 + 1);
   printf("%2d ", rand() % 49 + 1);
   printf("%2d ", rand() % 49 + 1);
   printf("%2d ", rand() % 49 + 1);
   printf("%2d ", rand() % 49 + 1);
   printf("%2d\n", rand() % 49 + 1);
   return 0;
} // end main function
