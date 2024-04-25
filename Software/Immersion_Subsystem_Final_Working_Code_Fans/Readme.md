This is the code for the Atmega 2560 that is used control the Fans.

This code controls both the PWM that drives the fan and the I2C connection the Raspberry Pi that allows that the Pi and Arduino to send data to each other. Make sure to consult the wiring schematic to ensure all the wires are connected to the correct ports or the code will not run properly. 

Also note that this code was created to run on the Arduino Atmega 2560. If you wish to run the code on a different Arduino, some of the registers and commands will need to be changed accordingly to match.

## Steps to Run Code:

1: Ensure that proper wiring has been done for the Arduino and Raspberry pi via the schematic. Ensure that the grounds of the external DC supply, Arduino, and Raspberry Pi are all connected. Ensure that the SCL and SDA pins on the Rpi are connected to the SCL and SDA pins on the Atmega. Ensure that the PWM wire of the fan is connected to Pin 9 on the Atmega.

2: Make sure that both the Arduino code and Raspberry Pi code are running simultaneously else there will be no connection and no data will be sent. Consult the Raspberry Pi software documentation for the necessary code to run.

3: Ensure that the power switch is set to on for the Immersion system enclosure, and that the fans are toggled on in the GUI. Failure to do so will result in the fans not running properly.


