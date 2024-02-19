![image](https://github.com/Baebel43/team5capstone/assets/123997954/6fae5de0-1d6b-493e-b84c-37253d8e2705)
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
|RPM Mapping| The rpm of the fans will be mapped to the virtual speed that the user is traveling|
|Fan Control| The speed of the fans will be adjustable and adaptable|
|Output Noise Level| The fans will have a max noise level output of 60 dBA|
|Power|Each of the fans will be supplied a minimum of 28.80 watts of power|


## Analysis

### Meeting the RPM Mapping Constraint

The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

Although the max speed one can achieve on a bike is above 100 mph, the average speed that a user will ride is anywhere between 10 for inexperienced riders up to 24 mph for more experienced riders [3]. This speed can reach upwards of 30 and 40 when the user is on an incline. With this in mind, the max speed of the fans will be proportionaly connected to a max speed of 35 mph on the bike. In a real bike riding environment, as the riders speed increases their aerodynamic drag increases as well. This means that at higher speeds the force of the wind will become stronger as the riders body causes more resistance. This means that the relationship between the speed of the user and the force of the wind is not linear and will increase at a faster rate at higher speeds. 

To get an accurate estimate of the wind load that a user would feel at different speeds, we can use the formual F = A x P x Cd , where A is the area of the object, P is the wind pressure, and Cd is the drag coefficient. 
Due to the scope of this project being an indoor environment with a virtual riding experience performed by many different types of users, the area is going to remain a constant value of 1 and will not affect the calculated value of the wind load. The simple formula for wind pressure is P = 0.00256V^2, where V is the velocity/speed that the user is traveling[5]. The drag coefficient is important in knowing how much aerodynamic drag the object has and how much resistance it has towards the wind. For a rider in a upright position, the drag coefficient is generally greater than 0.8 [4], so for this calculation a drag coefficient of 0.8 will be used. With these values the force of wind at different speeds can be approximated. 

Using the formula:

**$$\ F = P * C_d = 0.00256V^2 * C_d$$**

A table can be created that finds the force of at multiple different speeds.

<img width="149" alt="Screen Shot 2024-02-18 at 11 30 17 AM" src="https://github.com/Baebel43/team5capstone/assets/123997954/c526346f-c06f-4bfd-8359-f35cf529565d">

Figure 1. Table of Force of wind vs Speed

Using this data, a graph can be created that allows us to see the curve between the speed and force.

<img width="668" alt="Screen Shot 2024-02-18 at 11 32 40 AM" src="https://github.com/Baebel43/team5capstone/assets/123997954/3c0d1cfa-f2d9-4543-b055-e031c068c50e">

Figure 2. Graph of Force of wind vs speed/velocity

As shown in the graph of figure 2, there is an exponential relationship between the speed of the object and the force of wind that is acting upon it. To get the most accurate proportion between the force of wind felt by the user and the speed that the fans are outputting, the fan rpm should be set to have a similarly shaped curve. It is not feasible to have the fans simulate the exact force that user would experience out on a phsycial trail, so for the purpose of this project the values will be significantly scaled down. To create a proportion between the fan rpm and the user speed, the following formulas were used:

**$$\ Proportional_RPM(P_RPM) = Max_RPM * F(of wind)$$**

**$$\ Scaled_RPM(S_RPM) = P_RPM * .39868$$**

**$$\ Proportional_CFM(P_CFM) = S_RPM/31.26$$**

The first formula takes the max rpm of the CFM-A225BF-158-597-22 fan[2], which is 5800, and multiplies it by the calculated forces from figure 1. By doing this a set of values is created that relates to rpm. Once this rpm is calculated, it now has to be scaled down to fit the parameters and capabilities of the fan. The max value calculated from the previous calculation is 14547.85382, if the max rpm of the fan is taken and divided by this max proportional value, we find that it is 39.868% of the proportional value. Using the second formula, if we multiply each of the P_RPM values that were calculated by this 39.868% value, we can scale all the values of rpm down to within the necessary range. For the third formula, the values of the fans CFM were mapped to the rpm values to create a proportion between the two. The CFM and rpm of a fan are said to be directly proportional, so as the fan speed increases there is a linear increase in CFM. By dividing the max rpm of the CFM-A225BF-158-597-22, which is 5800, by the CFM, which is 185.5, it is found that for CFM increase of 1 there is a proportional increase of 31.2668 rpm in the fan. By dividing each of the scaled RPM values by 31.2668 we can approximate what it translates too in CFM values. 

<img width="342" alt="Screen Shot 2024-02-19 at 9 15 58 AM" src="https://github.com/Baebel43/team5capstone/assets/123997954/171128ae-8ac2-4f33-84b3-ab8a14b1b698">

Figure 3. Table of Conversions to scaled RPM and CFM

The main values that will be used are the scaled RPM values when driving the fans. 


### Meeting the Fan Control Constraint

To create an immersive riding experience for the user, it is important that the fans are controllable and able to change their output based on the speed that the user is traveling. The CFM-A225BF-158-597-22 is PWM controllable meaning that it can be hooked up the PWM output of the Raspberry pi and its speed can be programmed using pulse width modulation. The speed of the user will be taken from the tachometer and sent to the Rpi and a code will be ran to use that speed data and convert it to a proportional output for the fan. As the speed data that is sent gets changed, a change in the speed of the fans will be noticeable as well. 


### Meeting Off Button Constraint

In the case that the user does not want to make use of the immersion subsystem, an off switch will be programmed into the fan code that will allow the user to shut the subsytem off. This will keep the fans from outputting until the user decides that they want to turn it back on. 

### Meeting Output Noise Level Constraint

While the OSHA standard limit for noise level is under 85 dB for 8 hours, that is not the only constraint that should be taken into account when using fans. For this susbsystem, the fans should be fast enough to properly provide air to the user, but not be so loud as to cause discomfort. Around 60 dB is the sound level of a normal conversation and past this noises start to be considered loud and potentially annoying. With this is mind, the constraint of 60 dB has been set for the fans maximum sound output. At this noise level, the fans will be very noticeable and easily heard but not at the level that should cause pain or discomfort to individuals.

According to the datasheet of the fan CFM-A225BF-158-597-22, it has a rated noise level 59.7 dBA. This value is less than 60 dBA meaning this fan will be sufficient in fulfilling this constraint.

### Meeting power constraint (NEEDS WORD)

In the previous renditions of this project, the groups created a power distribution system to power their componenets. The same method of powering will be used for the fans. The fans will be connected to the already installed raspberry pi which will deliver the necessary power. The raspberry pi being used is the Model 3 B+. The recommended amperage limit for the pi is 2.5 amps. The CFM-A225BF-158-597-22 is rated to operate at 5 VDC and an input current of 0.57 A. This equates to a total power draw of 2.85 Watts. The power distribution system is comprised of multiple DIN rail power supplies, each of which is capable of delivering 45 watts of power or more. Since two fans will be used for this subsystem, a total power of 6.648 W will be needed. This is within the capabilities of the previously built power system meaning the fans will be delivered their full power and be able to operate within their full range. 

The CFM-A225BF-158-597-22 has 4 connections wires: +Vin, -Vin, and Tach signal, and PWM signal. The fan speed will be controlled via the PWM0 port GPIO12 on the raspberry pi. The fans will be connected to the 5v output of the pi. 

## Buildable Schematic

<img width="1000" alt="Screen Shot 2024-02-15 at 10 39 19 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/7e58c7a9-f88b-40d5-8dff-38b98e18d966">

Figure 1. Circuit Schematic for Fan Connection to Raspberry pi

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|DC Brushless Fan|CFM-A225BF-158-597-22|CUI Devices|2|$71.7|$|
|Total|||Total Components|2|Total Cost|$71.70|


## References:

[1]“Decibels dBA,” Decibels dba, https://silentpc.com/articles/decibels (accessed Feb. 11, 2024). 

[2] “CFM-120BF series datasheet - axial fans - cui devices,” SERIES: CFM-120BF | DESCRIPTION: DC AXIAL FAN, https://www.cuidevices.com/product/resource/cfm-a225bf-153-577.pdf (accessed Feb. 12, 2024). 

[3] “Average cycling speed for new and experienced cyclists,” Road Bike, https://www.road-bike.co.uk/articles/average-speed.php (accessed Feb. 12, 2024). 

[4] T. N. Crouch, D. Burton, Z. A. LaBry, and K. B. Blair, “Riding against the wind: A review of Competition Cycling Aerodynamics - Sports Engineering,” SpringerLink, https://link.springer.com/article/10.1007/s12283-017-0234-1 (accessed Feb. 18, 2024). 

[5] J. Quinones, “4 ways to calculate wind load,” wikiHow, https://www.wikihow.com/Calculate-Wind-Load (accessed Feb. 18, 2024). 
