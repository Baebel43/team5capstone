
Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha, Caleb Turney

# Detail Design: Immersion System


##  Subsystem Functionality

The immersion subsystem will drive fans that are pointed toward the user. A tachometer wil be used to indicate how fast the user is virtually moving. Based on the speed measured, the speedometer will drive the fans. The faster the speed, the faster the fans will rotate. By connecting the RPM of the fans proportionally to the speed being traveled, a more immersive experience can be achieved, since the user will be able to artificially feel the changes in their acceleration.

Components from previous iterations of this project will be utilized for this subsystem. A tachometer was added to the bike by a previous team that was used as a speed sensor for the ride replay system. The previous speed sensor would take data from the bike as the user rode the trails, then that data would be sent through ble to a raspberry pi. The fans will be connected to this raspberry pi and the speed sensor data will used to either increase or decrease the rpm of the fans. Previous codes for the microcontroller will be utlized to allow ble communication and new code will be added to properly connect the fans to speed that is read. The previous power distribution system will also be used to power the fans. 

## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Off Switch| The speedometer shall have an off switch implented that allows the user to disable the system.|
|Maximum RPM| The maximum number of rotations per minute (rpm) of the fans will be 2500.|
|Output Noise Level| The fans will have a max noise level output of 40 dBA|
|Power|The fans will be supplied a minimum of (TBD) watts of power|


## Analysis

### Things to think about

* Must be able to be turned off in case the user does not want to use the function. Also should be adjustable so that user can choose where the wind from fans will be blowing.
* Either directly taking from the speed of the tachometer, or from the work system or other systems, the rpm of the fans should proportionaley increase with an increase of the users speeds and acceleration
* Fans should have a maximum rpm they are allowed to reach, and an appropriate amount of power to drive them.
* Fans will neeed a way to be mounted near the bike
* Potentially have a base setting that is a consistent rpm for fans when going along the trail, they can decide if the want it to be on an adaptive setting.
  
### (NOT SURE WHAT CONSTRAINT TO MAKE THIS)

The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

What goes here: Approximate range of speed we believe the user will be traveling, proportional conversion to range of voltage values that fall within 0-(rated voltage of fans),


### Meeting Off Button Constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be included that will allow the user to shut the subsytem off. This will be connected to the raspberry pi output to the fans and will block the voltage flow from the pi to the fans until pressed again. 

### Metting Maximum Rpm Constraint

The average desk fan has an rpm of around 1300-2000 [reference]. For the immersion subsytstem, the fans need to rotate fast enough for air to reach the user and also have a large enough range to proportionaly adapt to the users speed. A maximum rpm constraint of 2500 has been set, this number will allow the fan to have a speed fast enough to immerse the user when virtually traveling at high speeds, but will also not be too loud ad disrupt immersion.

(explanation)

According to the datasheet of the fan CFM-A238V-121-370-20, it has a maximum rpm of 2100 [2]. This is a good speed for the fan as it allows enough speed to create sufficient airflow but stays unders the constraint of 2500 rpm. 

### Meeting Output Noise Level Constraint

While the OSHA standard limit for noise level is under 85 dB for 8 hours, that is not the only constraint that should be taken into account when using fans. For this susbsystem, the fans should be fast enough to properly provide air to the user, but not be so loud as to cause annoyance or discomfort. When it comes to noise levels, around 40 dBA is when many people start to consider a noise as distracting[1]. The ride replay system is not meant to be a completely silent device, so with this value in mind, a constraint of 40 dBA has been placed on the fans that will be used for this system. This value gives room for a wide selection of fans and speeds and is a noise level that should not cause the user any discomfort. 

According to the datasheet of the fan CFM-A238V-121-370-20, it has a rated noise level 37.0 dBA. This value is less than 40 dBA meaning this fan will be sufficient in fulfilling this constraint.

### Meeting power constraint

In the previous renditions of this project, the groups created a power distribution system to power their componenets. The same method of powering will be used for the fans. The fans will be connected to the already installed raspberry pi which will deliver the necessary power. The CFM-A238V-121-370-20 is rated to operate at 12 VDC and an input current of 277 mA. This equates to a total power draw of 3.324 Watts. The power distribution system is comprised of multiple DIN rail power supplies, each of which is capable of delivering 45 watts of power or more. Since two fans will be used for this subsystem, a total power of 6.648 W will be needed. This is within the capabilities of the previously built power system meaning the fans will be delivered their full power and be able to operate within their full range.
## Buildable Schematic

## 3D Model

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|DC Brushless Fan|CFM-A238V-121-370-20|CUI Devices|2|$15.63|$31.26|

|Total|||Total Components|7|Total Cost|$31.26


## References:

[1]“Decibels dBA,” Decibels dba, https://silentpc.com/articles/decibels (accessed Feb. 11, 2024). 
[2] “CFM-120V series datasheet - axial fans - cui devices,” SERIES: CFM-120V | DESCRIPTION: DC AXIAL FAN, https://www.cuidevices.com/product/resource/cfm-120v.pdf (accessed Feb. 12, 2024). 


