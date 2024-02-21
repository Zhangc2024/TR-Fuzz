#include <stdio.h>
int main()
{
	int yil; 
    printf("Yilni kiriting: ");
scanf("%d", &yil); 
 if ( yil%400 == 0) 
   printf("-yil kabisa yili\n", yil); 
 else if ( yil%100 == 0) 
    printf("%d-yil kabisa yili emas\n", yil); 
  else if ( yil%4 == 0 ) 
    printf("%d-yil kabisa yili\n", yil); 
 else
    printf("%d-yil kabisa yili emas\n", yil);  
   return 0; 
}
