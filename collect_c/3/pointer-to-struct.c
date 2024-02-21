/*
    Pointer to a Struct
    (also, passing struct pointers to functions, AND the arrow operator!)

    Pointers & structs have now been introduced. When we want to pass that data, you can pass a struct
    as you would other data types. However, in certain cases can add a lot of info to the stack...
    so you can pass a pointer to a struct instead. This will use a lot less memory.

    Here, we have a new type called essay. We have two functions that print essay info.
    One is for passing the struct by value, and one is for passing it by reference... aka, via a pointer to an essay.
*/

#include <stdio.h>

struct essay {
    int pageCount;
    int wordCount;
};

void printEssayInformation(struct essay theEssay);
void printPointerEssayInformation(struct essay *theEssay);

int main(void)
{
    struct essay firstEssay;

    firstEssay.pageCount = 5;
    firstEssay.wordCount = 500;

    struct essay *otherEssay; /* make an essay pointer named otherEssay */
    otherEssay = &firstEssay; /* point otherEssay to the struct firstEssay */

    /* print firstEssay, and otherEssay */
    printEssayInformation(firstEssay);
    printPointerEssayInformation(otherEssay);

    /* b/c it's a pointer, it changes the real value! */
    otherEssay->pageCount *= 5;
    otherEssay->wordCount *= 5;

    /* see that firstEssay was changed */
    printEssayInformation(firstEssay);

    return 0;
}

/*
    A function that accepts an essay struct and prints the info.
*/
void printEssayInformation(struct essay theEssay) {
    printf("This essay is %d pages long, and has %d words.\n", theEssay.pageCount, theEssay.wordCount);
}

/*
    A function that accepts a pointer to an essay struct and prints the info.

    I spread out the print function to show how we can reference fields from a pointer to a struct.
    Obviously, it removes some of the efficiency we were aiming for. However... it's just for example!
*/
void printPointerEssayInformation(struct essay *theEssay) {
    int pageCount = (*theEssay).pageCount;  /* you can dereference 'theEssay' pointer
                                               and access page count with the dot operator */

    int wordCount = theEssay->wordCount;    /* you can dereference and access the field with this
                                               shortcut... the arrow operator! */

    printf("This essay is %d pages long, and has %d words.\n", pageCount, wordCount);
}