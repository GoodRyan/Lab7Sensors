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
    	//Change the LED light being checked.
    }

}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  getInputFromSensor();
  __bic_SR_register_on_exit(CPUOFF);
}
