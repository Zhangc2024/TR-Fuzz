#include <stdio.h>

int main() {
    int binary_test = 0b00000000;
    printf("%d\n", binary_test);

    // 0b00000001
    binary_test = (1 << 0);
    printf("%d\n", binary_test);

    // 0b00000010
    binary_test = (1 << 1);
    printf("%d\n", binary_test);

    /**
     * ORing turns bits off ON and leaves bits off, off!
     */
    int oring;
    oring = (0b00000100 | 0b00010000); // 0b00010100
    printf("%d\n", oring);

    /**
     * We can re-write this as
     */
    oring = ( (1 << 2) | (1 << 4) ); // 0b00010100
    printf("%d\n", oring);

    /**
     * short hand oring with |= means short_hand_value = (short_hand_value | 0b00000010)
     *
     * which equals 3
     *
     */
    int short_hand_value = 0b00000001;
    short_hand_value |= (1 << 1);
    printf("%d\n", short_hand_value);

    /**
     * We can also toggle a bit on and off with XOR
     */
    short_hand_value = 0b00000001;
    short_hand_value ^= (1 << 0);
    printf("%d\n", short_hand_value); // 0

    short_hand_value ^= (1 << 0);
    printf("%d\n", short_hand_value); // 1

    /**
     * Clearing a bit with AND and NOT
     *
     * We need to inverse the bitmask
     */
    int test_mask = 0b10000001;
    int change = ~(1 << 0); // 0b11111110

    /**
     * test_mask = 0b100000001
     * change    = 0b111111110
     * equals    = 0b100000000
     */
    test_mask &= change;
    printf("%d\n", test_mask);

    return 0;
}

