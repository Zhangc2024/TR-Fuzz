#include <stdio.h>
int main()
{
    int a=5;
    int *pointer;
    pointer=&a;
    printf("a ning manzili %x, a ning qiymati %i\n", &a, a);
    printf("pointerning manzili %x, pointerning qiymati %x, pointerning qiymatining qiymati %i\n", &pointer, pointer, *pointer);
    a=10;
    printf("a ning manzili %x, a ning qiymati %i\n", &a, a);
    printf("pointerning manzili %x, pointerning qiymati %x, pointerning qiymatining qiymati %i\n", &pointer, pointer, *pointer);
    *pointer=75;
    printf("a ning manzili %x, a ning qiymati %i\n", &a, a);
    printf("pointerning manzili %x, pointerning qiymati %x, pointerning qiymatining qiymati %i\n", &pointer, pointer, *pointer);
    return 0;
}