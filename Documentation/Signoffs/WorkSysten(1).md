Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Work System

## Subsystem Functionality

The work subsystem uses the weight of the user, the velocity of the bike, and the elevation of the trail in order to create a work map for that trail to be replayed on the exercise bike. This work map will be altered based on the difficulty level the user selects in the user interface subsystem. A Hall effect sensor will be used to count the number of revolutions of the wheel to calculate the distance for use in the total work calculation of the trail. An altitude sensor will be used to detect the change in height throughout the trail and is used in the work calculation. The weight of the user will be converted to kg to be used in the work calculation. 

## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Distance between box attached to the bike frame and the spoke | The measured minimum distance between the bike spoke and frame was found to be 30 mm meaning that the device will be no larger than 20 mm between the spoke and the frame.|
|Magnetic Sensor Range | The magnetic sensor can be no more than 23.75 mm away from the magnet.|
|Diameter of the Wheel | The device must support the minimum wheel size of 50.8 cm in diameter.|
|Sensing Speed (Minimum and Maximum Velocity) | The maximum velocity the sensor will be able to detect is 190 miles per hour.|
|Waterproof | The kit shall have the ability to be fully submerged in water.|
|Ride Time | The user will be able to use the kit concurrently for 24 consecutive hours.|


## Analysis

### Meeting distance constraint

The average distance between the frame and the spoke of a mountain bike is between 30 mm and 35 mm.


### Meeting Magnetic Sensor Range Constraint

The Hall effect sensor has a voltage draw of 3.3 V to 5 V that produces a magnetic flux density of 39 mT, equivalent to 390 Gauss [1]. Based on these specifications there must be a magnet opposite of the sensor capable of producing a magnetic flux density of at least 390 Gauss to trigger the sensor. By using a 1 ¼” diameter by ¼” thickness nickel-based magnet it will produce 456 Gauss at a distance of 22 mm. The distance of 22 mm is found to be the largest possible distance between the magnet and the sensor. The space between the bike spoke and the frame is 30 mm, minus the thickness of the magnet (6.35 mm) and the thickness of the sensor (2.06 mm) which equals 21.59 mm which is then rounded to 22 mm to ensure that it will reach a slightly above 21 mm.

- The residual induction for the magnet chosen is 14,800 gauss. The thickness of the magnet is 0.25 inches or 6.35 millimeters. The radius of the magnet is 0.625 inches or 15.875 millimeters. The maximum distance from the magnet and sensor we calculated was rounded to 22 mm. Using the following formulas we can solve for gauss at maximum distance to prove that it is above the 390 gauss required by the sensor.
**1 Tesla = 10,000 Gauss**

  ![Magnetic Flux Calculation](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Magentic%20Flux%20Calculation%20Equation.png)

- Plugging in all the values: Br is 14800, D is 6.35, R is 15.875, and z is 22 mm we get  455.8 gauss which is well above the required value for the sensor.

The Hall effect sensor has a quiescent voltage between 0.535 V and 0.665 V [1]. This is used for the range of the linear output voltage which has a minimum of the quiescent voltage and a maximum of the voltage delivered to the device (3.3 V or 5 V) minus 0.2 V [1]. This analog signal is then sent to the Arduino to be converted into a digital signal for serial input into the Bluetooth module. The Bluetooth module will then continuously send this data to the Raspberry Pi to store the number of revolutions the wheel has completed.


### Meeting the Diameter of Wheel Constraint

The minimum wheel size has been set at 20 inches to account for the average wheel size of the smallest type of bike that would be commonly ridden on a trail, a BMX bike [3]. The largest wheel size has been set at 32 inches which is 3 inches above the most common largest mountain bike tire at 29 inches [4]. 

This is proven within the calculations for velocity


### Meeting the Sensing Speed Constraint

The Maximum Velocity that the Work System supports should be no higher than 190 miles per hour to account for the fastest speed achieved on a bike being 186 miles per hour [5]. The minimum speed that needs to be supported is 0 miles per hour. This will allow users to reach very small speeds without having to worry that the Kit will not record the data to the Work System. 
The Maximum Velocity that the Work System can record at is well above the 190 MPH value set by the constraint. The minimum velocity that the kit can support is no velocity at all and can support extremely small changes in velocity as long as the interval between rotations does not exceed the battery life of the system.

- Given the slowest delay within the system is 10 microseconds and the minimum wheel diameter that needs to be supported is 20 Inches we can use the following formulas.

  **Circumference = Diameter * Pi**

  **Velocity = Distance / Time**

- Using these formulas we get circumference is 62.83 and maximum velocity given 10 microseconds is 6283000 inches per second or 356989 miles per hour.


### Meeting the Waterproof Constraint

A waterproof box shall house the work system. This is in the case that the rider is to use the Ride Replay Kit in the rain or ride through a body of water that could potentially splash the work system or fully submerge it. The electronics will be coated in an acrylic conformal coating that will be done using a 419D Liquid that protects from moisture and is certified IPC-CC-830B [6]. To seal the box to add a second layer of protection an acrylic-based sealant will be used and conforms to the military specification MIL-46106 which provides a strong sealant and water repellent.

### Meeting the Ride Time Constraint

Since there are many different trail lengths and skill levels, there is no set amount of duration for trails. Due to this the minimum amount of time that the battery should last is hard to make a specific number for. Team 5 decided to set the minimum amount of time at 24 hours. This should allow for users to record large trails without having to worry about the battery not lasting the entire trail. 

- To solve for the maximum time the battery can last, the amperage output for each device and the milliamp hours output of the battery is needed. The following values are needed: the current draw for Arduino, the current draw for the Hall effect generator, and the current output of the battery. The values are 150 milliamps, 10 milliamps, and 5000 milliamp hours respectively. The following formulas can be used:

  **Amphours = Amps * Hour**

  **Hours = Amp Hours / Amps**

- Using these we can solve for the hours the device will be on given a full charge. Hours calculated from this is 5000 milliamp hours divided by 160 milliamps which is 31.25 hours.

### Creating a Work Map

- Creating the work map is the overall goal of the Work System. To do this altitude change, distance, and mass are needed. Altitude change comes from the altimeter from the previous group. Distance is calculated from the hall effect sensor on the back bike wheel and from the diameter of the wheel given by the user. The mass is given by the user from the User Interface subsystem. Once the given data is received the following formulas can be used.

  **Convert lbs to kilograms: kilograms = lbs / 2.205**

  **Work = kilograms * gravity * change in altitude**

- Taking these values and creating a matrix for altitude changes we can create a work map by plotting a graph with the X-axis being the current index of the matrix and the Y-axis being the work calculated in joules for the given altitude at the current index of the matrix.

![MatLab Code](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/MatlabCodeForWorkSystem.png)

Figure 1. Matlab Code for Work System

![Work Map Example](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ExampleWorkMap.png)

Figure 2. Example Work Map

## Buildable Schematics

![SolidWorks design of work system housing](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/HousingForWorkSystem.png)

Figure 3. Interior View of Housing for Work System

![Work system housing with lid](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/design1.png)

Figure 4. Design of Housing for work system with lid

![Holder for magnet front](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Worksystemmagnetholderfront.png)

Figure 5. Design of magnet holder within spoke

![Holder for magnet back](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/Worksystemmagnetholder1.png)

Figure 6. Back design of magnet holder within spoke

![Work System Circuit Dimesions](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/ArduinoNanoOnPerfboardWithDimensions.png)

Figure 7. Work System Circuit Dimensions

![Circuit Schematic](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/SchematicForWorkSystem.png)

Figure 8. Circuit Schematic of Work System



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


