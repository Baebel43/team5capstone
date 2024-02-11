
Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha, Caleb Turney

# Detail Design: Immersion System


##  Subsystem Functionality

The immersion subsystem will drive fans that are pointed toward the user. A tachometer wil be used to indicate how fast the user is virtually moving. Based on the speed measured, the speedometer will drive the fans. The faster the speed, the faster the fans will rotate. By connecting the RPM of the fans proportionally to the speed being traveled, a more immersive experience can be achieved, since the user will be able to artificially feel the changes in their acceleration.

Components from previous iterations of this project will be utilized for this subsystem. A tachometer was added to the bike by a previous team that was used as a speed sensor for the ride replay system. The previous speed sensor would take data from the bike as the user rode the trails, then that data would be sent through ble to a raspberry pi. The fans will be connected to this raspberry pi and the speed sensor data will used to either increase or decrease the rpm of the fans. Previous codes for the microcontroller will be utlized to allow ble communication and new code will be added to properly connect the fans to speed that is read. The previous power distribution system will also be used to power the fans. 

## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Off Switch|The speedometer shall have an off switch implented that allows the user to disable the system.|
|Maximum RPM| The maximum number of rotations per minute (rpm) of the fans will be 2500.|
|Power|The fans will be supplied a minimum of (TBD) watts of power|


## Analysis

### Things to think about

* Must be able to be turned off in case the user does not want to use the function. Also should be adjustable so that user can choose where the wind from fans will be blowing.
* Either directly taking from the speed of the tachometer, or from the work system or other systems, the rpm of the fans should proportionaley increase with an increase of the users speeds and acceleration
* Fans should have a maximum rpm they are allowed to reach, and an appropriate amount of power to drive them.
* Fans will neeed a way to be mounted near the bike
* Potentially have a base setting that is a consistent rpm for fans when going along the trail, they can decide if the want it to be on an adaptive setting.
  

### Meeting off button constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be included that will allow the user to shut the subsytem off. 

### Metting maximum rpm constraint

The average desk fan has an rpm of around 1300-2000 [reference]. For the immersion subsytstem, the fans need to rotate fast enough for air to reach the user and also have a large enough range to proportionaly adapt to the users speed. A maximum rpm constraint of 2500 has been set, this number will allow the fan to have a speed fast enough to immerse the user when virtually traveling at high speeds, but will also not be too loud ad disrupt immersion.

(explanation)

According to the datasheet of the fan ______________, it has a maximum rpm of _______ [reference]

### Meeting power constraint

In the previous renditions of this project, the groups used _________ to power their system. The same method of powering will be used for the fans. The fans will be connected to __________.

## Circuit Schematic

## 3D Model

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Hall Effect Sensor|Hall Effect Sensor Single Axis TO-92-3|DRV5056A2ELPGMQ1|Texas Instruments|2|$2.01|$4.02|

|Total|||Total Components|7|Total Cost|$72.93


## References:

[1]”DRV5056-Q1 Automotive Unipolar Ratiometric Linear Hall Effect Sensor,” https://www.ti.com/lit/ds/symlink/drv5056-q1.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1698173863097&ref_url=https%253A%252F%252Fwww.ti.com%252Fgeneral%252Fdocs%252Fsuppproductinfo.tsp%253FdistId%253D10%2526gotoUrl%253Dhttps%253A%252F%252Fwww.ti.com%252Flit%252Fgpn%252Fdrv5056-q1 (accessed Oct. 25th, 2023)


