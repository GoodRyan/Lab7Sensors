#include "sensor.h"

void initializeLedPins(){
	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

void initializeADC10(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
}

void checkLeftSensor(){
	ADC10CTL1 = INCH_3;
	ADC10AE0 |= BIT3;
	__bis_SR_register(CPUOFF + GIE);
}

void checkRightSensor(){
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	__bis_SR_register(CPUOFF + GIE);
}

void getInputFromSensor(){
	ADC10CTL0 |= ENC + ADC10SC;
	_delay_cycles(100);
	ADC10CTL0 &= ~ENC;
}
