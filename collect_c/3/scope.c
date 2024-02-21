/*
    Scope

    Here we look at examples of "scope". Scope is a region or an area where something is valid or accessible.
    This also has an example where we pass a variable by value... this means we make a copy of it inside the function,
    so it's accessible locally. However, the value isn't changed unless we return it back or pass by reference
    (something we'll look at in the future).

    Note- this file won't compile, due to the scope errors.
*/

void heyBro(int number);

int main(void)
{
    int apples = 5;
    int oranges = 18;

    apples = 10;        /* in scope, declared in this block, so this is usable */

    heyBro(oranges);    /* we pass the variable 'oranges' by _value_ to heyBro() */

    birthday = 0;       /* declared in heyBro, but it's out of scope here, so this will fail */

    return 0;
}

void heyBro(int number) {
    number = 6;         /* This is the copy of oranges from main().
                           We can change it's value, but the changes won't affect the original
                           variable oranges in main(). */

    int birthday = 8;   /* only available in this scope, not in main */
    apples = 20;        /* Declared in main(), but it's out of scope here. Will fail.*/
}