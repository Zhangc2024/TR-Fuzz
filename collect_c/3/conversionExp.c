# include <stdio.h>

int main() {
    // Won't lose info for char c, since it will drop excess high-order bits
    int i;
    char c;
    printf("int default: %d, char default: %d\n", i, c);
    
    i = c;
    c = i;
    printf("int assigned with char:%d, char assigned with int: %d\n", i, c);
}
