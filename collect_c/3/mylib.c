int big2(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int big3(int a, int b, int c)
{
    // return big2( big2(a,b), c);
    if (a > b)
        if (a > c)
            return a;
        else
            return b;
    else if (b > c)
        return b;
    else
        return c;
}

void sayHello()
{
    printf("\nHello!");
}

void greet()
{
    printf("\nGood Afternoon!!!");
}

void printBigger(int a, int b)
{
    if (a > b)
        printf("\nBiggest is %d", a);
    else
        printf("\nBiggest is %d", b);
}

int findBigger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}