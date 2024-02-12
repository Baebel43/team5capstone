
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
|Power|The fans will be supplied a minimum of 2.85 watts of power|


## Analysis

### How the System Will Work
The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

Although the max speed one can achieve on a bike is above 100 mph, the average speed that a user will ride is anywhere between 10 for inexperienced riders up to 24 mph for more experienced riders [3]. With this in mind, the max speed of the fans will be proportionaly connected to a max speed of 20 mph on the bike. The CFM-A225C-020-350-22 has a max speed of 2000 rpm. If the the minimum of both the fan speed and bike speed is set at 0, then we can calculate the correct ratio between the two. 

**Speed Ratio = $$\ \frac{1} {20} = \frac{X} {2000}$$ >> $$\20x = 200$$**

What goes here: Approximate range of speed we believe the user will be traveling, proportional conversion to range of voltage values that fall within 0-(rated voltage of fans),


### Meeting Off Button Constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be included that will allow the user to shut the subsytem off. This will be connected to the raspberry pi output to the fans and will block the voltage flow from the pi to the fans until pressed again. 

### Metting Maximum Rpm Constraint

The average desk fan has an rpm of around 1300-2000 [reference]. For the immersion subsytstem, the fans need to rotate fast enough for air to reach the user and also have a large enough range to proportionaly adapt to the users speed. A maximum rpm constraint of 2500 has been set, this number will allow the fan to have a speed fast enough to immerse the user when virtually traveling at high speeds, but will also not be too loud and disrupt immersion.

According to the datasheet of the fan CFM-A225C-020-350-22, it has a maximum rpm of 2000 [2]. This is a good speed for the fan as it allows enough speed to create sufficient airflow but stays unders the constraint of 2500 rpm. 

### Meeting Output Noise Level Constraint

While the OSHA standard limit for noise level is under 85 dB for 8 hours, that is not the only constraint that should be taken into account when using fans. For this susbsystem, the fans should be fast enough to properly provide air to the user, but not be so loud as to cause annoyance or discomfort. When it comes to noise levels, around 40 dBA is when many people start to consider a noise as distracting[1]. The ride replay system is not meant to be a completely silent device, so with this value in mind, a constraint of 40 dBA has been placed on the fans that will be used for this system. This value gives room for a wide selection of fans and speeds and is a noise level that should not cause the user any discomfort. 

According to the datasheet of the fan CFM-A225C-020-350-22, it has a rated noise level 37.8 dBA. This value is less than 40 dBA meaning this fan will be sufficient in fulfilling this constraint.

### Meeting power constraint

In the previous renditions of this project, the groups created a power distribution system to power their componenets. The same method of powering will be used for the fans. The fans will be connected to the already installed raspberry pi which will deliver the necessary power. The raspberry pi being used is the Model 3 B+. The recommended amperage limit for the pi is 2.5 amps. The CFM-A225C-020-350-22 is rated to operate at 5 VDC and an input current of 0.57 A. This equates to a total power draw of 2.85 Watts. The power distribution system is comprised of multiple DIN rail power supplies, each of which is capable of delivering 45 watts of power or more. Since two fans will be used for this subsystem, a total power of 6.648 W will be needed. This is within the capabilities of the previously built power system meaning the fans will be delivered their full power and be able to operate within their full range. 

The CFM-A225C-020-350-22 has 4 connections wires: +Vin, -Vin, and Tach signal, and PWM signal. The fan speed will be controlled via the PWM0 port GPIO12 on the raspberry pi. The fans will be connected to the 5v output of the pi. 

## Buildable Schematic

<img width="678" alt="Screen Shot 2024-02-12 at 12 04 32 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/3a0ad067-a5f4-4a1d-a446-cd1a15e2a534">

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|DC Brushless Fan|CFM-A225C-020-350-22|CUI Devices|2|$8.73|$17.46|

|Total|||Total Components|7|Total Cost|$31.26


## References:

[1]“Decibels dBA,” Decibels dba, https://silentpc.com/articles/decibels (accessed Feb. 11, 2024). 
[2] “CFM-120C series datasheet - axial fans - cui devices,” SERIES: CFM-120C | DESCRIPTION: DC AXIAL FAN, https://www.cuidevices.com/product/resource/cfm-120c.pdf (accessed Feb. 12, 2024). 
[3] “Average cycling speed for new and experienced cyclists,” Road Bike, https://www.road-bike.co.uk/articles/average-speed.php (accessed Feb. 12, 2024). 

