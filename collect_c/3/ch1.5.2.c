#include <stdio.h>
// 统计输入的字符数量

main()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf ("%ld\n", nc);
}
