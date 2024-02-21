#include <stdio.h>

void sayHello()
{
    printf("Hello to all");
}

int sum(int a, int b)
{
    int s;
    s = a + b;
    return s;
}

float avgerage(int a, int b)
{
    float avg;
    avg = (float)(a + b) / 2;
    return avg;
}

// recursive  function
void display(int i)
{
    printf("%d", i);

    if (i == 0)
        return;

    display(i - 1);
    return;
}

int main()
{

    // sayHello(); // function call / function invocation / accessing a function

    int x;
    // x = sum(10, 20);
    // printf("%d", x);

    // printf("Sum is %d", sum(10,20) );

    display(5);


}
