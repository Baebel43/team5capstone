Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Visual System


##  Subsystem Functionality

The visual subsystem uses the user’s current distance traveled on the recorded trail, and displays the frame from that point to the user on the screen. The video will replay back to the user at minimum 60 FPS at 1080p resolution. In the case that the user is replaying the trail slowly, the Ride Replay kit will utilize frame interpolation to maintain the smooth visuals, to avoid choppy video replay.

## Constraints 

|Constraint|Description|
|----------|-----------|
|Maximum FPS|60 FPS|
|Maximum resolution|1080p|
|Storage space|2TB|



##Analysis


### Meeting Frames Per Second

Experts say the human eye can only perceive up to 60hz-75hz. The GoPro Hero 5 can record video at 30FPS to 120FPS. Team 5 will record trails at 120FPS to not only minimize the amount of frames needed from frame interpolation, but also cause smoother video for the user when replaying the trails at low speeds. The HDMI splitter inherited from the previous teams limits FPS outputs to 60 FPS. Because of this limitation, the output from the system can only be at 60 FPS. This also ensures that the user will have smooth video as it stays within the 60-75hz range. [1]

### Meeting Resolution

The GoPro Hero 5 can record from 480p to 4K. The max resolution that can be recorded while maintaining 120FPS is 1080p, which is also the resolution limitation for the HDMI splitter from the previous team. The goal of the visual subsystem is to be immersive, which includes picture resolution, so to make the experience as immersive as possible, the max resolution capable should be used, which is 1080p.

### Minimum percentage of recorded speed

The recording will be done at 120 FPS, and the resulting video will be put into frame interpolation software to create inbetween frames resulting in 240 FPS. The inherited HDMI splitter only has capabilities up to 1080p 60Hz, which limits video outputs to 60 FPS. Now using the interpolated video of 240 FPS, the video can support users going 25% of the original trail’s speed, while maintaining smooth visuals.

![Percentage](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/MinimumPercentageRecordingCalcluationForVisualSystem.png)

Team 5 will not interpolate the video more than once as to not take up too much storage space.

### Meeting minimum storage requirements

With the goal of 4 hours of video, the calculation for the storage space needed for each recorded ride is as follows:

![Bitrate](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/StorageCalcluationForVisualSystem.png)

These calculations already take the GoPro Hero 5’s video compression into account.[2] Also, with the interpolation scaling the video to 240FPS, the video will now take 216GB of space. With this calculated, the SD card can now fit up to video files.


## Buildable Schematics

![Holder Bottom](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/HolderBottom.png)
Figure 1. Holder Bottom

![Holder Side](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/HolderSide.png)
Figure 2. Holder Side

## Bill of Materials

Item
|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|-----------|-----------|------------|--------|----------------|-----|
|GoPro Hero5 Black|Waterproof Digital Action Camera for Travel with Touch Screen 4K HD Video 12MP Photos|CHDHX-502|GoPro|1|$374.52|$374.52
|Raspberry Pi 4  Model B - 4GB RAM|4GB RAM, Dual Micro HDMI Port with SSD Holder, Bluetooth 5.0|RP4B4GB|Raspberry Pi|1 (WIll also be used for Audio Subsystem)|$55.00|$55.00
|Portable-Charger-Power-Bank|2 Pack 15000mAh Dual USB Power Bank Output 5V3.1A Fast Charging Portable Charger Compatible with Smartphones and All USB Devices|B0B45GX5V7|LOVELEDI|1|$19.99|$19.99
|Micro SD|High Speed 2TB SD/TF Flash Memory Card|B0C4RK83RK|Lenovo|1|$30.00|$30.00|
|Total||||Total Components|3|Total Cost|





## References:

[1] https://azretina.sites.arizona.edu/node/837

[2]https://havecamerawilltravel.com/gopro/video-hero5-black/

