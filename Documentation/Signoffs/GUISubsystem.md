Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Graphical User Interface System

##  Subsystem Functionality

The graphical user interface system is intended to provide a smooth interaction between the user and the exercise bike system. The GUI will take in the weight of the user and the wheel radius of the user. The user will then select the difficulty and trail they would like to replay. The user inputs are used in the calculation of the work map. The weight is used to calculate the force the user can produce, the radius of the wheel is used to reproduce the accurate distance traveled, the difficulty selection is used to scale the work done, and finally the trail selection. These are all put together to send data to the Raspberry Pi for the calculation of the work map for the bike. Lastly, at the end of every trail, a pop-up of the local area will appear informing the user of the location of the trail.

## Constraints 

|Constraint|Description|
|----------|-----------|
|Delay Between Functions|The measured delay between the touch screen and the user input will be no less than 17 ms and no larger than 300 ms.|
|Overexertion Reminder|The amount of time the user can spend exercising can be as little as 0 minutes but can be no longer than 120 minutes without acknowledging the risk of overexertion.|


## Analysis

### Meeting Delay Between Functions Constraint

The measurement delay will be no less than 17 ms since the display specification says that the refresh rate of the display is 60hz which is equivalent to roughly 17 ms, rounding to the nearest whole number [1]. This means that the quickest polling rate of the device is 17 ms seen in Equation (1)

$$ \frac{1}{hz} * 10^3 = ms $$

$$ \frac{1}{60} * 10^3 \approx 17ms \text{  (1)}$$


The highest delay is set at 300 ms because this is said to be nominal for low attention-tapping tasks [2]. The way to ensure it is within this limit is by using pre-existing Python libraries. Python is very versatile and easy to test. Using the GUI libraries already built-in as well as timers will make creating a GUI easy and testing the response speed of the program easy as well. By importing the time library for Python the time a piece of code takes to execute such as the press from the user to the touchscreen. Using this library during the implementation phase of the design will ensure that no one interaction is larger than 300 ms.

Mahtmatically the way to prove that the delay time between the interaction between the user and the system is less than 300ms is to use the CPU Performance Equation [3]. To do this the Total Execution Cycles divided by the count of the instructions (IC) is needed to find the Cycle per Instruction (CPI) shown in Equation (2). Using the IC, CPI equation, and CPU Clock Cycle the time a program takes to execute (CPU Time) can be found shown in Equation (3). Since our max time is 300ms the maximum CPU Cycles that our UI can execute to provide an interaction between the user and a change on the display is 450,000,000 cycles as shown in Equation (4).

$$ \text{CPI} = \frac{\text{Total Execution Cycles}}{IC} \text{  (2)}$$

$$ \text{CPU Time} = \text{IC} * \text{CPI} * \text{CPU Clock Cycle (3)}$$

$$ .3 = IC * \frac{\text{Total Execution Cycles}}{IC} * \text{CPU Clock Cycle} => \text{Total Execution Cycles} = \frac{.3}{\frac{1}{1.5*10^9}} = 450000000 \text{  Cycles  (4)} $$

According to PassMark Software the ARM Cortex-A72 is capable of 6.289 Billion integer operations a second, 3.246 billion floating point operations a second, and a single thread speed of 458 million operations a second. For our purposes that means, 1.886 billion integer operations in 300 ms, 973 million floating point operations in 300 ms, and a single thread speed of 137.4 million operations per 300 ms [4].

### Overexertion Reminder

The overexertion reminder must be given before a 120-minute period has been reached to allow the user to acknowledge the risk of over-exertion. The display will pop up with a warning informing the user that overexertion can lead to injury. Should the user continue past this point, after every trial has been completed the user will be re-informed of the risk associated with overtraining [5].

## References

[1] “Review of the 7” Raspberry Pi Touchscreen Display,” https://tutorials-raspberrypi.com/review-of-the-7-raspberry-pi-touchscreen-display. (accessed Oct 31st, 2023)

[2] W. Ritter, G. Kempter, and T. Werner, User-Acceptance of Latency in Touch Interactions. Cham, CH: Springer International Publishing, 2015.

[3] M. Shaaban. CPU Performance Evaluation [PowerPoint Slides]. Available: http://meseec.ce.rit.edu/eecc550-winter2012/550-12-4-2012.pdf

[4] "ARM Cortex-A72 4 Core 1500 MHz," https://www.cpubenchmark.net/cpu.php?cpu=ARM+Cortex-A72+4+Core+1500+MHz&id=3917. (accessed November 15th, 2023)

[5] K. Jeffery and S. Jennifer, Overtraining syndrome: a practical guide. Sports Health, 2012.

