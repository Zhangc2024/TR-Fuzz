#include <stdio.h>

int main(int argc, char const *argv[]) {
   char cResponse = '\0';

   printf("\tAC Control Unit\n");
   printf("a\tTurn the AC on\n");
   printf("b\tTurn the AC off\n\n");
   printf("Enter your selection: ");
   scanf("%c", &cResponse);

   if (cResponse == 'a') {
      printf("\nAC is now on\n");
   }

   if (cResponse == 'b') {
      printf("\nAC is now off\n");
   }

   return 0;
}
