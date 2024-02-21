#include<stdio.h>
#include<string.h>


int main(){
    char str[20];int count=1;
    printf("\nENter a string");
    gets(str);
    int max=0;char c;
    for(int i=0;str[i]!='\0';i++){
        count=1;
        for(int j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){
               count++;
            }

        }
        printf("\n%c is repeated %d times",str[i],count);
        if(count>max){
            max=count;
            c=str[i];
        }
         
    }
    printf("\n%c is the most repeated character..as it has been repeated %d times",c,max);
    return 0;
}