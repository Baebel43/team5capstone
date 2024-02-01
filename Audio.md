Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Audio System
The audio subsystem records the audio from the bike trail and replays it on the exercise bike for the user to hear the environment of the trail.

##  Subsystem Functionality
The audio subsystem will use a unidirectional microphone mounted to the mountain bike to record audio from the trail. The audio will then be sent to a cloud based service where it will be processed to remove unwanted noises and improve audio quality through equalization and audio compression. The audio will also be divided into loop points depending on key points of interest throughout the trail. This processed audio will then go back on the Ride Replay Kit to the speakers of the exercise bike for playback while riding the trail. The audio should sync with the work map to give the user an accurate audio experience for when the user comes across different environments which produce different sounds.

## Constraints 

|Constraint|Description|
|----------|-----------|
|Recording audio without undesired noises|A unidirectional microphone will be used to reduce the pick up of audio from the bike and the user riding the bike. A wind mic filter will reduce wind noise.|
|Syncing Audio with Work Map|Audio associated with specific distance must be synced with the correlated work value from the Work Subsystem.|
|Python Libraries used for audio processing and looping|The correct libraries must be implemented in order for the audio processing to occur in Python on a separate computer. The audio will need to loop upon key points of interest until the biker has reached the next section.|
|Processing audio|The recorded audio will need to be stored and accurately played back for the user.|
|Limit Audio level output to speaker|Audio Output has to be limited to 80 decibels or less to reduce hearing fatigue. OSHA Law requires less than 85 decibels for 8 hours.|

## Analysis

### Meeting Noise Constraint
To record audio, a unidirectional microphone will be mounted to the front of the bike on a 12 inch arm to reduce the pick up of audio from the bike and the user riding the bike. The microphone will have a windshield on it to reduce wind noise. Once the audio is recorded on the mountain bike, the data on the Raspberry Pi can be uploaded to the online cloud based service Cloud SQL. Once the audio has been uploaded to the cloud, an external computer will complete the audio processing by using a Python code that Team 5 will be writing. An equalizer will be implemented that can apply a low-pass or high-pass filter to the audio to filter out any unwanted noises. For example, any hiss or squeaking from the bike is usually a high frequency noise and these can be filtered out with a low-pass filter applied to the audio. Any low frequency rumble or wind noises can be filtered out of the audio file through a high-pass filter as well. This audio processing will occur on a separate computer through uploading the data from the SD card to the computer. After the audio has been processed on the computer, the data will then be sent back through the SD card to be uploaded onto the exercise bike.

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
The audio recorded from the mountain bike is to be synced with the distance and speed of the Work Map. However, an issue that could occur is, if during playback on the exercise bike, the user pedals at a slower rate than what was originally recorded, the audio may slow down and become pitched down as well. To prevent this from happening, the audio will be divided into sections and every time the user pedals slowly in that section, the audio will loop until they have reached the next section. The same concept will be applied if the user is pedaling faster than the original recorded speed. Once the user has finished the length of a section, quicker than normal, the audio will fade to the next section, thus syncing it with the work map.

Using this audio file, a spectrogram can be generated in Python to plot frequency over time. With this data, Team 5 can determine the points-of-interest throughout the duration of the audio recording. An example of these points-of-interest would be the sounds of waterfalls or terrain/environment changes. With the points of interest determined, the loop points can be more accurately determined. To create a smooth loop, the loop should occur during a consistently occurring frequency so it is less noticeable when the ending and starting of a loop occurs. For example, a point of interest would be passing by a waterfall and the loop should occur during this period and it should not loop back to before the waterfall because the audio in the loop would be noticeably different from the waterfall noise thus creating a choppy sounding loop.  

![Spectrogram Example](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Spectrogram.png)

Above is an example of a Python generated Spectrogram using the 'scipy' library. Commonly occurring frequencies appear from 6 to 8 seconds into the audio clip. The time axis will be much larger but these are examples of good loop points that will be practically unnoticeable by the user.

The looping will have a crossfade applied to the audio loop to prevent sudden stopping in the audio to play back a previous section. This crossfading can be programmed to occur during playback when it takes an input and then determines which section of audio to playback. For transitions, the first audio clip will slowly decrease the volume as the next audio file slowly increases, until only the new audio section is playing. This should make for a more smooth transition to the looping of audio. 

In order to create this loop, the audio system will be linked to the work map to sync with the Visual and Resistance systems for an immersive experience. The Raspberry Pi accepts the time/speed that the user is at, and then once this data is obtained, it will move to the section of the audio file that the user should be in. The crossfade should occur during this transition period of one section to the other.


### Python Libraries used for audio processing and looping
The goal is to use Python to automate the processing for the audio to be sectioned into various loop points based on key points of interest that loop until the user proceeds to the next section. This is because Team 5 wants the capability to process up to a 4 hour recording. In order to create these loop points, the original audio file from the trail must be divided into many different audio files automatically through the use of Python and machine learning.

Within Python there are functions that can be used to apply a high-pass or low-pass filter to the two audio file formats, .wav and .mp3 files. There is also libraries and machine learning to create these loops based on clustering commonly occurring frequencies. These functions can be made with the following libraries: 
Pysqlite, numpy, librosa, scipy, wave, math, matplotlib.pyplot., and scikit-learn

The 'pysqlite' library allows for interfacing with an SQL based Google Cloud service that the Raspberry Pi will upload the files to.

The 'numpy' library allows for recreation of the audio signal within python through processing arrays of data points. This allows for manipulation of the signal including filtering and other signal effects.

The 'librosa' library allows for analyzing and processing audio signals. This allows for importing of .mp3 files. This works along with the 'numpy' library and allows for manipulation of these .mp3 files. 'Librosa' also allows for the creation and computation of spectrograms of audio, which is a plot of audio frequency over the time of the audio clip.

The 'scipy' library is an extension of 'numpy' which provides additional capabilities such as signal processing. 

The 'math' library allows for greater mathematical functions and number theory of the digital audio signal. 

The 'wave' library is included within the list, in case .wav files are needed instead of .mp3 files. This library allows for the reading of .wav files. 

The 'matplotlib' library allows for visualization of the audio file and spectrogram through plots.

The 'scikit' library is a machine learning library that will allow for clustering of audio that represent commonly occurring frequencies. From this, sectionalization of audio can be done and correct loop points can be established. 

The cutoff frequency of the audio file can be specified within the code depending on what the unwanted frequencies are. For example, a 50 hz high-pass filter may be applied to reduce rumble or wind noises.

### Meeting Audio Level Constraint

Create a Volume limiter built into the audio processing unit. This will limit the maximum amount of decibels to 80 decibels whenever the speaker is turned up to max volume. A microphone can be used to test the decibel levels after implementation to confirm. 



### Meeting Processing Constraint

Team 5 wants to ensure the audio file will be small enough to fit on the SD card so that it can be uploaded for processing. 

Formula:
Bits per sample x samples per second = bits per second / 8 = Bytes per second x 60 seconds = Bytes per minute x 60 minutes = Bytes per hour.

Recording at: 16 bit, 44.1 KHz, Mono:
16 bits per sample x 44,100 samples per second = 705,600 bits per second. [88.2 KB per second]
705,600 bits per second / 8 = 88,200 bytes per second x 60 seconds = 5,292,000 Bytes or 5.292 MB per minute.
5.292 MB per minute x 60 minutes = 317.52 MB per hour.

Team 5 calculated that the maximum amount of ride time we recommend the user to ride is 4 hours. So with the microphone recording at 317.52 MB per hour x 4 hours = 1,270.08 MB [1.2G] for 4 hours of recording.

According to a benchmark taken of the Raspberry Pi, the SD card can be processed at 44.5 Mb/s meaning it would take approximately 28.5 seconds for the audio to process fully onto the SD card.

After data is stored on the SD card, it can be plugged into a computer to transfer the audio file to the SQL cloud-based service where Team 5 can add an equalizer, compressor, or any other audio effects to the audio after the recording occurs, so it is not limited to occur during recording. If the user has an internet connection, the user can upload the file as soon as they finish recording the trail and while the user takes the time to transport the mountain bike with the microphone back to the exercise bike, the processing can occur.

### Meeting Audio Level Constraint

Team 5 will seek to create a volume limiter built into the audio playback system. This will limit the maximum amount of decibels to 80 decibels whenever the speaker is turned up to max volume. 

The general rule is that, to increase speaker sound output by 3 decibels, the amplifier power must double.

|Amp Power|Speaker|
|----------|-----------|
|0.125	W|79	dB|
|0.25	W|82	dB|
|0.5	W|85	dB|
|1	W|88	dB|
|2	W|91	dB|
|4	W|94	dB|
|8	W|97	dB|
|16	W|100	dB|
|32	W|103	dB|
|64	W|106	dB|
|128	W|109	dB|
|256	W|112	dB|

Based upon the Sensitivity specification given of the Pyle PLMR24B speaker: “88 db at 1 watt 1 meter” and the Wattage of 200W, then this speaker falls between the 128W and 256W range on the table shown above. This shows that the maximum decibel output to be around 111dB, which would make the speaker output much louder than the 80 db that Team 5 desires. After looking at the chart, the speaker will need to be powered at 0.14 Watts in order to have a maximum output of 80 dB's. This would prevent the speaker from ever being able to physically output audio greater than 80 dB, which would support the OSHA audio standard of no exposure over 85 decibles of audio for an 8 hour period of time. By meeting this spec, Team 5 aims to have this exercise bike placed in a public environment such as a gym or fitness center. 

To power the speaker at 0.14 Watts a physical audio limiter will need to be applied. The 200W Pyle speakers require an amplifier to power them. The amplifier Team 5 aims to use is the Pyle PDA29BU.5 which supports output to speakers of 200W.

A solution to this would be to attenuate the input to the amp with a fixed resistor divider. To do this, a resistor must be implemented in parallel to the input of the amp which then continues to the speakers system. Which will act as a high impedance load and prevent the speakers from reaching any gain above 80 decibels. These resistors will create a voltage divider circuit that will divide the voltage of the input audio that will in term limit the audio output of the speakers. The resistors needed are already in Team 5’s possession. The resistor will need to be determined based on the actual wattage drawn from the speakers. It was described in the item description that the speakers may not run at a full 200 Watts but have the capability to do so. Thus, after purchasing and testing the speakers, a DMM will be used to determine the power drawn from the speakers and a correct resistance can be chosen to limit output to 80 decibles.

## Buildable Schematics

[3D Schematics will be posted in GitHub]	

Shown in the buildable schematics below, the microphone will be mounted to the side of this 12 inch arm that also holds the GoPro camera using the cold-shoe mount. This arm will be mounted to the CAMVATE bike mount, which will mount the microphone and GoPro camera to the handlebars of the bike. This will ensure that the microphone does not pick up as much bike noise, user breathing noises, or any other extraneous noises. This is the ideal setup for picking up audio from the bike trail.

![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderWithGoPro.png)
Figure 1. Holder Side View With GoPro

![HolderBottomViewWithGopro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderWithGoProBottomView.png)
Figure 2. Holder Bottom View With GoPro

![HolderTopView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderTopDimensions.png)
Figure 3. Holder Top View Showing GoPro Attachment Dimensions

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderSideDimensions.png)
Figure 4. Holder Side View Showing Microphone Attachment Dimensions

## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|https://tinyurl.com/4j8j3rhy|Movo VXR10 Universal Video Microphone with Shock Mount, Deadcat Windscreen|VXR10|Movo|1|$39.95|$39.95|
|https://tinyurl.com/4r7cuptk|CAMVATE Super Clamp with Cold Shoe Mount for Camera Flash Light |1814|CAMVATE|1|$15.00|$15.00|
|http://tinyurl.com/3yy5rby7|Pyle 3-way Mini Box Speaker System - 3.5 Inch 200 Watt Waterproof Marine Grade Mount Speakers (Black)|PLMR24B|Pyle|1|$29.99|$29.99|
|http://tinyurl.com/496w74wc|Pyle Wireless Bluetooth Stereo Power Amplifier - 200W Dual Channel Sound Audio Stereo Receiver |PDA29BU.5|Pyle|1|$41.67|$41.67|
||||||TOTAL|126.61|

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

[4] How To Add A Resistor To A Speaker To Change Or Match Impedance
https://soundcertified.com/how-to-add-resistor-to-speaker-to-change-match-impedance/
(accessed Nov. 27, 2023)

[5] Volume Reducing Resistor in Speaker Lines
https://electronics.stackexchange.com/questions/278198/volume-reducing-resistor-in-speaker-lines
(accessed Nov. 27, 2023)

[6] Scikit-Learn Machine Learning in Python] 
https://scikit-learn.org/stable/
(accessed Jan. 31, 2023)

[7] Volume Reducing Resistor in Speaker Lines
https://electronics.stackexchange.com/questions/278198/volume-reducing-resistor-in-speaker-lines
(accessed Jan 31, 2023)

