#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const* argv[]) {
   int x = 0, iNumQuestions = 0, iResponse = 0, iRndNum1 = 0, iRndNum2 = 0;
   srand(time(NULL));

   printf("\nEnter number of questions to ask: ");
   scanf("%d", &iNumQuestions);

   for ( x = 0; x < iNumQuestions; x++ ) {
      iRndNum1 = rand() % 10 + 1;
      iRndNum2 = rand() % 10 + 1;

      printf("\nWhat %d x %d: ", iRndNum1, iRndNum2);
      scanf("%d", &iResponse);

      if ( iResponse == iRndNum1 * iRndNum2 ) {
         printf("Correct!\n");
      } else {
         printf("The correct answer was %d\n", iRndNum1 * iRndNum2);
      } // end if-else
   } // end loop

   return 0;
} // end main function
