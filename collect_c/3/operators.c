/*
    Operators

    C has operators to 'do something' to one or more values.
    Below are some examples of operators.
    Addition, subtraction, multiplication, division, and modulo are common operators.
    These operators require a left and right value. Other operators, like the increment / decrement operators (++ or --),
    only operate on one value.

    Notice line 24 when we divide ourBakersDozen by 6. 'ourBakersDozen' doesn't become 2, because we aren't SETTING it to 2.
    We are only dividing by 6 and printing the result.
*/

#include <stdio.h>

int main(void)
{
    int ourBakersDozen = 13;
    printf("A bakers' dozen has %d donuts in it.\n", ourBakersDozen);

    printf("Let's eat one donut...\n");
    ourBakersDozen--;                                       /* equal to: ourBakersDozen = ourBakersDozen - 1; */
    printf("Now we have %d donuts.\n", ourBakersDozen);

    printf("Some friends want some. There are 6 people. How many donuts does each person get?\n");
    printf("Each person would get %d donuts.\n", ourBakersDozen / 6);

    int originalAmount = ourBakersDozen;
    ourBakersDozen  = ourBakersDozen * 5;
    printf("Actually, let's just buy more donuts. We currently have %d donuts, and after buying more, we have %d donuts!\nHow many more did we buy??\n", originalAmount, ourBakersDozen);

    int difference = ourBakersDozen - originalAmount;
    printf("Looks like we bought %d more donuts!\n", difference);

    printf("If I found one more on the street, I would have %d donuts.\nBut, I probably shouldn't eat it.", ourBakersDozen + 1);

    return 0;
}