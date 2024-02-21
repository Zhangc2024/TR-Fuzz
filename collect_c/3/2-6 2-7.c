#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * My own solution using OR to "shadow" n bits
 */
unsigned setbits1(unsigned x, int p, int n, unsigned y) {
	return (x | ~(~0 << n) << (p + 1 - n)) & ~((~y & ~(~0 << n)) << (p + 1 - n));
}

/**
 * Official Solution using AND to "shadow" n bits
 */
unsigned setbits2(unsigned x, int p, int n, unsigned y) {
	return (x & ~(~(~0 << n) << (p + 1 - n))) | (y & ~(~0 << n)) << (p + 1 - n);
}

/**
 * My own solution without using XOR operation
 */
unsigned invert1(unsigned x, int p, int n) {
	unsigned x1 = x;
	x = x | ~(~0 << n) << (p + 1 - n);
	x1 = ~(x1 & ~(~0 << n) << (p + 1 - n));
	return x & x1;
}

/**
 * Official Solution with XOR operation
 */
unsigned invert2(unsigned x, int p, int n) {
	return x ^ (~(~0 << n) << (p + 1 - n));
}

