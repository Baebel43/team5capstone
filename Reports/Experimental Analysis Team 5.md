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
|Fan Mapping|The speed of a fan is directly proportional to the PWM duty cycle that the fan is driven with. To test this mapping constraint and ensure that the fans output was mapped to the scaled wind speed, the sensor data sent from the pi to the arduino had to be scaled. The calculated values from the signoff for speed were taken and a ratio was created between that speed and the PWM range of the fan. The 8-bit PWM range for the fan was 0-255 and the RPM range of the fan was 0-5800 . This means that for every 1 PWM there was an equivalent 22.75 RPM. The PWM was then found for each calculated RPM value in the signoff so that there was an accurate PWM value for each scaled speed value. A ratio was then found by taking each of the calculated PWM values and dividing them by the scaled speed value they were associated with. This resulted in a value of 12.3732523. This value was taken and implemented into the code so that every value that was read from the sensor would be multiplied by it.|The accuracy of this was tested by having the arduino display the speed that was read from the bike sensor and also the scaled PWM value that the fan was being driven with. The values matched those that were calculated meaning that the fan mapping constraint was fulfilled.|YES|
|Fan Control|The fan control constraint was tested by running both the bike code and the arduino fan code at the same time. If the speed of the fans changed when the sent value of the bike speed changed, it meant that the fans were being properly controlled and adapting to new inputs.|Whenever the user increased or decreased the speed, a new value was sent to the fans which resulted in visible and audible change in speed. This shows that the fans are indeed adjustable therefore this constraint is fulfilled.|YES|
|Output Noise Level|An app on the phone was used to test the output noise level of the fan. The fan was run at different speeds while the phone was held approximately 4 feet away.|The max decibels that were read was around 65-66 dBA. This was tested at multiple different speeds to give a wide range of different sound output levels. This falls slightly outside the range set in this constraint but is within an acceptable margin for safe testing. Due to how close this value is to the constraint set it will not be considered fulfilled.|NO|Setting different PWM frequencies on the fan can have an effect on the noise level that the fan outputs. More research and testing on this frequency may result in a value that allows the fans to fall within a more acceptable sound level range.
|Power|To test the power draw of the fan, the fan was connected to both the wall wart power supply and an adjustable bench power supply in the lab. A multimeter was connected so that both the voltage and the current draw of the fan could be measured.|When the fan was run at full power, the voltage reading was approximately 11.3 and the current draw was 1.67. The adjustable power supply was used to confirm that the readings were not the result of a lack of power from the chosen wall wart power supply. This shows that the fan only used around 18.871 Watts of power. The wall wart is rated to supply 60 Watts of power therefore it was reasonably inferred that the 28.8 watts of power outlined in the constraint were achievable. However, due to the fans not drawing that much power it cannot be said with 100% certainty that this is true. This constraint is considered fulfilled.|YES|

### Work Subsystem - Jayden Marcom

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|


### Audio Subsystem - Jesse Brewster

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|

### Video Subsystem - Utsav Singha

| Item | Testing Method | Results | Was The Constraint Fulfilled | Why Was The Constraint Not Fulfilled (if applicable) |
|------|----------------|---------|------------------------------|------------------------------------------------------|
|Minimum Recording FPS|The team viewed each recording file to verify it was at the specified minimum FPS of 60|The video recordings were always at the minimum FPS requirement.|YES|
|Minimum Resolution|The team recorded the video at the resolution of 1080p, then replayed it on the bike through the RaspberryPi, and checked for video stability.|Due to the low RAM space on the RaspberryPi, 1080p would cause visual tear, distortions, and overall lag. The team then adjusted the video output on the RaspberryPi and tried replaying at 720p, and although the result was slightly better, the issues from the previous test persisted. After dropping the resolution to 480p the video was finaly stable and was replayable smoothly.|NO|The RaspberryPi could not sustain video resolutions above 480p without major visual tear and distortion.|
|Minimum User Speed|The team hard set the video replay on the RaspberryPi to replay the video at 25% speed, and checked the display to make sure the video was replaying smoothly with no breakage or stuttering. The team would also take this time to ensure the video was interpolated with no issues or distortions from the interpolation process|The video was stable and smooth while replayed at 25% of the original rider's speed. The interpolation software worked with no issues.|YES|
|Storage Space Requirements|The team took a 4 hour long ride and interpolated the video recorded before compressing said video to ensure it was within the 216GB max storage space requirement|Initially a 4 hour 720p video was used, but after interpolation, the video was going to be well over 2 terabytes and would not even fit on the drive of the PC used to run FlowFrames. Since the RaspberryPi also could not run 720p videos, the team decided to drop the video resolution to 420p. Next, a 4 hour 420p 60 FPS video was used to ensure it would fit on the drive, however this too was over 1 terabyte. After running a 2 hour 420p 60 FPS video through the system, the video took up exactly 215.5 gigabytes of storage, which now fits within the constraint.|NO|4 hours of video was not feasable due to the interpolated videos being almost 1 terabyte of space. After testing, the max video length at 420p is 2 hours.|

