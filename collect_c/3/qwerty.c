#include <stdio.h>
#include <string.h>
int main()
{
    char ism[30], fam[30];
    printf("Ismingizni kiriting: "); scanf("%s", ism);
    printf("Familiyangizni kiriting: "); scanf("%s", fam);
    int k, i;
    if(strlen(ism)>strlen(fam))
    { 
        for(i=0 ; i<strlen(fam); i+=2) 
        {
            k=ism[i-1];
            ism[i-1]=fam[i];
            fam[i]=k;
        }
    }
    else
    {
        for(i=0 ; i<strlen(ism); i+=2)
        {
            k=ism[i];
            ism[i]=fam[i+1];
            fam[i+1]=k;
        }
    }
    puts(ism);
    puts(fam);
    return 0;
}