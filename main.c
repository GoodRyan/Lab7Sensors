#include <msp430.h> 
#include "sensor.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initializeADC10();
	
    initializeLedPins();

    for(;;){

    	checkLeftSensor();

    	if (ADC10MEM < 0x2FF)
    		P1OUT &= ~BIT0;
    	else
    		P1OUT |= BIT0;

    	_delay_cycles(100);

    	checkRightSensor();

    	if (ADC10MEM < 0x2FF)
    		P1OUT &= ~BIT6;
    	else
    		P1OUT |= BIT6;

    }

}



