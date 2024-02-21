#include <stdio.h>

void count();

/**
 * Both this variable and function is ONLY available within this file as it has the static keyword prefixed!
 */
static int test1 = 999;
static void test_func();

int main() {
    /**
     * These will output 1, 2, 3, 4
     */
    count();
    count();
    count();
    count();

    /**
     * test1 is ONLY available within this file.
     */
    printf("\n%d\n", test1);

    test_func();

    return 0;
}

void count() {
    /**
     * Maintains the value of count_number on each call.
     */
    static int count_number = 1;
    printf("%d\n", count_number);
    count_number++;
}

static void test_func() {
    printf("\nI am only avilable wthin this file!\n");
}

