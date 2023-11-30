Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Audio System
The audio subsystem records the audio from the bike trail and replays it on the exercise bike for the user to hear the environment of the trail.


##  Subsystem Functionality

The audio subsystem will use a unidirectional microphone mounted to the mountain bike to record audio from the trail. The audio will then be processed to remove unwanted noises and improve audio quality through equalization and audio compression. This processed audio will then go to the speakers of the exercise bike for playback while riding the trail. The audio should sync with the work map to give the user an accurate audio experience for when the user comes across different environments which produce different sounds.

## Constraints 


|Constraint|Description|
|----------|-----------|
|Recording audio without undesired noises|A unidirectional microphone will be used to reduce the pick up of audio from the bike and the user riding the bike. A wind mic filter will reduce wind noise.|
|Processing audio|The recorded audio will need to be stored and accurately played back for the user.|
|Syncing Audio with Work Map|Audio associated with specific distance must be synced with the correlated work value from the Work Subsystem.|
|Limit Audio level output to speaker|Audio Output has to be limited to 80 decibels or less to reduce hearing fatigue. OSHA Law requires less than 85 decibels for 8 hours.|



## Analysis

### Meeting Noise Constraint
An equalizer will be implemented within the Raspberry Pi that can apply a low-pass or high-pass filter to the audio to filter out any unwanted noises. For example, wind noises are usually high frequency noises and these can be filtered out with a low-pass filter applied to the audio. Any low frequency rumble can be filtered out as of the audio file through a high-pass filter as well.

### Meeting Processing Constraint

Formula:

Bits per sample x samples per second = bits per second / 8 = Bytes per second x 60 seconds = Bytes per minute x 60 minutes = Bytes per hour.

Recording at: 16 bit, 44.1 KHz, Mono:

16 bits per sample x 44,100 samples per second = 705,600 bits per second. [88.2 KB per second]
705,600 bits per second / 8 = 88,200 bytes per second x 60 seconds = 5,292,000 Bytes or 5.292 MB per minute.
5.292 MB per minute x 60 minutes = 317.52 MB per hour.

Team 5 calculated that the maximum amount of ride time we recommend the user to ride is 4 hours. So with the microphone recording at 317.52 MB per hour x 4 hours = 1,270.08 MB or 1.2GB for 4 hours of recording.

According to benchmark taken of the Raspberry Pi 4, the SD card can be processed at 44.5 Mb/s meaning it would take approximately 12 seconds for the audio to process fully onto the SD card.

The Raspberry Pi can add an equalizer, compression, or any other audio effects to the audio after the recording occurs, so it is not limited to occur during recording. This is because the user will take time to transport the mountain bike with the microphone back to the exercise bike, meaning the processing can occur during this period, if the battery keeps the board on.

### Meeting Syncing Constraint

The audio recorded from the mountain bike is to be synced with the distance and speed of the Work Map. However an issue that could occur is, if during playback on the exercise bike, the user pedals at a slower rate than what was originally recorded, the audio may slow down and become pitched down as well. To prevent this from happening, the audio will be divided into 1 minute sections and every time the user pedals slowly in that section, the audio will loop until they have reached the next section. The looping will have a crossfade applied to the audio loop to prevent sudden stopping in the audio to play back a previous section. This should make for a more smooth transition to the looping of audio. The same concept will be applied if the user is pedaling faster than the original recorded speed. Once the user has finished the length of a section, quicker than normal, the audio will fade to the next section, thus syncing it with the work map.



### Meeting Audio Level Constraint

Create a Volume limiter built into the audio processing unit. This will limit the maximum amount of decibels to 80 decibels whenever the speaker is turned up to max volume. A microphone can be used to test the decibel levels after implementation to confirm. 


## Buildable Schematics

[3D Schematics will be posted in GitHub]	

The schematic posted in GitHub represents an arm that will be mounted to the CAMVATE bike mount, which will mount the microphone 12 inches from the handlebars of the bike.


![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderWithGoPro.png)
Figure 1. Holder Side View With GoPro

![HolderBottomViewWithGopro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderWithGoProBottomView.png)
Figure 2. Holder Bottom View With GoPro

![HolderTopView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderTopDimensions.png)
Figure 3. Holder Top View Showing GoPro Attachment Dimensions

1[HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderSideDimensions.png)
Figure 4. Holder Side View Showing Microphone Attachment Dimensions

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|https://tinyurl.com/4j8j3rhy|Movo VXR10 Universal Video Microphone with Shock Mount, Deadcat Windscreen|VXR10|Movo|1|$39.95|$39.95|
|https://tinyurl.com/4r7cuptk|CAMVATE Super Clamp with Cold Shoe Mount for Camera Flash Light |Accessories - 1814|1814|CAMVATE|1|$15.00|$15.00|
|https://tinyurl.com/2s3aramp|Raspberry Pi 4 Model B - 4GB RAM|RP4B4GB|Raspberry Pi|0 (Split between Visual Subsystem)|$0.00|$0.00|
|https://tinyurl.com/bdzkabtp|Acoustic Audio AA321B Mountable Indoor Speakers 400 Watts Black Bookshelf Pair|AA321B|Acoustic Audio|1|$36.88|$36.88|
||||||TOTAL|$91.83|

## References:

[1] Shotgun Video Microphone VXR10
https://www.movophoto.com/products/vxr10-universal-cardioid-condenser-mic
(accessed Nov. 1, 2023)
	 	
[2] Audio File Size Calculations
https://www.audiomountain.com/tech/audio-file-size.html
(accessed Nov. 1, 2023)

[3] microSD Card Benchmarks
https://www.pidramble.com/wiki/benchmarks/microsd-cards
(accessed Nov. 1, 2023)

