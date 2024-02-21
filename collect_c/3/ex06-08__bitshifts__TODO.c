// Exercise 2-6. Write a function setbi ts ( x, p, n, y) that returns x with the n
//bits that begin at position p set to the rightmost n bits of y, leaving the other
//bits unchanged. 0


//Exercise 2-7. Write a function invert(x,p,n) that returns x with then bits
//that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
//the others unchanged. o

//Exercise 2-8. Write a function rightrot ( x, n) that returns the value of the
//integer x rotated to the right by n bit positions.
//

/* EXAMPLE -- getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n))
    & -(-0 << n);
}

 // GLOSS:
 // The expression x > > ( p+ 1-n ) moves the desired field to the right end of the
 // word. -o is all 1-bits; shifting it left n bit positions with -O<<n places zeros in
 // the rightmost n bits; complementing that with - makes a mask with ones in the
 // rightmost n bits.
 //
 // eg: getbits(b01010, 3, 3) returns b101
 // which are the middle 3 bits of the 5-bit value consumed (taking 3 bits from the fourth-from-the-right position)