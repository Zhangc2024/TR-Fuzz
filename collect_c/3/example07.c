#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
   int iRandomNum = 0;
   int iResponse = 0;

   iRandomNum = ( rand() % 10 ) + 1;

   printf("\nGuess a number between 1 and 10: ");
   scanf("%d", &iResponse);

   if ( iResponse == iRandomNum ) {
      printf("\nYou guessed rigth!\n");
   } else {
      printf("\nSorry, you guessed wrong\n");
      printf("The correct guess was %d\n", iRandomNum);
   }


   return 0;
}
