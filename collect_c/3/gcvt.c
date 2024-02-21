#include <stdio.h>

#include <string.h>

int main()
{

    float y = 123.4567;
    char buf[100];
  	char x[1000];
   
  
    sprintf(buf,"%5.1f,",y);
  //	printf("%d----%s",strlen(buf),buf);
  	strcpy(x,buf);
  	 sprintf(buf,"mehmet,");
  	 	strcat(x,buf);
  printf("%d----%s",strlen(x),x);
  	x[strlen(x)-1]='\0';
  	  printf("%d----%s",strlen(x),x);
  	  
  	    	 sprintf(buf,"mehmet,");
  	 	strcat(x,buf);
  printf("%d----%s",strlen(x),x);
  	  
    return 0;

	
	
}
