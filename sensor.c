#include "sensor.h"

void initializeLedPins(){
	P1DIR |= 0x01;
	P1DIR |= 0x02;
}

void initializeADC10(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
}

void checkLeftSensor(){
	ADC10CTL1 = INCH_3;
	ADC10AE0 |= BIT3;
}

void getInputFromSensor(){
	ADC10CTL0 |= ENC + ADC10SC;
	_delay_cycles(100);
	ADC10CTL0 &= ~ENC;
}
