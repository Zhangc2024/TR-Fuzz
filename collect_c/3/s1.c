#include <stdio.h>
#include <string.h>
int main()
{
    /*char name[20], surname[20];
    printf("Ismingizni kiriting: "); scanf("%s", name);
    printf("Familyangizni kiriting: "); scanf("%s", surname);
    char ism [20], fam[20];
    int i, n=strlen(name), m=strlen(surname);
    if (n%2==0) { n=n/2; }
    else { n=n/2+1; }
    if (m%2==0) { m=m/2; }
    else { m=m/2+1; }
    strcpy(ism, surname+m);
    strcat(ism, name+m);
    puts(ism);
    strcpy(fam, name+n);
    strcat(fam, surname+m);
    puts(fam);
    */


    /*char ism[20], fam[20];
    printf("Ismingizni kiriting: "); scanf("%s", name);
    printf("Familyangizni kiriting: "); scanf("%s", surname);
    int i, k;
    if (strlen(ism)>strlen(fam))
    {
        for (i=1; i<strlen(fam); i+=2)
        {
            k=ism[i-1];
            ism[i-1]=fam[i];
            fam[i]=k;
        }
    }
    else 
    {
        for (i=0; i<strlen(ism); i+=2)
        {
            k=ism[i];
            ism[i]=fam[i+1];
            fam[i+1]=k;
        }
    }
    puts(ism);
    puts(fam);
    */


    
return 0;    
}