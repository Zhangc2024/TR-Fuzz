#include <stdio.h>
int main()
{
    int qatorsoni;
    printf("Qatorlar sonini kiriting: \n");
    scanf("%d", &qatorsoni);
    
    int qator, probel, yulduz;
    for(qator=1;qator<=qatorsoni;qator++)
    {
        for(probel=qatorsoni-qator; probel>=1;probel--)
        {
            printf(" ");
        }
        for(yulduz=1;yulduz<=qator;yulduz++)
        {
            printf("* "); 
        }
        printf("\n");
    }
    return 0;
}
