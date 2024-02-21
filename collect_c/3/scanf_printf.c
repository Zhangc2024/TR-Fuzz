#include <stdio.h>

int main()
{
    char str[100];
    int i;

    while(1)
    {
        printf("Enter a value: ");
        scanf("%s %d", str, &i);

        printf("\nYou entered: %s, %d \n", str, i);
    }
    

    return 0;
}
