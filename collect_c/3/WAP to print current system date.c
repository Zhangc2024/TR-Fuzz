/*WAP to print current system date*/
#include <stdio.h>
#include <time.h>
 
int main(){
  
  char cur_time[128];
  
  time_t      t;
  struct tm*  ptm;
  
  t = time(NULL);
  ptm = localtime(&t);
    
  strftime(cur_time, 128, "%d-%b-%Y %H:%M:%S", ptm);
  
  printf("Current date and time: %s\n", cur_time);
  
  return 0;
}
