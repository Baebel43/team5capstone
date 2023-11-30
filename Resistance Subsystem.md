Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Resistance System
The resistance subsystem controls the linear actuator during a virtual trail. Team 5 will incorporate the previous iteration of this project's resistance system with the intent of changing the existing open loop system into a closed loop feedback system. 

## Subsystem Functionality

The resistance subsystem will take a force input from the user on the exercise bike, compare it to the current resistance value, and make the appropriate change to the resistance value to keep the work done during the ride replay constant. This will be done using a force sensor which will feedback information via a bluetooth transmitter to the Raspberry Pi that holds the work map. The actual work done will be compared to the value on the work map via code and the actuator distance will be adjusted accordingly. 

There will be two graphs. Force from the pedals and distance, both in respect to time. Work is force multiplied by distance. The result will will be the current work graph. The derivative of the current work graph in respect to time is the change in work. This change in work is directly related to the change in distance for the linear actuator. The relationship will be exponential, as magnets are nowhere near linear. All of this will be done in the Arduino.


## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Distance of the actuator | The closest the magnets may reach the flywheel is 2 mm. The furthest the magnet may be from the flywheel is 20 mm.|
|Feedback Accuracy | The feedback must ensure the work done is equal to the current value on the work map.|
|Force Minimum and Maximum | The minimum force value needs to be as low as possible to provide maximum sensitivity for the user. The maximum force value is set by the force sensor at 7000 lbs. |
|Actuator Duty Cycle | The duty cycle of the linear actuator will be set at 25%. 
|Stability| The resistance system must operate without becoming unstable.
|Housing Security | Resistance system must not fall of the pedal during operation.




## Analysis

### Meeting Distance of the Actuator Constraint

This constraint is an inherited constraint from the previous capstone group. This was set for the safety of the system, as well as to match the calculated torque values. The closest distance is set at 2 mm, while the maximum mechanical distance is fixed at 20 mm. 

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



### Meeting Force Minimum and Maximum Constraint

The minimum force will be set as low as possible. According to the datasheet, the higher the feedback resistor, the more sensitive the force sensor will be (seen in Figure 1). Team 5 will calibrate the sensor to provide the most sensitive force possible. 

Using the equation from the last iteration of the project[1]:

$Td = 𝛑 𝛔 4 D^2 d B^2 R^2 θ$


Where,

Td=Torque (Nm)

σ = Conductivity of flywheel material  (Ω−1m−1)

D = magnet diameter (meters)

d = disc (flywheel) thickness (meters)

B = magnet field strength (Tesla)

R = dist from flywheel center to magnet (m) 

θ = angular velocity (rads/s)

The maximum force will be set to 121.8499.

![SolidWorks design of work system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/WorkChart.png)

Figure 1. Force Sensor Datasheet

### Meeting Actuator Duty Cycle Constraint
This is an inheretted constraint from the past team. The Arduino contains a function to programmabley limit the duty cycle. This will be utlized to set the maximum PWM cycle to fulfill this constraint.

### Meeting Stability Constraint
The Arduino can be programmed as a PID controller. The PID constants given by the manufacturer are as follows:

$Kp = 1.80$

$Ki = 0.0900$

$Kd = 2.50$

Using these values, a stable feedback loop system can logically be achieved. 

## Meeting Housing Security Constraint
Velcro straps will be used to secure the resistance system force sensor circuit to the pedals. Two straps placed parallel to the bike should be suffiecient to keep the housing in place, also taking into account the weight of the user's foot keeping the straps in place. The option for a third strap placed perpendicular to the bike will be kept in mind, just in case two is not sufficient after testing.

## Buildable Schematics

The housings for each of the two force sensor circuits will be placed below each pedal. The force sensors will be mounted to the top of each pedal, with wires running to the housings below. The bluetooth transmitter will then send the signal to the Raspberry Pi with the work map.

![SolidWorks design of Resistance system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/PedalBox.png)

Figure 2. Corner View of Housing for Resistance System

![Work system housing with lid](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/PedalLid.png)

Figure 3. Design of Housing for Work System with Lid

![Housing on Bike 1](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/ResistanceSystemOnBikeSideView.png)

Figure 4. Housing on Bike Side View

![Housing on Bike 2](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/ResistanceSystemOnBikeTopView.png)

Figure 5. Housing on Bike Top View

![Housing on Bike Corner View](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/ResistanceSystemOnBikeCornerView.png)

Figure 6. Housing on Bike Corner View

![Holder for magnet back](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ResistanceSystemImages/ResistanceSystemCircuitDesign.png)

Figure 7. Force Sensor Circuit Design



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
|Total|||Total Components|10|Total Cost|$119.00|

## References:
[1]”Spring2023-Mario-Kart-BikeV2 Resistance System,”
﻿​﻿​﻿​​​﻿﻿[Spring2023-Mario-Kart-BikeV2/Documentation/Signoffs/ResistanceSystem.md at main · TnTech-ECE/Spring2023-Mario-Kart-BikeV2 (github.com)](https://github.com/TnTech-ECE/Spring2023-Mario-Kart-BikeV2/blob/main/Documentation/Signoffs/ResistanceSystem.md)https://github.com/TnTech-ECE/Spring2023-Mario-Kart-BikeV2/blob/main/Documentation/Signoffs/ResistanceSystem.md


