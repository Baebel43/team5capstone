Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha, Caleb Turney

# Detail Design: Immersion System


##  Subsystem Functionality

The immersion subsystem will drive fans that are pointed toward the user. A tachometer wil be used to indicate how fast the user is virtually moving. Based on the speed measured, the fans will rotate at a specific RPM. The faster the measured speed, the faster the fans will rotate. The goal will be for the fans to simulate the speed of the wind outside by outputting at the same or scaled but similar wind speed. By having the fans adapt and change their speed based on the riders speed, a more immersive experience can be achieved, since the user will be able to artificially feel the changes in their speed.

Components from previous iterations of this project will be utilized for this subsystem. A tachometer was added to the bike by a previous team that was used as a speed sensor for the ride replay system. The previous speed sensor would take data from the bike as the user rode the trails, then that data would be sent through ble to a raspberry pi. The fans will be connected to this raspberry pi and the speed sensor data will used to either increase or decrease the rpm of the fans. Previous codes for the microcontroller will be utlized to allow ble communication and new code will be added to properly connect the fans to speed that is read. The previous power distribution system will also be used to power the fans. 

## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Off Switch| The speedometer shall have an off switch implented that allows the user to disable the system.|
|Fan Mapping| The fans will be mapped to output at a scaled version of outside wind speed |
|Fan Control| The speed of the fans will be adjustable and adaptable|
|Minimum RPM| The fan shall spin at a minimum of 1,105 RPM|
|Output Noise Level| The fans will have a max noise level output of 60 dBA|
|Power|Each of the fans will be supplied a minimum of 28.80 watts of power|


## Analysis



### Meeting the Fan Mapping Constraint

The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

Although the max speed one can achieve on a bike is above 100 mph, the average speed that a user will ride is anywhere between 10 for inexperienced riders up to 24 mph for more experienced riders [3]. This speed can reach upwards of 30 and 35 when the user is on an incline. With this in mind, the max wind speed of the fans will be connected to a max speed of 35 mph on the bike.

When it comes to choosing a fan for the immersion subsystem, it is important that the fan has a high enough CFM (Cubic Feet per Minute) value. CFM is the measurement of the volume of air that a fan is capable of moving. In order to convert CFM to a speed value you would have to know the measurements of the room and the static pressure within it. For the scope of this project, the goal is not to circulate air in the room but to push air from the fans on to the face of the user. It is impossible to precisely calculate the speed and the force that a fan will produce in an open space without being able to physically test it. So, for the sake of simplicity, a fan with a comparatively high CFM will be chosen and if the max power and speed ends up being too high then the maximum RPM of the fan will be limited. A PC cooling fan will have on average between 50-80 CFM depending on the quality and the size. This value needs to be marginally higher in order for the wind from the fans to reach the user and provide any sort of noticeable force. Therefore, the CFM-A225BF-158-597-22 has been chosen with a CFM value of 185.5. Extra testing will need to be done in regards to the distance of the positioning of the fans and their max power output, but this value should be adequate in pushing enough air towards the user to provide an immersive experience through changing speeds.

The goal of the immersion system is to have the speed of the wind that the fans output match the speed of wind outside while the user is traveling. Although there are many factors that can affect wind speed from a fan, for the sake of this project, it will be assumed that the air around the fan is perfectly stationary and all the air movement comes from the fans alone. It will also be assumed that the cross sectinal area that the flan is blowing into will be equal to the circumference of the fan. The diameter of entire CFM-A225BF-158-597-22 fan frame is 120mm, there is approximately 10 mm of frame so the diameter of the actual fan will be taken as 110 mm. This makes the radius equal to 55mm so if we find the cross sectional area, which is πr^2, then we get an area of 0.1023 square feet. The datasheets for fans do not include their winds speeds but instead their CFM so these values must be converted to get an idea of what the fans output wind speed will be. The formula to convert CFM to FPM is [9]:

**$$\ FPM = CFM/(Cross Sectional Area_ft^2)$$**

Then by converting the Feet per minute to Miles per hour, you get the wind speed in MPH.

If we take the max CFM value of the CFM-A225BF-158-597-22 fan, which is 185.5, then divide by the area of 0.1023 square feet and convert to mph, then we acquire an mph equivalent value of 20.6056 Mph. This will be used as the max value for the fan wind speed, and to connect it to the speed of the user the values will be scaled to match. This means that for the scope of this design, 20.6056 mph will be equal to 35 mph, which is the range of the outside wind speed values scaled down by 41.13%. With this scale factor in place, the cfm values for each mph in the range can be found, and then the appropriate rpm can be apllied.

<img width="293" alt="Screen Shot 2024-02-23 at 9 47 18 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/fd3a82c0-c903-4ab3-b917-6488134343da">

Figure 1. Full Data set for MPH to RPM

As Shown in figure 1, the values from the speed range are scaled down to fit parameters, then using the CFM to MPH conversion formula that was previously outlined, the CFM at each of those scaled speed values is found. As will be explained more later, the CFM values for a fan and the RPM are directly proportional[8]. So by taking the max CFM value of 185.5 and the max RPM value of 5800 for the CFM-A225BF-158-597-22 fan, a ratio of 31.24 RPM to every CFM can be calculated. Using this, the relative RPM values for each of the calculated CFM values was found. 
For speeds of 1-6mph then value of the rpm of the fans will be set to the minimum value contraint of 1,105 rpm. This will be explained in detail further into the analysis but the purpose is to provide a minimum speed that will be required for air to reach the user. 

These values match up to the desired range of wind speeds and relate to the speed of the outside wind linearly. In the code pwm code for the fans these values will be used as the basis for the speed of the fans, as the tachometer sends values the speed will be read, then the fan will change to the appropriate RPM value.

### Meeting the minimum RPM Constraint.

When calculating to rpms needed to create certain wind speeds with the fan, it is important to take into account how much air the fan will push, and if the amount of air will be sufficient when the fan runs at very low RPMS. The fans will be positioned apporiximately 1 meter away from the user, for the purpose of this project, we will assume that the minimum area that the fan will need to be able to blow air is a cubic meter. This translate to 35.3147 square feet of space. When it comes to CFM and RPM for fans, they are directly proportional[8]. This means for a 10% increase in rpm there will be an equivalent 10% increase in cfm. The max rpm of the CFM-A225BF-158-597-22 is 5800, and the max cfm is 185.5. This means that for every 1 CFM, there is an equivalent 31.266 RPM. If we take the 35.3147 Cubic feet value that was decided earlier, and translate that to an equivalent RPM value we get 35.3147 x 31.266 = 1,104.149 RPM. This is the hypothetical value based on calculations that the minimum fan speed needs to be to push air in a cubic meter of space, and this is ignoring any outside factors of static pressure or air flow. 

The minimum value that the fan will output is 1105 rpm, this will allow the user to feel the air even at the lower speeds where the calculated fan speed would initially not have been able to push enough air to reach the user. This is in line with the minimum constraint.
 
### Meeting the Fan Control Constraint

To create an immersive riding experience for the user, it is important that the fans are controllable and able to change their output based on the speed that the user is traveling. The CFM-A225BF-158-597-22 is PWM controllable meaning that it can be hooked up the PWM output of the Raspberry pi and its speed can be programmed using pulse width modulation. The speed of the user will be taken from the tachometer and sent to the Rpi and a code will be ran to use that speed data and convert it to a proportional output for the fan. As the speed data that is sent gets changed, a change in the speed of the fans will be noticeable as well. 


### Meeting Off Button Constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be programmed into the fan code that will allow the user to shut the subsytem off. This will keep the fans from outputting until the user decides that they want to turn it back on. 

### Meeting Output Noise Level Constraint

While the OSHA standard limit for noise level is under 85 dB for 8 hours, that is not the only constraint that should be taken into account when using fans. For this susbsystem, the fans should be fast enough to properly provide air to the user, but not be so loud as to cause discomfort. Around 60 dB is the sound level of a normal conversation and past this noises start to be considered loud and potentially annoying. With this is mind, the constraint of 60 dB has been set for the fans maximum sound output. At this noise level, the fans will be very noticeable and easily heard but not at the level that should cause pain or discomfort to individuals.

According to the datasheet of the fan CFM-A225BF-158-597-22, it has a rated noise level 59.7 dBA. This value is less than 60 dBA meaning this fan will be sufficient in fulfilling this constraint.

### Meeting power constraint

<!-- In the previous renditions of this project, the groups created a power distribution system to power their componenets. The same method of powering will be used for the fans. The fans will be connected to the already installed raspberry pi which will deliver the necessary power. The raspberry pi being used is the Model 3 B+. The recommended amperage limit for the pi is 2.5 amps. The CFM-A225BF-158-597-22 is rated to operate at 5 VDC and an input current of 0.57 A. This equates to a total power draw of 2.85 Watts. The power distribution system is comprised of multiple DIN rail power supplies, each of which is capable of delivering 35 watts of power or more. Since two fans will be used for this subsystem, a total power of 6.648 W will be needed. This is within the capabilities of the previously built power system meaning the fans will be delivered their full power and be able to operate within their full range. -->

When it comes to the goal of this subsystem, it is important that the fans are powerful enough to push winds towards the user that provides ample force that is at least partially indicative of a physical trail riding experience. When considering the 5V fan options available on the market, they are not powerful enough or provide enough cfm to produce much wind force without being within a very close proximity to the user. With this in mind, 12V options had to be taken into account with the goal of a successful immersion system in mind. The Rpi is only capable of powering up to 5V fans, so an external power supply will need to be utilized in order to provide ample power to the fans and let them operate at their full range. The fans will be connected to the PWM GPIO of the raspberry pi and powered by an external source. 

The CFM-A225BF-158-597-22 fan is a 12V fan that is rated to have a current draw of 2.4 Amps equalling out to a power draw of 28.8 Watts. With there being two fans that measn the total power draw will be 57.6 amps. With this in mind, a 12V 5A 60W power supply has been chosen to power the fans. It comes with a female DC connector piece that will allow a connection to fans. 


The CFM-A225BF-158-597-22 has 4 connections wires: +Vin, -Vin, and Tach signal, and PWM signal. The fan speed will be controlled via the PWM0 port GPIO12 on the raspberry pi. The fans will be connected to the external 60W power supply.

## Buildable Schematic

<img width="1071" alt="Screen Shot 2024-02-21 at 5 25 00 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/7babd72f-9b61-4bef-8532-6b27e42302d5">

Figure 2. Circuit Schematic for Fan Connection to Raspberry pi

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|DC Brushless Fan|CFM-A225BF-158-597-22|CUI Devices|2|$35.85|$71.7|
|DC 12V 5A 60W Power Supply||Arybroourd|1|$10.87|$10.87|
|Total|||Total Components|2|Total Cost|$82.57|


## References:

[1]“Decibels dBA,” Decibels dba, https://silentpc.com/articles/decibels (accessed Feb. 11, 2024). 

[2] “CFM-120BF series datasheet - axial fans - cui devices,” SERIES: CFM-120BF | DESCRIPTION: DC AXIAL FAN, https://www.cuidevices.com/product/resource/cfm-a225bf-153-577.pdf (accessed Feb. 12, 2024). 

[3] “Average cycling speed for new and experienced cyclists,” Road Bike, https://www.road-bike.co.uk/articles/average-speed.php (accessed Feb. 12, 2024). 

[4] T. N. Crouch, D. Burton, Z. A. LaBry, and K. B. Blair, “Riding against the wind: A review of Competition Cycling Aerodynamics - Sports Engineering,” SpringerLink, https://link.springer.com/article/10.1007/s12283-017-0234-1 (accessed Feb. 18, 2024). 

[5] J. Quinones, “4 ways to calculate wind load,” wikiHow, https://www.wikihow.com/Calculate-Wind-Load (accessed Feb. 18, 2024). 

[6] "DC 12 Volt 5 Amp Power Supply - 60W https://www.amazon.com/Supply-Adapter-100-235V-50-60Hz-Connector/dp/B0BJVVBBMJ/ref=sr_1_13?dib=eyJ2IjoiMSJ9.NdG7lJz6NP5jClxT5_rsJeQSFy8O-Y6IaMFn27sm2Z4cLQhvVEscFhQnC2mLwLUsDTp_Tp-l4s3a2YvgOkhYmOqKQ92SUN4Ejnzad3hOzjNh8WQbPqMc4Fi0BagE8GBtlVnZGsVvKqBcf-Yr6MFRcgk4K30FVhDx2EkWVvXvu61DxzJOVGKHNvISYF9RS7eoe1p441zVA-CikZmCjmOlg6gg76B8YZ7t_L_20GJ19rM.h_7I5SjaCUJVQSA-XJtS8eEyX-OEekI9otaB_Z9rtnc&dib_tag=se&keywords=12v+5a+power+supply&qid=1708556650&sr=8-13

[7] “Fan wind speed calculator,” Calculator Academy, https://calculator.academy/fan-wind-speed-calculator/ (accessed Feb. 22, 2024). 

[8] E. Gutowski, “The 3 fan laws and fan curve charts,” HVAC School, https://hvacrschool.com/the-3-fan-laws-and-fan-curve-charts/ (accessed Feb. 23, 2024). 

[9] M. A. Instructor, “Calculating CFM or velocity across a coil or in ductwork,” MEP Academy, https://mepacademy.com/calculating-cfm-or-velocity-across-a-coil-or-in-ductwork/# (accessed Feb. 23, 2024). 
