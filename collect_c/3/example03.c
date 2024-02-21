#include <stdio.h>

int main(int argc, char const* argv[]) {
   char cResponse = '\0';

   printf("Enter the letter 'A': ");
   scanf("%c", &cResponse);

   if ( cResponse == 'A' ) {
      printf("\nCorrent response!.\n");
   }
   else {
      printf("\nIncorrect response!.\n");
   }

   return 0;
}
