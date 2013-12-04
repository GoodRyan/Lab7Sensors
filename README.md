RobotSensorLibrary
==================

A library that allows for easy interfacing with the robot sensors.

## Functions

- `void initializeLedPins()`
	- Sets the LED pins as outputs to enable them to be turned on or off depending on the values produced by checkLeftSensor and checkRightSensor.

- `void initializeADC10()`
	- Sets up the ADC10 registers appropriately for use with the robot sensors.

- `unsigned int checkLeftSensor()`
	- Returns the voltage found at the left sensor after configuring the left sensor.

- `unsigned int checkRightSensor()`
	- Returns the voltage found at the right sensor after configuring the right sensor.

- This library also contains interrupt code for ADC10.

## Example Code

```c
//This code would initialize the ADC10 register and then return the left sensor voltage
initializeADC10();
int voltageAtLeftSensor = checkLeftSensor();
```
