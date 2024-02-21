#include <stdio.h>
int main(){
    char c;
    printf("enter the character value : ");
    scanf("%c",&c);
    if (c >= 'a' && c<= 'z' || c >= 'A' && c<= 'Z')
    {
        printf("the entered character %c is a alphabet",c);
    }
    else 
      printf("the entered character %c is not a alphabet",c);   
    return 0;
}