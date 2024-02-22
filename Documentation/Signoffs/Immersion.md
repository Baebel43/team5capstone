Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha, Caleb Turney

# Detail Design: Immersion System


##  Subsystem Functionality

The immersion subsystem will drive fans that are pointed toward the user. A tachometer wil be used to indicate how fast the user is virtually moving. Based on the speed measured, the fans will spin and simulate the force of wind. The faster the speed, the faster the fans will rotate. And as how in real life the force of wind exponentially increases as the speed of an object increase, the fans will attempt to simulate this force and ramp up in rpm at an increasing rate as the users miles per hour grows. By connecting the RPM of the fans proportionally to the speed being traveled, a more immersive experience can be achieved, since the user will be able to artificially feel the changes in their acceleration.

Components from previous iterations of this project will be utilized for this subsystem. A tachometer was added to the bike by a previous team that was used as a speed sensor for the ride replay system. The previous speed sensor would take data from the bike as the user rode the trails, then that data would be sent through ble to a raspberry pi. The fans will be connected to this raspberry pi and the speed sensor data will used to either increase or decrease the rpm of the fans. Previous codes for the microcontroller will be utlized to allow ble communication and new code will be added to properly connect the fans to speed that is read. The previous power distribution system will also be used to power the fans. 

## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Off Switch| The speedometer shall have an off switch implented that allows the user to disable the system.|
|RPM Mapping| The rpm of the fans will be mapped to the virtual speed that the user is traveling|
|Fan Control| The speed of the fans will be adjustable and adaptable|
|Output Noise Level| The fans will have a max noise level output of 60 dBA|
|Power|Each of the fans will be supplied a minimum of 28.80 watts of power|


## Analysis






### Meeting the RPM Mapping Constraint

The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

Although the max speed one can achieve on a bike is above 100 mph, the average speed that a user will ride is anywhere between 10 for inexperienced riders up to 24 mph for more experienced riders [3]. This speed can reach upwards of 30 and 45 when the user is on an incline. With this in mind, the max wind speed of the fans will be connected to a max speed of 45 mph on the bike.

When it comes to choosing a fan for the immersion subsystem, it is important that the fan has a high enough CFM (Cubic Feet per Minute) value. CFM is the measurement of the volume of air that a fan is capable of moving. In order to convert CFM to a speed value you would have to know the measurements of the room and the static pressure within it. For the scope of this project, the goal is not to circulate air in the room but to push air from the fans on to the face of the user. It is impossible to precisely calculate the speed and the force that a fan will produce in an open space without being able to physically test it. So, for the sake of simplicity, a fan with a comparatively high CFM will be chosen and if the max power and speed ends up being too high then the maximum RPM of the fan will be limited. A PC cooling fan will have on average between 50-80 CFM depending on the quality and the size. This value needs to be marginally higher in order for the wind from the fans to reach the user and provide any sort of noticeable force. Therefore, the CFM-A225BF-158-597-22 has been chosen with a CFM value of 185.5. Extra testing will need to be done in regards to the distance of the positioning of the fans and their max power output, but this value should be adequate in pushing enough air towards the user to provide an immersive experience through changing speeds.

The goal of the immersion system is to have the speed of the wind that the fans output match the speed of wind outside while the user is traveling. Although there are many factors that can affect wind speed from a fan, for the sake of this project, it will be assumed that the air around the fan is perfectly stationary and all the air movement comes from the fans alone. With these assumptions we can use the formula for wind speed in miles per hour

**$$\ Wind Speed (WS) = \frac{π * r^2 * RPM * 60}{5280} $$**

Where the windspeed is WS, πr^2 is the diamter of the fan, RPM is the rotations per minute of the fan, and 60/5280 is the conversion to miles per hour[7]. The diamater of the CFM-A225BF-158-597-22 fan is approximately 110mm which is equal to approximately 4.33 inches. Rearranging this formula, we can find what the RPM would be for the fan at different wind speeds. 

<img width="147" alt="Screen Shot 2024-02-22 at 5 33 52 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/2d2f28ad-18d5-4bce-aa25-24e2bd2c1ddd">

Figure 1. Calculated RPM values from wind speed formula. 

As shown in the table in figure 1 and the formula for wind speed, there is a linear relationship between the RPM of a fan and the wind speed that it outputs. This is assuming static airflow factors where not forces of drag or resistance are present. Using these values from the table, they can be scaled up to better account for the full range that the fan can handle. Although the formula calculates some of the values for rpm to be below 100 rpm, at this speed the fan will not be able to generate nearly enough pressure to move any air forward. So by scaling the fan values it  will allow the fan to operate at a wider range and will also help account for unknown variables that may limit airflow during testing. The maximum value at 45 mph that was calculated at 3501 will be scaled up to 5000. This rpm utilizes the upper capabilites of the fan and also allows room for increase and change if the need may arise during testing. The new table of scaled values is as follows:


<img width="172" alt="Screen Shot 2024-02-22 at 5 43 21 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/ee28ba1c-cb28-4082-8d8c-b6259264d2dd">

Figure 2. Scaled RPM Values

These values match up to the desired range of wind speeds with a buffer scaling that will help account for unknown factors in airflow. In the code pwm code for the fans these values will be used as the basis for the speed of the fans, as the tachometer sends values the speed will be read, then the fan will change to the appropriate RPM value.

### Meeting the Fan Control Constraint

To create an immersive riding experience for the user, it is important that the fans are controllable and able to change their output based on the speed that the user is traveling. The CFM-A225BF-158-597-22 is PWM controllable meaning that it can be hooked up the PWM output of the Raspberry pi and its speed can be programmed using pulse width modulation. The speed of the user will be taken from the tachometer and sent to the Rpi and a code will be ran to use that speed data and convert it to a proportional output for the fan. As the speed data that is sent gets changed, a change in the speed of the fans will be noticeable as well. 


### Meeting Off Button Constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be programmed into the fan code that will allow the user to shut the subsytem off. This will keep the fans from outputting until the user decides that they want to turn it back on. 

### Meeting Output Noise Level Constraint

While the OSHA standard limit for noise level is under 85 dB for 8 hours, that is not the only constraint that should be taken into account when using fans. For this susbsystem, the fans should be fast enough to properly provide air to the user, but not be so loud as to cause discomfort. Around 60 dB is the sound level of a normal conversation and past this noises start to be considered loud and potentially annoying. With this is mind, the constraint of 60 dB has been set for the fans maximum sound output. At this noise level, the fans will be very noticeable and easily heard but not at the level that should cause pain or discomfort to individuals.

According to the datasheet of the fan CFM-A225BF-158-597-22, it has a rated noise level 59.7 dBA. This value is less than 60 dBA meaning this fan will be sufficient in fulfilling this constraint.

### Meeting power constraint

<!-- In the previous renditions of this project, the groups created a power distribution system to power their componenets. The same method of powering will be used for the fans. The fans will be connected to the already installed raspberry pi which will deliver the necessary power. The raspberry pi being used is the Model 3 B+. The recommended amperage limit for the pi is 2.5 amps. The CFM-A225BF-158-597-22 is rated to operate at 5 VDC and an input current of 0.57 A. This equates to a total power draw of 2.85 Watts. The power distribution system is comprised of multiple DIN rail power supplies, each of which is capable of delivering 45 watts of power or more. Since two fans will be used for this subsystem, a total power of 6.648 W will be needed. This is within the capabilities of the previously built power system meaning the fans will be delivered their full power and be able to operate within their full range. -->

When it comes to the goal of this subsystem, it is important that the fans are powerful enough to push winds towards the user that provides ample force that is at least partially indicative of a physical trail riding experience. When considering the 5V fan options available on the market, they are not powerful enough or provide enough cfm to produce much wind force without being within a very close proximity to the user. With this in mind, 12V options had to be taken into account with the goal of a successful immersion system in mind. The Rpi is only capable of powering up to 5V fans, so an external power supply will need to be utilized in order to provide ample power to the fans and let them operate at their full range. The fans will be connected to the PWM GPIO of the raspberry pi and powered by an external source. 

The CFM-A225BF-158-597-22 fan is a 12V fan that is rated to have a current draw of 2.4 Amps equalling out to a power draw of 28.8 Watts. With there being two fans that measn the total power draw will be 57.6 amps. With this in mind, a 12V 5A 60W power supply has been chosen to power the fans. It comes with a female DC connector piece that will allow a connection to fans. 


The CFM-A225BF-158-597-22 has 4 connections wires: +Vin, -Vin, and Tach signal, and PWM signal. The fan speed will be controlled via the PWM0 port GPIO12 on the raspberry pi. The fans will be connected to the external 60W power supply.

## Buildable Schematic

<img width="1071" alt="Screen Shot 2024-02-21 at 5 25 00 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/d1934595-0775-4899-acdc-7b06734e968f">


Figure 1. Circuit Schematic for Fan Connection to Raspberry pi

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|DC Brushless Fan|CFM-A225BF-158-597-22|CUI Devices|2|$45.85|$71.7|
|DC 12V 5A 60W Power Supply||Arybroourd|1|$10.87|$10.87|
|Total|||Total Components|2|Total Cost|$82.57|


## References:

[1]“Decibels dBA,” Decibels dba, https://silentpc.com/articles/decibels (accessed Feb. 11, 2024). 

[2] “CFM-120BF series datasheet - axial fans - cui devices,” SERIES: CFM-120BF | DESCRIPTION: DC AXIAL FAN, https://www.cuidevices.com/product/resource/cfm-a225bf-153-577.pdf (accessed Feb. 12, 2024). 

[3] “Average cycling speed for new and experienced cyclists,” Road Bike, https://www.road-bike.co.uk/articles/average-speed.php (accessed Feb. 12, 2024). 

[4] T. N. Crouch, D. Burton, Z. A. LaBry, and K. B. Blair, “Riding against the wind: A review of Competition Cycling Aerodynamics - Sports Engineering,” SpringerLink, https://link.springer.com/article/10.1007/s12283-017-0234-1 (accessed Feb. 18, 2024). 

[5] J. Quinones, “4 ways to calculate wind load,” wikiHow, https://www.wikihow.com/Calculate-Wind-Load (accessed Feb. 18, 2024). 

[6] "DC 12 Volt 5 Amp Power Supply - 60W https://www.amazon.com/Supply-Adapter-100-245V-50-60Hz-Connector/dp/B0BJVVBBMJ/ref=sr_1_13?dib=eyJ2IjoiMSJ9.NdG7lJz6NP5jClxT5_rsJeQSFy8O-Y6IaMFn27sm2Z4cLQhvVEscFhQnC2mLwLUsDTp_Tp-l4s3a2YvgOkhYmOqKQ92SUN4Ejnzad3hOzjNh8WQbPqMc4Fi0BagE8GBtlVnZGsVvKqBcf-Yr6MFRcgk4K30FVhDx2EkWVvXvu61DxzJOVGKHNvISYF9RS7eoe1p441zVA-CikZmCjmOlg6gg76B8YZ7t_L_20GJ19rM.h_7I5SjaCUJVQSA-XJtS8eEyX-OEekI9otaB_Z9rtnc&dib_tag=se&keywords=12v+5a+power+supply&qid=1708556650&sr=8-13

[7] “Fan wind speed calculator,” Calculator Academy, https://calculator.academy/fan-wind-speed-calculator/ (accessed Feb. 22, 2024). 
