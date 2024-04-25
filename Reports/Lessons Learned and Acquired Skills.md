# Lessons Learned

This document should have a section for each team member. Each engineer should respond to these:

- Reflect on the project, both technical and organizational. What went well? What didn’t go well? 
- What unanticipated problems occurred? 
- What would you do differently if you were to do it over again? 
- What “best practices” have you identified? 
- What words of wisdom would you pass on to future students?
- What new knowledge or skills did you acquire throughout capstone.

Create a subsection addressing each of the above questions in your section of the document. 

# Jayden Marcom
  For my subsystem most things went well the only thing that didn't go well is the accuracy of the pressure sensor. The pressure sensor is currently inaccurate by about 3 feet and I believe that could be further improved. Some unanticipated problems that occured is the idea of what should happen if there was a perfectly flat trail recording. Currently there is no set solution to the problem since it's purely hypothetical, but since the user on the bike and on the trail would just have to pedal the bike the back actuator shouldn't place any resistance on the back flywheel. If I were to go back and do it over again I would spend more time reviewing the previous teams work and understanding what exactly they were trying to do with specific systems. The best practice that I have identified are keeping backups of everything. You never know when you might need it. The words of wisdom I would like to relay is always be willing to help your teammates since later on they would be willing to help you. Some new knowledge that I aquired during capstone is teamwork, B field calculations, python coding, coding on an ubuntu interface, and many mathematical concepts. 

# Ben Ebel 
The creation of the GUI and implementation both went well and didn’t go well and was the main struggle for me. The GUI started out working but when it came time to implement the scaling code for the video it was tough to do. So tough in fact that I switched GUI libraries and ended up using multi threading to do so. However, in doing this it made the interaction with the GUI and the user very seamless. 

Dealing with infinite loops was the hardest part of my systems. It was eventually fixed with the use of the threading library in Python but this was a headache to deal with before discovering threading.

I would do better research on the previous team’s implementation. There were multiple times where our group assumed that the past group had actually got a system working but it then turned out that only half the system worked. So I would do more research in general.

I think the best practices are to research and try to find others who have done what you are trying to do or something similar to what you are trying to do.

I would suggest to them that they do more research on their topic before choosing. Always do more research than you think, whether that be into a topic you’re basing your system off or a topic other people are basing their system off because it could come to bite you.

I learned a lot about how to code in Python and interface with raspberry pis. I also learned a lot about how to function in a team dynamic. Additionally, I learned to always be prepared for the worst case scenario because almost nothing is going to work how you think it will and you will have to learn how to be on your feet.

# Jesse Brewster
  My subsystem was the audio subsystem, and overall the audio was successfully played back in accordance to the work done by the user on the exercise bike. So the basis of the experiment was completed. However what I hoped to accomplish was to divide the trail audio file into audio sections based upon commonly occurring frequencies such as a waterfall, and to loop these sections until the user progressed past them. This was not able to be accomplished due to the incompatibility of the machine learning software with the Raspberry Pi, more specifically the Python Libraries were not compatible. An unanticipated problem occurred whenever I had completed the audio code on my personal computer with the audio succesfully playing, but when I transferred the code to the Raspberry Pi the code had trouble working because it was originally designed to work on a Windows based system, not a Linux based system that was loaded onto the Raspberry Pi. 
  
  If I were to do this again, I would have done more testing with the Raspberry Pi itself to more fully understand how to make the Python code works and to fix any problems that arose. The best practice I learned was to always ask for help when needed and always be willing to help other group members when possible. This creates a better work environment and a willingness to accompish goals collaboratively. For the future, I would recommend groups to continue working hard and never give up because there are others in your same position who can help you. Also, taking on a third iteration of a project can be challenging because you have to review two other preious groups work and identify what worked well and what didn't, then use the devices they chose to buy instead of your own. A new skill I learned was how to program in Python, working with linux-based system, and how to process and divide audio files just through coding.
﻿
