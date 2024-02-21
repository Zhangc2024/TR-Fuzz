#include <stdio.h>
int main(){
    char charcase;
    char L = 'L', l ='l',U ='U',u='u';
    printf("Lowercase enter 'L' and for Upppercase enter 'U' ");
    scanf("%c",&charcase);

    if(charcase == L || charcase == l) {
        printf("Printing Lowercase alphabets : ");
        for(int i='a';i<='z';i++){
        printf(" %c ",i);
        }
    }
    else if(charcase == U || charcase == u){
        printf("Printing Lowercase alphabets : ");
        for(int j='A';j<='Z';j++){
        printf(" %c ",j);
        }
    }
    else 
        printf("You have entered wrong input\nTry again!");
    
    return 0;
}