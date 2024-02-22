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


### Explanation of Subsystem and Choices

The immersion subsystem is an addition to the Ride Replay System that will attempt to use fans to simulate the feeling of moving through, accelerating, and decelerating through the wind. To do this, a number of methods, assumptions, and research had to be utilized.

When it comes to wind speed and fan rpm, there is not a linear relationship. Factors such as fan CFM and static pressure are among many things that affect how the wind flows and how much RPM is needed for a fan to output a certain speed of wind. As a person is riding on a physical bike trail, the force of wind starts to become stronger as they approach higher speeds. Due to the forces of drag and resistance on an object, the relationship between the force of wind and the speed of an object is exponential. This means that the force of felt per mph increase at 20 mph is going to be much higher than ever mph increase at 5 mph. With this in mind, to make the output of the fans simulate the feeling of traveling through the wind as accurately as possible, they need to try and match the force of the wind the user would experience, rather than just the speed. 

When looking at fan specifications, the main factors for output to look at are RPM and CFM. Where CFM is the volume of air that the fan circulates in a minute. Unfortunately, there is not a simple conversion between the CFM of a fan and the speed of the air it blows. To get an accurate speed in mph of the wind that a fan will blow, the fan would either have to be blowing into a duct with a know cross sectional area, or an anemometer would need to be utilized which can measure the speed of wind. For the scope of this project, the fans will be blowing in an open space towards the user. Without having a duct that travels directly from the fan to the user, or having the fans physically on hand to test them with a device it is impossible to accurately know the speed of the wind they are outputting. Therefore,  a method must be utilized that allows a rational connection between the users speed and the cfm/rpm of the fan. The steps in which this connection was made will be outlined now. 

To find the force of the wind load that the user would experience on a physical trail, the formula for wind load was used where the load takes into account wind pressure, object surface area, and the drag coefficient of an object. Wind pressure is found by taking the value for air density and multiplying it by velocity squared. This means that as velocity increases the pressure will exponentially increase. This formula for wind load was applied to every mph value within the minimum to maximum range chosen of 0-35 mph.

These force values ranged from 0.002 all the way to 2.5, as seen from the table of values there is an exponential increase in the force value as the mph speed gets higher. To connect this exponential curve of force vs speed and match the rpm/cfm of the fans to it. The max rpm value of the fan was taken (5800) and was multiplied by each force value that was calculated. This gives a range of rpm values that are proportional to the exponential curve of force that the user experiences. These values ranged from 12 rpm all the way 14500 rpm which of course is outside the capabilities of the fan, so to get it within a range that the fan could handle the values needed to be scaled down. By taking 5800/14500 we find that it is 40% of the proportional value. So, taking each proportional rpm value and multiplying it by .4, we get a scaled range of values that match the force curve that was calculated and is within range of the fans capabilities. 

The same thing can be said with the cfm of the fan. CFM and RPM of a fan are directly proportional so for the 5800 rpm 185.5 CFM fans, it can be reasonably inferred that for every 1 CFM there is an equivalent 31.26 rpm. This allows us to convert all the values of rpm that were scaled to CFM values to get an accurate idea of the volume of air being pushed at each mph that the user is traveling. Putting these values against the speed range also yields a similar curve to the force curve. It is unclear how fast the wind will be at these different CFM values so an inference must be made that the 185.5 CFM is sufficient in pushing air towards the user. This assumption is made based on data on how other CFM fans are generally used, with 50-70 CFM fans being used for PC case fans and 150-250 CFM fans being used for things like racing simulators and other things. 

Given the process that was followed, it is reasonable to believe that the exponential curve that the RPM of the fans will follow will be at least partially indicative of the increase in wind force and speed that a user would experience while riding on a physical outdoor trail.



### Meeting the RPM Mapping Constraint

The speed from the previously installed speed sensor system will be used as the comparison data to decide on the fans speed. The speed data will be taken then converted into a voltage value proportionally. This voltage value is the amount that will be sent to the fan at a given time. As the fan is driven at different voltages the RPM will either increase or decrease 

Although the max speed one can achieve on a bike is above 100 mph, the average speed that a user will ride is anywhere between 10 for inexperienced riders up to 24 mph for more experienced riders [3]. This speed can reach upwards of 30 and 40 when the user is on an incline. With this in mind, the max speed of the fans will be proportionaly connected to a max speed of 35 mph on the bike. In a real bike riding environment, as the riders speed increases their aerodynamic drag increases as well. This means that at higher speeds the force of the wind will become stronger as the riders body causes more resistance. This means that the relationship between the speed of the user and the force of the wind is not linear and will increase at a faster rate at higher speeds. 

When it comes to choosing a fan for the immersion subsystem, it is important that the fan has a high enough CFM (Cubic Feet per Minute) value. CFM is the measurement of the volume of air that a fan is capable of moving. In order to convert CFM to a speed value you would have to know the measurements of the room and the static pressure within it. For the scope of this project, the goal is not to circulate air in the room but to push air from the fans on to the face of the user. It is impossible to precisely calculate the speed and the force that a fan will produce in an open space without being able to physically test it. So, for the sake of simplicity, a fan with a comparatively high CFM will be chosen and if the max power and speed ends up being too high then the maximum RPM of the fan will be limited. A PC cooling fan will have on average between 50-80 CFM depending on the quality and the size. This value needs to be marginally higher in order for the wind from the fans to reach the user and provide any sort of noticeable force. Therefore, the CFM-A225BF-158-597-22 has been chosen with a CFM value of 185.5. Extra testing will need to be done in regards to the distance of the positioning of the fans and their max power output, but this value should be adequate in pushing enough air towards the user to provide an immersive experience through changing speeds.

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

**$$\ Proportional_{RPM}(P_{RPM}) = Max_{RPM} * Force of Wind)$$**

**$$\ Scaled_{RPM}(S_{RPM}) = P_{RPM} * .39868$$**

**$$\ Proportional_{CFM}(P_{CFM}) = S_{RPM}/31.26$$**

The first formula takes the max rpm of the CFM-A225BF-158-597-22 fan[2], which is 5800, and multiplies it by the calculated forces from figure 1. By doing this a set of values is created that relates to rpm. Once this rpm is calculated, it now has to be scaled down to fit the parameters and capabilities of the fan. The max value calculated from the previous calculation is 14547.85382, if the max rpm of the fan is taken and divided by this max proportional value, we find that it is 39.868% of the proportional value. Using the second formula, if we multiply each of the P_RPM values that were calculated by this 39.868% value, we can scale all the values of rpm down to within the necessary range. For the third formula, the values of the fans CFM were mapped to the rpm values to create a proportion between the two. The CFM and rpm of a fan are said to be directly proportional, so as the fan speed increases there is a linear increase in CFM. By dividing the max rpm of the CFM-A225BF-158-597-22, which is 5800, by the CFM, which is 185.5, it is found that for CFM increase of 1 there is a proportional increase of 31.2668 rpm in the fan. By dividing each of the scaled RPM values by 31.2668 we can approximate what it translates too in CFM values. 

<img width="341" alt="Screen Shot 2024-02-19 at 9 35 53 AM" src="https://github.com/Baebel43/team5capstone/assets/123997954/eb7a36d5-14fd-4f7f-b964-a52ccadd34c4">

Figure 3. Table of Conversions to scaled RPM and CFM

The main values that will be used are the scaled RPM values when driving the fans. 


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

<img width="1071" alt="Screen Shot 2024-02-21 at 5 25 00 PM" src="https://github.com/Baebel43/team5capstone/assets/123997954/d1933595-0775-4899-acdc-7b06734e968f">


Figure 1. Circuit Schematic for Fan Connection to Raspberry pi

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

[6] "DC 12 Volt 5 Amp Power Supply - 60W https://www.amazon.com/Supply-Adapter-100-240V-50-60Hz-Connector/dp/B0BJVVBBMJ/ref=sr_1_13?dib=eyJ2IjoiMSJ9.NdG7lJz6NP5jClxT5_rsJeQSFy8O-Y6IaMFn27sm2Z4cLQhvVEscFhQnC2mLwLUsDTp_Tp-l4s3a2YvgOkhYmOqKQ92SUN4Ejnzad3hOzjNh8WQbPqMc4Fi0BagE8GBtlVnZGsVvKqBcf-Yr6MFRcgk4K30FVhDx2EkWVvXvu61DxzJOVGKHNvISYF9RS7eoe1p441zVA-CikZmCjmOlg6gg76B8YZ7t_L_20GJ19rM.h_7I5SjaCUJVQSA-XJtS8eEyX-OEekI9otaB_Z9rtnc&dib_tag=se&keywords=12v+5a+power+supply&qid=1708556650&sr=8-13
