#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	unsigned char uc;
	int i;
	unsigned int ui;
	long int li;
	unsigned long int uli;
	
	c = 0;
	c = c | (1 << 7);
	printf("char min: %d\n", c);

	c = 0;
	c = ~c ^ (1 << 7);
	printf("char max: %d\n", c);

	uc = 0;
	printf("unsigned char min: %u\n", uc);

	uc = ~uc;
	printf("unsigned char max: %u\n", uc);

	i = 0;
	i = i | (1 << 31);
	printf("int min: %d\n", i);

	i = 0;
	i = ~i ^ (1 << 31);
	printf("int max: %d\n", i);

	ui = 0;
	printf("unsigned int min: %u\n", ui);

	ui = ~ui;
	printf("unsigned int max: %u\n", ui);

	li = 0;
	li = li | (1l << 63);
	printf("long int min: %ld\n", li);

	li = 0;
	li = ~li ^ (1l << 63);
	printf("long int max: %ld\n", li);

	uli = 0;
	printf("unsigned long int min: %lu\n", uli);

	uli = ~uli;
	printf("unsigned long int max: %lu\n", uli);

	return 0;
}