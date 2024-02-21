#include <stdio.h>
#include <string.h>
int main()
{
    char name[30], surname[30];
    printf("Ismingizni kiriting: "); scanf("%s", name);
    printf("Familiyangizni kiriting: "); scanf("%s", surname);
    char ism[30], fam[30];
    int n=strlen(name), m=strlen(surname);
    if (n%2==0) { n=n/2; }
    else { n=n/2+1; }
    strcpy(ism, surname+m/2);
    strcat(ism, name+n/2+1);
    puts(ism);
    return 0;
}   