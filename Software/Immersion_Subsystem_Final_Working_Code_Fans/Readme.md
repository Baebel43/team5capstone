This is the code for the Atmega 2560 that is used control the Fans.

This code controls both the PWM that drives the fan and the I2C connection the Raspberry Pi that allows that the Pi and Arduino to send data to each other. Make sure to consult the wiring schematic to ensure all the wires are connected to the correct ports or the code will not run properly. 

Also note that this code was created to run on the Arduino Atmega 2560. If you wish to run the code on a different Arduino, some of the registers and commands will need to be changed accordingly to match.

**Steps to Run Code**


