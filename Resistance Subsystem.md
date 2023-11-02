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

![SolidWorks design of Resistance system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/HolderSide.png)

Figure 3. Side View of Housing for Resistance System

![Work system housing with lid](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/WorkLid.png)

Figure 4. Design of Housing for work system with lid

![Holder for magnet front](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/WorkBox.png)

Figure 5. Side View

![Holder for magnet back](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Work_Circuit_Design.png)

Figure 6. Work Circuit desing



## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Hall Effect Sensor|Hall Effect Sensor Single Axis TO-92-3|DRV5056A2ELPGMQ1|Texas Instruments|2|$2.01|$4.02|
|Wireless Bluetooth Serial Transceiver|HC-06 Wireless Bluetooth Serial Transceiver Support Module Slave and Master Mode for Arduino + 4PIN Dupont Cable|SH-HC-06|DSD Tech|1|$9.99|$9.99|
|Arduino Nano|Arduino Nano|ABX00028|Arduino|2|$13.70|$13.70|
|Power bank|5V 2A Pocket Size Thin 5000mAh Portable USB Charger|B081747GM9|Vida IT|1|$22.99|$22.99|
|Perfboard|1" x 2" Perfboard|ST-PERF-1-2|SchmalzTech, LLC|2|$1.95|$3.90|
|Magnet|Nickel-Plated N52 Magnet|DX44-N52|K&J Magnetics|1|$11.57|$11.57|
|Acrylic Sealant (For waterproofing enclosure)|Clear Electronic Grade Silicone - 2.8 oz Squeeze Tube|ASI 388|American Sealants Inc.|1|$11.95|$11.95|
|Conformal Coating (for waterproofing PCB)|CONFORMAL COATING UL 94V-0|419D-55ML|MG Chemicals|1|$16.76|$16.76|

## References:

[1]”DRV5056-Q1 Automotive Unipolar Ratiometric Linear Hall Effect Sensor,” https://www.ti.com/lit/ds/symlink/drv5056-q1.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1698173863097&ref_url=https%253A%252F%252Fwww.ti.com%252Fgeneral%252Fdocs%252Fsuppproductinfo.tsp%253FdistId%253D10%2526gotoUrl%253Dhttps%253A%252F%252Fwww.ti.com%252Flit%252Fgpn%252Fdrv5056-q1 (accessed Oct. 25th, 2023)

[2]”How do you calculate the magnetic flux density?” https://www.supermagnete.de/eng/faq/How-do-you-calculate-the-magnetic-flux-density (accessed Oct. 25th, 2023)

[3]"BMX Bike Sizing,”  https://rampfest.com.au/pages/bmx-bike-sizing. (accessed Oct. 25th, 2023)

[4]"Bike Tire Sizes Guide," Sweet Pete's. Available: https://www.sweetpetes.com/articles/bike-tire-sizes-guide-pg564.htm. (accessed Oct. 25th, 2023)

[5]E. Jack, Fastest cyclist ever: Setting a World Record speed of 183mph on a bicycle, Cyclist, 2019. https://www.cyclist.co.uk/news/fastest-cyclist-ever-setting-a-world-record-speed-of-183mph-on-a-bicycle

[6]V. David, A Quick Guide to Understand IPC-CC-830B Qualification Standard, HumiSeal, 2018. https://blog.humiseal.com/a-quick-guide-to-understand-ipc-cc-830b-qualification-standard


