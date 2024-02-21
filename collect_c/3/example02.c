#include <stdio.h>

int main(int argc, char const* argv[]) {
   int iSelection = 0;
   float fTransAmount = 0.0;
   float fBalance = 100.25;

   printf("\tATM\n\n");
   printf("1\tDeposit Funds\n");
   printf("2\tWithdraw Funds\n");
   printf("\nEnter your selection: ");
   scanf("%d", &iSelection);

   if ( iSelection == 1 ) {
      printf("\nEnter fund amount to deposit: ");
      scanf("%f", &fTransAmount);
      printf("Your new balance is: %.2f\n", fBalance + fTransAmount);
   }  // end if

   if ( iSelection == 2 ) {
      printf("\nEnter fund amout to withdraw: ");
      scanf("%f", &fTransAmount);

      if ( fTransAmount > fBalance ) {
         printf("\nInsuficient funds\n");
      }
      else {
         printf("Your new balance is: %.2f\n", fBalance - fTransAmount);
      }  // end inner if-else

   }  // end outer if

   return 0;
}  // end main fucntion
