#include <msp430.h> 
#include "sensor.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

   // initializeADC10();
	
    initializeLedPins();
    P1OUT |= 0x01;

    while(1){}

    for(;;){
    	checkLeftSensor();
    	if (ADC10MEM < 0x1FF)
    		P1OUT &= ~BIT0;
    	else
    		P1OUT |= BIT0;

    	_delay_cycles(100);

    	checkRightSensor();
    	if (ADC10MEM < 0x1FF)
    		P1OUT &= ~BIT6;
    	else
    		P1OUT |= BIT6;
    }

}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  getInputFromSensor();
  __bic_SR_register_on_exit(CPUOFF);
}
