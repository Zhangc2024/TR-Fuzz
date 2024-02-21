#include <stdio.h>
#include <string.h>
int main()
{
    char ism[30], fam[30];
    printf("Ismni kiriting: "); scanf("%d", ism);
    printf("Familiyani kiriting: "); scanf("%d", fam);
    /*strcpy(text1,text2);
    strcpy(text1,text2+5);
    strcpy(text1+5,text2);
    strcpy(text1,"");
    strcpy(text1+3,text2+7);
    strncpy(text1,text2+10,3);
    strcat(text1,text2);*/
    strcat((strcat(ism," ")),fam);
    puts(ism);
    return 0;
}