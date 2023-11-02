Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Resistance System
The resistance subsystem controls the linear actuator during a virtual trail. 

## Subsystem Functionality

The resistance subsystem will take a force input from the user on the exercise bike, compare it to the current resistance value, and make the appropriate change to the resistance value to keep the work done during the ride replay constant. This will be done using a force sensor which will send information to the Raspberry Pi that holds the work map. The actual work done will be compared to the value on the work map and adjusted accordingly. 


## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Distance of the actuator | The closest the magnets may reach the flywheel is 2 mm.|
|Feedback | The feedback must ensure the work done is equal to the current value on the work map.|
|Force Minimum and Maximum Constraint | The minimum force value needs to be as low as possible to provide maximum sensitivity for the user. The maximum force value is set by the force sensor at 7000 lbs. |



## Analysis

### Meeting Distance of the Actuator

This constraint is an inherited constraint from the previous capstone group. This was set for the safety of the system, as well as to match the calculated torque values.

### Meeting Feedback Constraint

The force sensor provides a force value to compare to the work map. This value is in lbs of force. This can be converted to J/m as shown below. The work map is in Joules per meter. If the user contributes less force than is needed according to the work map, the actuator will close the distance, thereby increasing the resistance, appropriately. On the other hand, if the user contributes more force than needed according to the work map, the actuator will retract, thereby lowering the resistance, appropriately. This way, the overall work done remains the same.

1 pound-Force = 4.4482 J/m

1 J/m = 1 N

W = F*d

Where,

J = Joules

m = meters

N = Newtons

W = work (in Joules)

F = Force (in Newtons)

d = distance (in meters)


![SolidWorks design of work system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Work%20Chart.png)


### Meeting Force Minimum and Maximum Constraint

The minimum force will be set as low as possible. According to the datasheet, the higher the feedback resistor, the more sensitive the force sensor will be. Team 5 will calibrate the sensor to provide the most sensitive force possible. The maximum force will be set to 121.8499


## Buildable Schematics

![SolidWorks design of Resistance system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/WorkBox.png)

Figure 3. Side View of Housing for Resistance System

![Work system housing with lid](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/WorkLid.png)

Figure 4. Design of Housing for work system with lid

![Holder for magnet back](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Work_Circuit_Design.png)

Figure 6. Work Circuit desing



## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Force Sensor|Force Sensing Resistor Force Sensor 3175.15kgf (7000 lbs)|A401-25|Tekscan|3|$26.30|$78.90|
|Opamp|General Purpose Amplifier 4 Circuit Rail-to-Rail 14-PDIP|MCP6004-I/P|Microchip Technology|2|$0.59|$1.08|
|100 kΩ potentiometer|100 kOhms 0.5W, 1/2W PC Pins Through Hole Trimmer Potentiometer Cermet 1.0 Turn Top Adjustment|3386P-1-104LF|Bourns Inc.|1|$1.61|$1.61|
|Battery Holder|Battery Holder (Open) AA 3 Cell Wire Leads - 6" (152.4mm)|BC3AAW|MPD|1|$2.33|$2.33|
|47 pF capacitor|47 pF Mica Capacitor 500 V Radial|CD15ED470JO3|Cornell Dubilier Electronics (CDE)|1|$1.73|$1.73|
|Perfboard|Breadboard, General Purpose Plated Through Hole (PTH) Pad Per Hole (Round) 0.1" (2.54mm) Grid|ST-PERF-1-2|SchmalzTech, LLC|1|$1.95|$1.95|
|Arduino Nano 33 BLE|Arduino Nano 33 Bluetooth Low Energy Microcontroller|ABX00030 |Arduino|1|$26.30|$26.30|
|Total|||9|Total Cost|$119|

## References:


