
Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha, Caleb Turney

# Detail Design: Work System


##  Subsystem Functionality

The speedometer subsystem will drive fans that are pointed toward the user. The speedometer will take the work measured from the work subsystem and use that to find the speed that the user is virtually traveling. Based on the speed measured, the speedometer will drive the fans. The faster the speed, the faster the fans will rotate. By connecting the RPM of the fans proportionally to the speed being traveled, a more immersive experience can be achieved, since the user will be able to artificially feel the changes in their acceleration.
## Constraints 

|Constraint        |Description        |
|------------------|-------------------|
|Distance between the box attached to the bike frame and the spoke|The measured minimum distance between the bike spoke and frame was found to be 30 mm meaning that the device can be no larger than 20 mm in depth protruding from the frame in between the spoke and the frame.|
|Magnetic Sensor Range|The magnetic sensor can be no more than 23.75 mm away from the magnet and it can be no closer than 12.7 mm.|
|Diameter of the Wheel|The device must support the minimum wheel size of 45.72 cm in diameter.|
|Sensing Speed (Minimum and Maximum Velocity)|The maximum velocity the sensor will be able to detect is 190 miles per hour. The Minimum velocity supported is 0 miles per hour.|
|Splash Resistant|The kit shall have the ability to withstand splashes from puddles and rain.|
|Ride Time|The user will be able to use the kit concurrently for 24 consecutive hours.|


## Analysis

### Meeting distance constraint

The average distance between the frame and the spoke of a mountain bike is between 30 mm and 35 mm. So to account for a 0.5-inch wiggle of the back wheel the maximum distance the box enclosing the device can protrude from the side of the frame to the spoke is 20 mm.


## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Hall Effect Sensor|Hall Effect Sensor Single Axis TO-92-3|DRV5056A2ELPGMQ1|Texas Instruments|2|$2.01|$4.02|
|Arduino Nano 33 BLE |Arduino Nano 33 Bluetooth Low Energy Microcontroller|ABX00030 |Arduino|1|$26.30|$26.30
|AA holder|Battery holder fo 3 AA batteries|BC3AAW-ND|MPD (Memory Protection Devices)|1|$2.33|$2.33|
|Magnet|Nickel-Plated N52 Magnet|DX44-N52|K&J Magnetics|1|$11.57|$11.57|
|Acrylic Sealant (For waterproofing enclosure)|Clear Electronic Grade Silicone - 2.8 oz Squeeze Tube|ASI 388|American Sealants Inc.|1|$11.95|$11.95|
|Conformal Coating (for waterproofing PCB)|CONFORMAL COATING UL 94V-0|419D-55ML|MG Chemicals|1|$16.76|$16.76|
|Total|||Total Components|7|Total Cost|$72.93


## References:

[1]”DRV5056-Q1 Automotive Unipolar Ratiometric Linear Hall Effect Sensor,” https://www.ti.com/lit/ds/symlink/drv5056-q1.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1698173863097&ref_url=https%253A%252F%252Fwww.ti.com%252Fgeneral%252Fdocs%252Fsuppproductinfo.tsp%253FdistId%253D10%2526gotoUrl%253Dhttps%253A%252F%252Fwww.ti.com%252Flit%252Fgpn%252Fdrv5056-q1 (accessed Oct. 25th, 2023)

[2]”How do you calculate the magnetic flux density?” https://www.supermagnete.de/eng/faq/How-do-you-calculate-the-magnetic-flux-density (accessed Oct. 25th, 2023)

[3]"BMX Bike Sizing,”  https://rampfest.com.au/pages/bmx-bike-sizing. (accessed Oct. 25th, 2023)

[4]"Bike Tire Sizes Guide," Sweet Pete's. Available: https://www.sweetpetes.com/articles/bike-tire-sizes-guide-pg564.htm. (accessed Oct. 25th, 2023)

[5]E. Jack, Fastest cyclist ever: Setting a World Record speed of 183mph on a bicycle, Cyclist, 2019. https://www.cyclist.co.uk/news/fastest-cyclist-ever-setting-a-world-record-speed-of-183mph-on-a-bicycle

[6]V. David, A Quick Guide to Understand IPC-CC-830B Qualification Standard, HumiSeal, 2018. https://blog.humiseal.com/a-quick-guide-to-understand-ipc-cc-830b-qualification-standard

[7] Energizer Brands LLC, “Cylindrical Primary Lithium Handbook and Application Manual,” Form No. 12004-A.
