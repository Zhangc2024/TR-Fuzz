#include <stdio.h>
int main()
{
    char text[30]="Hello\n Foundation\t29";
    int size=0, i;
    char name[50]="";
    printf("name=%s\n", name);
    for (i=0; text[i]!='\0'; i++)
    {
        name[size]=text[i];
        size++;
    }
    printf("Kiritilgan belgilar soni %d ta\n", size);
    puts(name); 
    printf("%s\n", name);
    return 0;
}