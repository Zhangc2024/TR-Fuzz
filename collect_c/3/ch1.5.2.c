#include <stdio.h>
// ͳ��������ַ�����

main()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf ("%ld\n", nc);
}
