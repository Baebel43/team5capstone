Team 5 - Ride Replay Kit

Team Members: Benjamin Ebel, Jayden Marcom, Jesse Brewster, Caleb Rozenboom, Utsav Singha

# Detail Design: Graphical User Interface System

##  Subsystem Functionality

The graphical user interface system is intended to provide a smooth interaction between the user and the exercise bike system. The GUI will take in the weight of the user and the wheel radius of the user. The user will then select the difficulty and trail they would like to replay. The user inputs are used in the calculation of the work map. The weight is used to calculate the force the user can produce, the radius of the wheel is used to reproduce the accurate distance traveled, the difficulty selection is used to scale the work done, and finally the trail selection. These are all put together to send data to the Raspberry Pi for the calculation of the work map for the bike. Lastly, at the end of every trail, a pop-up of the local area will appear informing the user of the location of the trail.

## Constraints 

|Constraint|Description|
|----------|-----------|
|User Interrupt Priority|The user of the system will have one of the highest interrupt priorities to ensure the interaction of the user will be handled as fast as possible by the system. Should the interaction of the user not be able to be handled in less than 300 ms a window will pop up informing the user that the interaction has been seen.|
|Overexertion Reminder|The amount of time the user can spend exercising can be as little as 0 minutes but can be no longer than 120 minutes without acknowledging the risk of overexertion.|
|Loading Screen| On tasks, such as loading a trail, that are not able to be performed in less than 300 ms there will be a loading bar to inform the user that the task is loading.|
|Color Blindness Sensitive GUI| The GUI will be in a color scheme that is sensitive to color blindness to ensure the system is color-sensitive.|

## Analysis

### Meeting Delay Between Functions Constraint

The User will have one of the highest priority interrupt levels of the system. This is to ensure that the interaction between the user and the system is handled as soon as possible. The reason it is labeled as one of the highest priorities is to account for the chance that a system-critical operation is being executed and in the event of this, a window will pop up informing the user that the input will be handled after the system-critical operation has finished. This is to inform the user that the input has been seen so the user does not repeatedly spam the system with interactions and or get frustrated with the system not responding. By having the user interaction as one of the highest priority interrupts the system will handle the request as fast as the system can and in the event it cannot the user will know that the system has seen it. Using the time library in Python will ensure that the interaction does not take longer than 300 ms without sending an acknowledgment to the user the interaction has been received.

### Overexertion Reminder

The overexertion reminder must be given before a 120-minute period has been reached to allow the user to acknowledge the risk of over-exertion. The display will pop up with a warning informing the user that overexertion can lead to injury. Should the user continue past this point, after every trial has been completed the user will be re-informed of the risk associated with overtraining [1].

### Loading Screen

The loading screen will inform the user a task is loading. Based on the interrupts above, should a user task not be able to execute as soon as a user interacts with the system a loading screen will appear to inform the user their interaction has been seen and is being executed. Keeping the user informed is important in ensuring the user understands what is going on so the user does not become frustrated with the system [2]. 

### Color Blindness Sensitivity

The GUI will be color-blind friendly. It will use a color scheme that can be seen by the three main types of color blindness: complete, red-green, and blue-yellow color blindness. To GUI will be comprised of differing colors of grey to ensure that even a completely color-blind person can see and clearly interact with the GUI [3].

## References

[1] K. Jeffery and S. Jennifer, Overtraining syndrome: a practical guide. Sports Health, 2012.

[2] "User Interface Design Basics," https://www.usability.gov/what-and-why/user-interface-design.html (accessed Nov. 20th, 2023)

[3] "Types of Color Vision Deficiency," https://www.nei.nih.gov/learn-about-eye-health/eye-conditions-and-diseases/color-blindness/types-color-vision-deficiency (accessed Nov. 20th, 2023)
