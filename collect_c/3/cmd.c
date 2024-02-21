/* c-examples by A.A.Shtanyuk */
/* cmd.c - command line arguments */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i,num;
   if(argc<3)
   {
      puts("Usage: cmd word number");
      exit(1);
   }
   printf("Welcome to %s! Enjoy!\n",argv[0]); 
   num=atoi(argv[2]);
   if(num>0)
      for(int i=0;i<num;i++)
         printf("%d - %s\n",i+1,argv[1]);
   else
      puts("Wrong number!");
   return 0;
}
