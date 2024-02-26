# Detail Design: Audio System
The audio subsystem records the audio from the bike trail and replays it on the exercise bike for the user to hear the environment of the trail.


##  Subsystem Functionality

The audio subsystem will use a unidirectional microphone mounted to the mountain bike to record audio from the trail. The audio will be recorded to a Raspberry Pi where a Python code will send it to a cloud based service where it will be processed to remove unwanted noises and improve audio quality through equalization and audio compression. The audio will also be divided into loop points depending on key points of interest throughout the trail. This processed audio will then go back on the Ride Replay Kit to the speakers of the exercise bike for playback while riding the trail. A separate Raspberry Pi will be responsible for the playback of the audio to the speakers. The audio should sync with the work map to give the user an accurate audio experience for when the user comes across different environments which produce different sounds. The speakers on the exercise bike will be mounted to the sides of the TV and allow the user to hear from both the left and right.

## Constraints 


|Constraint|Description|
|----------|-----------|
|Recording audio without undesired noises|A unidirectional microphone will be used to reduce the pick up of audio from the bike and the user riding the bike. A wind mic filter will reduce wind noise.|
|Processing audio|The recorded audio will need to be stored and accurately played back for the user.|
|Syncing Audio with Work Map|Audio associated with specific distance must be synced with the correlated work value from the Work Subsystem.|
|Python Libraries used for audio processing and looping|The correct libraries must be implemented in order for the audio processing to occur in Python on a separate computer. The audio will need to loop upon key points of interest until the biker has reached the next section.|
|Limit Audio level output to speaker|Audio Output has to be limited to 80 decibels or less to reduce hearing fatigue. OSHA Law requires less than 85 decibels for 8 hours.|



## Analysis

### Meeting Noise Constraint

To record audio, a cardioid polar pattern microphone will be mounted to the front of the bike on a 12 inch arm to reduce the pick up of audio from the bike and the user riding the bike. The microphone will have a windshield on it to reduce wind noise. The Logitech Blue Snowball USB Microphone will be used for recording, and has the option to be switched from a cardioid polar pattern to an omni-directional pattern, meaning it can accept audio from all directions. Team 5 will only switch to use the omni-directional mode if the unidirectional cardiod pattern doesn't accurately record the environmental noises. This microphone is powered and transfers data through the USB 2.0 port on the Raspberry Pi 3 B. Once the audio is recorded on the mountain bike, the data on the SD card from the Raspberry Pi can be uploaded to the online cloud based service, Google Drive. Once the audio has been uploaded to the cloud, an external computer will complete the audio processing by using a Python code that Team 5 will be writing. An equalizer will be implemented that can apply a low-pass or high-pass filter to the audio to filter out any unwanted noises. For example, any hiss or squeaking from the bike is usually a high frequency noise and these can be filtered out with a low-pass filter applied to the audio. Any low frequency rumble or wind noises can be filtered out of the audio file through a high-pass filter as well. After the audio has been processed on the computer, the data will then be sent back to the cloud through which the Raspberry Pi on the exercise bike will run a Python code to transfer the audio back onto the exercise bike, through a separate Raspberry Pi 4.

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Polar_Pattern_microphone.png)

**Figure 1.** Cardioid and Omnidirectional Polar Patterns of Blue Snowball Microphone

### Meeting Processing Constraint

The audio recorded from the bike trail must be stored and accurately played back on the Exercise Bike. To ensure this is possible, the total data stored must be calculated.

Formula:

Bits per sample x samples per second = bits per second / 8 = Bytes per second x 60 seconds = Bytes per minute x 60 minutes = Bytes per hour.

Recording at: 16 bit, 44.1 KHz, Mono:

16 bits per sample x 44,100 samples per second = 705,600 bits per second. [88.2 KB per second] 
705,600 bits per second / 8 = 88,200 bytes per second x 60 seconds = 5,292,000 Bytes or 5.292 MB per minute. 
5.292 MB per minute x 60 minutes = 317.52 MB per hour.

Team 5 calculated that the maximum amount of ride time we recommend the user to ride is 4 hours. So with the microphone recording at 317.52 MB per hour x 4 hours = 1,270.08 MB or 1.2GB for 4 hours of recording. So the maximum audio file size recommended is around 1.2GB which falls within the 15 GB of space given by the Google Drive for free.

According to a benchmark taken of the Raspberry Pi 3, the SD card can be processed at 44.5 Mb/s meaning it would take approximately 28.5 seconds for the audio to process fully onto the SD card.

After the audio file has been recorded, it needs to be uploaded to the cloud through a Google Drive for processing on another, more powerful computer. To do this, the Raspberry Pi needs to be plugged into a computer and there will be a Python code that will transfer the data from the SD card and put it in the Google Drive. Within Python there is a library, pydrive, that allows the Raspberry Pi to upload audio files to the Google Drive, and this can be executed as soon as the Raspberry Pi is connected to the internet. 

### Meeting Syncing Constraint
The audio recorded from the mountain bike is to be synced with the distance and speed of the Work Map. However, an issue that could occur is, if during playback on the exercise bike, the user pedals at a slower rate than what was originally recorded, the audio may slow down and become pitched down as well. To prevent this from happening, the audio will be divided into sections and every time the user pedals slowly in that section, the audio will loop until they have reached the next section. The same concept will be applied if the user is pedaling faster than the original recorded speed. Once the user has finished the length of a section, quicker than normal, the audio will fade to the next section, thus syncing it with the work map.

Using this audio file, a spectrogram can be generated in Python to plot frequency over time. With this data, Team 5 can determine the points-of-interest throughout the duration of the audio recording. An example of these points-of-interest would be the sounds of waterfalls or terrain/environment changes. With the points of interest determined, the loop points can be more accurately determined. To create a smooth loop, the loop should occur during a consistently occurring frequency so it is less noticeable when the ending and starting of a loop occurs. For example, a point of interest would be passing by a waterfall and the loop should occur during this period and it should not loop back to before the waterfall because the audio in the loop would be noticeably different from the waterfall noise thus creating a choppy sounding loop.  

![Spectrogram Example](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Spectrogram.png)

**Figure 2.** Spectrogram Example Plot from Python

Above is an example of a Python generated Spectrogram using the 'scipy' library. Commonly occurring frequencies appear from 6 to 8 seconds into the audio clip. The time axis will be much larger but these are examples of good loop points that will be practically unnoticeable by the user.

The looping will have a crossfade applied to the audio loop to prevent sudden stopping in the audio to play back a previous section. This crossfading can be programmed to occur during playback when it takes an input and then determines which section of audio to playback. For transitions, the first audio clip will slowly decrease the volume as the next audio file slowly increases, until only the new audio section is playing. This should make for a more smooth transition to the looping of audio. 

In order to create this loop, the audio system will be linked to the work map to sync with the Visual and Resistance systems for an immersive experience. The Raspberry Pi accepts the time/speed that the user is at, and then once this data is obtained, it will move to the section of the audio file that the user should be in. The crossfade should occur during this transition period of one section to the other.

The audio recorded from the mountain bike is to be synced with the distance and speed of the Work Map. If the above solution does not work, an alternative solution is to divide the audio clip into 1 minute sections and every time the user pedals slowly in that section, the audio will loop until they have reached the next section. The looping will have a crossfade applied to the audio loop to prevent sudden stopping in the audio to play back a previous section.The same concept will be applied if the user is pedaling faster than the original recorded speed. Once the user has finished the length of a section, quicker than normal, the audio will fade to the next section, thus syncing it with the work map.

### Python Libraries used for audio processing and looping
The goal is to use Python to automate the processing for the audio to be sectioned into various loop points based on key points of interest that loop until the user proceeds to the next section. This is because Team 5 wants the capability to process up to a 4 hour recording. In order to create these loop points, the original audio file from the trail must be divided into many different audio files automatically through the use of Python and machine learning.

Within Python there are functions that can be used to apply a high-pass or low-pass filter to the two audio file formats, .wav and .mp3 files. There is also libraries and machine learning to create these loops based on clustering commonly occurring frequencies. These functions can be made with the following libraries: 
Pysqlite, numpy, librosa, scipy, pydub, pydrive, wave, math, matplotlib.pyplot., and scikit-learn

The 'pysqlite' library allows for interfacing with an SQL based Google Cloud service that the Raspberry Pi will upload the files to.

The 'numpy' library allows for recreation of the audio signal within python through processing arrays of data points. This allows for manipulation of the signal including filtering and other signal effects.

The 'librosa' library allows for analyzing and processing audio signals. This allows for importing of .mp3 files. This works along with the 'numpy' library and allows for manipulation of these .mp3 files. 'Librosa' also allows for the creation and computation of spectrograms of audio, which is a plot of audio frequency over the time of the audio clip.

The 'scipy' library is an extension of 'numpy' which provides additional capabilities such as signal processing. 

The ‘pydub’ library allows audio gain to be manipulated to match the 80 dB output described within the constraint section. It also allows for audio segmentation based on time, if necessary.

The ‘pydrive’ library allows for files to be uploaded to a Google Drive through python script. In this case, the Raspberry Pi will be uploading the audio file to the Drive through this library. 

The 'math' library allows for greater mathematical functions and number theory of the digital audio signal. 

The 'wave' library is included within the list, in case .wav files are needed instead of .mp3 files. This library allows for the reading of .wav files. 

The 'matplotlib' library allows for visualization of the audio file and spectrogram through plots.

The 'scikit' library is a machine learning library that will allow for clustering of audio that represent commonly occurring frequencies. From this, sectionalization of audio can be done and correct loop points can be established. 

The cutoff frequency of the audio file can be specified within the code depending on what the unwanted frequencies are. For example, a 50 hz high-pass filter may be applied to reduce rumble or wind noises.


### Meeting Audio Level Constraint

Team 5 will seek to create a volume limiter built into the audio playback system. This will limit the maximum amount of decibels to 80 decibels whenever the speaker is turned up to max volume. 

There will be a separate Raspberry Pi for playback of audio to the speakers. This Raspberry Pi has an 1/8" auxilary output that the Logitech speakers can plug into and output the processed audio.

Based upon the Sound Pressure Level (SPL Max) found on the Logitech Z207 specification sheet, the speaker can output an audio level of 88 dBA at 1 meter. The approximate distance from the speakers to above the bike seat, where the user riding the bike, is around 1 meter. This means the speaker is capable of outputing 88dB when the user is on the bike, thus the gain needs to be limited. This speaker volume can be adjusted through the audio processing on the Python code found within the library pydub. To prove this, Team 5 will create a SPL meter with a calibrated microphone to determine the speaker output gain at 1 meter from the speakers. Upon finding this gain, the loudness of the audio file can be adjusted so that when the speakers are turned all the way up to max volume the gain will be at or below 80 db.

Another issue that may occur, is if a gym worker or person is closer than the 1 meter length from the speakers, then the audio may be louder than 80 db to them. To solve this issue, a directional speaker cone can be 3D printed and mounted to each speaker to keep the sound projecting in the direction of the user only. This would mitigate the sound from getting to anyone standing beside the biker and keep the audio within the OSHA specification. 

![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Speaker%20Cone%20Front.png)
**Figure 3.** Directional Speaker Cone

## Buildable Schematics

The schematic posted in GitHub represents an arm that will be mounted to the CAMVATE bike mount, which will mount the microphone 12 inches from the handlebars of the bike. An adapter will be needed to convert the cold shoe mount to a standard 5/8" camera thead, that the Blue Snowball Microphone has. This way the microphone will still be able to be mounted to the 12" arm, away from the user.

Shown in the buildable schematics below, the microphone will be mounted to the side of this 12 inch arm that also holds the GoPro camera using the cold-shoe mount. This arm will be mounted to the CAMVATE bike mount, which will mount the microphone and GoPro camera to the handlebars of the bike. This will ensure that the microphone does not pick up as much bike noise, user breathing noises, or any other extraneous noises. This is the ideal setup for picking up audio from the bike trail.





![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Speaker%20Holder%20Front.png)
**Figure 4.** Speaker Holder Front

![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Speaker%20Holder%20Back.png)

**Figure 5.** Speaker Holder Back, With Screw Holes For Mounting


![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Speakers%20Mounted%20to%20Sides%20of%20TV.png)

**Figure 6.** Speakers Mounted to Sides of TV


![HolderSideWithGoPro](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderWithGoPro.png)

**Figure 7.** Holder Side View With GoPro

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/HolderSideDimensions.png)

**Figure 8.** Holder Side View Showing Microphone Attachment Dimensions

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Microphone%20Subsystem%20(Blue%20Yeti%20Microphone).png)

**Figure 9.** Circuit Diagram for Microphone In Ride-Replay Kit

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Ride_Replay_Kit_Large_Schematic.png)

**Figure 10.** Ride Replay Kit Schematic

![HolderSideView](https://github.com/Baebel43/team5capstone/blob/main/Documentation/Images/AudioAndVideoSystemImages/Ride_Replay_Kit_Large_Schematic(Zoomed_In_Audio_Subsystem).png)

**Figure 11.** Zoomed in Audio Subsystem Circuit Diagram


## Bill of Materials

|Item|Description|Part Number|Manufacturer|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|http://tinyurl.com/yc6b6wyp|Logitech Blue Snowball USB Microphone for PC|988-000070|Logitech|1|$49.99|$49.99|
|http://tinyurl.com/6nshjt5v|Deadcat Windshield Wind Cover for Blue Snowball iCE|B07SF5C6BV|YOUSHARES|1|$9.99|$9.99|
|http://tinyurl.com/3r4b9tjt| 5/8"-27 Male Threaded Cold Shoe Adapter for Microphone Mount|0953|CAMVATE|1|$5.99|$5.99|
|http://tinyurl.com/yzzv7sss|CAMVATE Super Clamp with Cold Shoe Mount for Camera Flash Light|1814|CAMVATE|1|$15.00|$15.00|
|http://tinyurl.com/2xbv66vw|Logitech Z207 2.0 Multi Device Stereo Speaker|Z207|Logitech|1|$59.54|$59.54|
|http://tinyurl.com/2p9t866m|1-3/8 in. x 36 in. Zinc Steel Punched Flat Bar with 1/16 in. Thick|802037|Everbilt|1|$11.47|$11.47|
|http://tinyurl.com/mryprwj9|Universal Stainless Steel Vertical Pole Mount Adapterwith 3 Loops|Lighfast-SSJK-1P|Lighfast|1|$9.99|$9.99|
|http://tinyurl.com/2nu8f6ph|1/4-20 x 3/4" Button Head Socket Cap Bolts Screws, 304 Stainless Steel 18-8|AB10070201|EastLo|1|$7.99|$7.99|
||||||TOTAL|$169.96|

## References:

[1] Audio File Size Calculations
https://www.audiomountain.com/tech/audio-file-size.html
(accessed Nov. 1, 2023)

[2] microSD Card Benchmarks
https://www.pidramble.com/wiki/benchmarks/microsd-cards
(accessed Nov. 1, 2023)

[3] Scikit-Learn Machine Learning in Python] 
https://scikit-learn.org/stable/
(accessed Jan. 31, 2023)

[4] Volume Reducing Resistor in Speaker Lines
https://electronics.stackexchange.com/questions/278198/volume-reducing-resistor-in-speaker-lines
(accessed Jan 31, 2023)

