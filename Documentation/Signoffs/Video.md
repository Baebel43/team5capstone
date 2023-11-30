Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Visual System


##  Subsystem Functionality

The visual subsystem uses the user’s current distance traveled on the recorded trail, and displays the frame from that point to the user on the screen. The video will replay back to the user at minimum 60 FPS at 1080p resolution. In the case that the user is replaying the trail slowly, the Ride Replay kit will utilize frame interpolation to maintain the smooth visuals, to avoid choppy video replay. 

## Constraints 

|Constraint|Description|
|----------|-----------|
|Minimum Recording FPS|Video must be recorded at or above 60 FPS to ensure smooth video output to the user even at low speeds|
|Minimum Resolution|Video must be recorded at and display at or above 1080p|
|Minimum User Speed|The replay must support the user going minimum 25% of the recorded speed with smooth video|
|Storage Space Requirements|Replay video must fit on 2TB micro SD Card|



## Analysis


### Meeting Frames Per Second Constraint

Experts say the human eye can only perceive up to 60hz-75hz [1]. The GoPro Hero 5 can record video at 30FPS to 120FPS. Team 5 will record trails at 120FPS to not only minimize the amount of frames needed from frame interpolation, but also cause smoother video for the user when replaying the trails at low speeds. The HDMI splitter inherited from the previous teams limits FPS outputs to 60 FPS. Because of this limitation, the output from the system can only be at 60 FPS. This also ensures that the user will have smooth video as it stays within the 60-75hz range.

### Meeting Resolution Constraint

The GoPro Hero 5 can record from 480p to 4K. The max resolution that can be recorded while maintaining 120FPS is 1080p, which is also the resolution limitation for the HDMI splitter from the previous team. The goal of the visual subsystem is to be immersive, which includes picture resolution, so to make the experience as immersive as possible, the max resolution capable should be used, which is 1080p. 	

### Minimum percentage of recorded speed

The recording will be done at 120 FPS, and the resulting video will be put into frame interpolation software to create inbetween frames resulting in 240 FPS. The inherited HDMI splitter only has capabilities up to 1080p 60Hz, which limits video outputs to 60 FPS. Now using the interpolated video of 240 FPS, the video can support users going 25% of the original trail’s speed, while maintaining smooth visuals.

![Percentage](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/MinimumPercentageRecordingCalcluationForVisualSystem.png)

Team 5 will not interpolate the video more than once as to not take up too much storage space.

### Meeting minimum storage requirements

With the goal of 4 hours of video, the calculation for the storage space needed for each recorded ride is as follows:

![Bitrate](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/StorageCalcluationForVisualSystem.png)

These calculations already take the GoPro Hero 5’s video compression into account.[2] Also, with the interpolation scaling the video to 240FPS, the video will now take 216GB of space. With this calculated, the SD card can now fit up to video files.

### Syncing with Work Subsystem
	
The video output from the Visual Subsystem needs to synchronize with the Work Subsystem. This is to ensure the user’s visuals are in sync with the current point in the work map they are experiencing. For instance, if the video shows the user going up a hill, they will also experience increased resistance due to the work map. This will be done by associating each frame recorded or interpolated with a specific distance, and then display each frame depending on the distance the user has traveled in total. This constraint is essential to make the replays immersisive to the user.

### Obtaining Interpolated Frames

As mentioned before, the FPS of the recorded video will need to be doubled, to ensure that the user has smooth video replay when progressing slower than then original recording. Team 5 will be using the free AI frame interpolating tool called Flowframes Video Interpolator to interpolate the recorded video. Team 5 then move the interpolated video onto the RaspberryPi to replay to the user.

### Scaling Video Replay

The Resistance System functions using a work over distance graph as well as a work over time graph. As the user progresses distance while replaying the trail, the work changes, which then progresses the time graph. Using this relation, the video will progress depending on how far the user has travelled...


## Buildable Schematics

![Holder Bottom](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/HolderBottom.png)
Figure 1. Holder Bottom

![Holder Side](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderSide.png)
Figure 2. Holder Side

This electrical system is fully contained within the GoPro, so there is no electrical schematic for this system.

## Bill of Materials

Item
|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|-----------|-----------|------------|--------|----------------|-----|
|GoPro Hero5 Black|Waterproof Digital Action Camera for Travel with Touch Screen 4K HD Video 12MP Photos|CHDHX-502|GoPro|1|$374.52|$374.52
|Total||||Total Components|1|Total Cost|





## References:

[1] V. Sierra, How Many Frames Per Second Can We Actually See In?, Arizona Retina Project, Available: https://azretina.sites.arizona.edu/node/837 (accessed Oct. 30th, 2023)

[2] C. David, GoPro HERO5 Black Video Sizes, Framerates, Modes & Options, Have Camera Will Travel, Available: https://havecamerawilltravel.com/gopro/video-hero5-black/ (accessed Oct. 30th, 2023)

[3] “Hero 5 Black User Manual” https://gopro.com/content/dam/help/hero5-black/manuals/HERO5Black_UM_ENG_REVD_Web.pdf (accessed Oct. 30th, 2023)

[4] "Flowframes - Windows GUI for Video Interpolation" "https://github.com/n00mkrad/flowframes"
