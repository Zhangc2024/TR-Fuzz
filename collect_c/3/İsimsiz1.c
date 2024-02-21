#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

union daire
{
	float alan;
	float cevre;
};

int main()
{
	float r;
	union daire tapur;
	printf("yaricapi giriniz: ");
	scanf("%f",&r);
	tapur.cevre=2*pi*r;
	tapur.alan=pi*r*r;
	printf("Alan=%.2f\n",tapur.alan);
	printf("cevre=%.2f",tapur.cevre);
	return 0;
}
