/*define the frequency of the interrupt*/
#define F_CPU 12000000UL
/*include the libraries for I/O and interrupt declarations*/
#include <avr/io.h>
#include <avr/interrupt.h>

/*main part of the program*/
int main(void)
{
    DDRC    = 0xFF;     /*set DDRC as an OUTPUT*/
    PORTC   = 0x00;     /*shutdown all LED's*/

    DDRD    = 0x00;     /*set DDRD as an INPUT*/
    PORTD   = 0xFF;     /*pull-up resistor on PD0-PD7*/

    /*interrupt register*/
    MCUCR   |= (1 << ISC11);    /*interrupt INT1 in MCUCR(set flag)*/
    GICR    |= (1 << INT1);     /*interrupt INT1 in GICR(enable)*/

    /*global interrupt set*/
    while(1)
    {
        if(GIFR & (1 << INTF1))     /*when INFT1 is zero*/
        {
            PORTC++;                /*OUTPUT PORTC more than 1*/
            GIFR = (1 << INTF 1);   /*INTF1 flag is RESET*/
        }
    }
}