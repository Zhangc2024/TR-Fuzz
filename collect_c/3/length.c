#include <stdio.h>

main()
{
    int i;
    for (i=0; i < 10 ; ++i){
        printf("%d\n",i);
    }
    printf("%d\n---\n",i);

    i = 0;
    while (i < 10){
        ++i;
        printf("%d\n",i);
    }
}
