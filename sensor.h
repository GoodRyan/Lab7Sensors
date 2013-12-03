#ifndef _sensor_h
#define _sensor_h
#include <msp430.h>

void initializeLedPins();

void initializeADC10();

void checkLeftSensor();

void getInputFromSensor();

#endif
