#include <stdio.h>
#include <assert.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main(int argc, char const *argv[])
{
	// 00011010 (26), 4, 3 -> 110 (6)
	assert(getbits(26u, 4, 3) == 6u);

	// 00100111 (39), 4, 3, 11010110 (214) -> 00111011 (59)
	assert(setbits(39u, 4, 3, 214u) == 59u);

	// 00100111 (39), 4, 3 -> 00111011 (59)
	assert(invert(39u, 4, 3) == 59u);

	// 00100111 (39), 4 -> 0111 ... 0010 (1879048194)
	assert(rightrot(39u, 4) == 1879048194u);

	return 0;
}

/* getbits: return n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* setbits: return x with the n bits at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	x = x & ((~0 << (p + 1)) | ~(~0 << (p - n + 1))); // x with unset n bits at position p
	y = y & ~(~0 << n); // y with unset all other bits
	return x | (y << (p - n + 1));
}

/* invert: invert n bits at position p */
unsigned invert(unsigned x, int p, int n) {
	return x ^ (~(~0 << n) << (p - n + 1));
}

/* rightrot: rotates x rotated n bits to the right */
unsigned rightrot(unsigned x, int n) {
	unsigned r = x << (sizeof(x) * 8 - n);
	x = x >> n;
	return x | r;
}
