#include <ctype.h>
#include <stdio.h>

int main(int argc, char const* argv[]) {
   char cResponse = '\0';

   printf("Please enter a digit: ");
   scanf("%c", &cResponse);

   if ( isdigit(cResponse) ) {
      printf("\nthank you!\n");
   } else {
      printf("\nYou did not enter a digit!\n");
   }


   return 0;
}