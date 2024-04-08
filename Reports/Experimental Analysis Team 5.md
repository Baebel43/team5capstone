# Team 5 - Ride Replay Kit
## Team Members: Benjamin Ebel, Caleb Rozenboom, Caleb Turney, Jayden Marcom, Jesse Brewster, Utsav Singha

## Experimentation

### GUI Subsystem - Benjamin Ebel

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|

### Resistance Subsystem - Caleb Rozenboom

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|

### Immersion Subsystem - Caleb Turney

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|
|Off Switch|To allow the user to turn off the fan output when riding, an off switch was implemented into the GUI of the device. This switch is a toggle that limits the output of the fans once pressed. Once the option is pressed, the send data variable that initially reads from the sensor is replaced with a 0 value so that the fans are not receiving new inputs from the bike. This remains implemented until the user presses the switch again and allows the fan to read from the sensor.|This was tested by running the program and pressing the switch multiple times during the bike's functional period. At each point in time that the switch was pressed, the fans displayed that they were receiving a value of zero and no longer outputted. This switch follows the off button constraint that was set therefore this constraint is fulfilled.|YES||
|Fan Mapping|The speed of a fan is directly proportional to the PWM duty cycle that the fan is driven with. To test this mapping constraint and ensure that the fans output was mapped to the scaled wind speed, the sensor data sent from the pi to the arduino had to be scaled. The calculated values from the signoff for speed were taken and a ratio was created between that speed and the PWM range of the fan. The 8-bit PWM range for the fan was 0-255 and the RPM range of the fan was 0-5800 . This means that for every 1 PWM there was an equivalent 22.75 RPM. The PWM was then found for each calculated RPM value in the signoff so that there was an accurate PWM value for each scaled speed value. A ratio was then found by taking each of the calculated PWM values and dividing them by the scaled speed value they were associated with. This resulted in a value of 12.3732523. This value was taken and implemented into the code so that every value that was read from the sensor would be multiplied by it.|The accuracy of this was tested by having the arduino display the speed that was read from the bike sensor and also the scaled PWM value that the fan was being driven with. The values matched those that were calculated meaning that the fan mapping constraint was fulfilled.||
|Fan Control|YES|||
|Output Noise Level||||
|Power||||

### Work Subsystem - Jayden Marcom

### Audio Subsystem - Jesse Brewster

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|

### Video Subsystem - Utsav Singha

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|
