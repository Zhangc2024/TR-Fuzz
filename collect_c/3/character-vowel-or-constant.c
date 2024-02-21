#include<stdio.h>
int main(){
    char chr;
    printf("enter value of a :\n");
    scanf("%c",&chr);
    if (chr == 'a' ||chr =='e' ||chr =='i'||chr =='o'||chr =='u'||chr =='A'||chr =='E'||chr =='I'||chr =='O'||chr =='U')
    {
        printf("the : %c : is a vowel value",chr);
    }
    else {
        printf("the : %c : is a constant value",chr);
    }
    return 0;
};