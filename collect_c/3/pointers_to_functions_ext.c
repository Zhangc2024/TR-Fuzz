/* function pointers can be used in place of switch case */
#include <stdio.h>

void add(int, int);
void subtract(int, int);
void multiply(int, int);

int main() {
    // function_pointers is an array of function pointers
    void (*function_pointers[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;

    printf("a: %d and b: %d\n", a, b);
    printf("Enter choice: 0 for add, 1 for subtract and 2 for multiply\n");
    scanf("%d", &ch);

    if (ch > 2)
        return 0;
    (*function_pointers[ch])(a, b);
    return 0;
}

void add(int a, int b) {
    printf("Sum is: %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference is: %d\n", a - b);
}

void multiply(int a, int b) {
    printf("Product is: %d\n", a * b);
}
