# include <stdio.h>
unsigned long int next = 1;
int rand(void);
void srand(unsigned int seed);

int main() {
    int i = 1;
    while (i < 11){
        srand(i);
        printf("Random number is %d, given seed = %d\n", rand(), i);
        ++i;
    }
}
/* rand: return pseudo-random integer on 0..32767*/
int rand(void) {
    next = next * 1103515245 + 123456;
    return (unsigned int)(next / 65536) % 32768;
}
/* srand: set seed for rand() */
void srand(unsigned int seed){
    next = seed;
}
