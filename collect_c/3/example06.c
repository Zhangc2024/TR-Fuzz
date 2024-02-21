#include <stdio.h>

int main(int argc, char const* argv[]) {
   int iResponse = 0;

   printf("1\tSports\n");
   printf("2\tGeography\n");
   printf("3\tMusic\n");
   printf("4\tWorld Events\n\n");
   printf("Please select a category (1-4): ");
   scanf("%d", &iResponse);

   switch ( iResponse ) {
      case 1:
         printf("You selected sports questions\n");
         break;
      case 2:
         printf("You selected geography questions\n");
         break;
      case 3:
         printf("You selected music questions\n");
         break;
      case 4:
         printf("You selected wolrd event questions\n");
         break;
   } // end switch statement

   return 0;
} // end main
