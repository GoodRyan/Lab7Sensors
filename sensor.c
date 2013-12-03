#include "sensor.h"

void initializeLedPins(){

}

void initializeADC10(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
}
