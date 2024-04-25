# Ride Replay System 

## Executive Summary

Currently, there are no commercially available devices that officially allow people to ride a personal recording of a trail, Team 5 aims to change this with the Ride Replay Kit. The Ride Replay Kit aims to offer users the ability to replay a trail recorded anywhere with the same difficulty and immersion as if the rider was actually on that trail.


## Capabilities

The Project is able to do the following. For the indoor exercise bike, it is able to take a video and replay it on the trail with the ability to scale the video up and down based on the speed of the user. The Fan attached to the front of the indoor exercise bike will also scale with the user's speed. The outdoor bike that will have the ride replay kit attached is able to take in elevation data in after every full rotation of the back wheel. The full rotations are taken when the magnet attached to the spoke passes by the hall effect sensor attached to the back of the bike. This data is then saved to a text file and it can then be turned into a byte array for use inside the linear actuator code. The outdoor bike also has the ability to record audio from the microphone and store it on the Raspberry Pi. The Arduino IOT devices have the ability to communicate the weight input from the load cells and send them to the main controller Arduino IOT, these will be label so that future teams can know which is the slave and which is the master.

## Salient Outcomes

Being able to run the User Interface, the code to scale the video, the fan scale code, and the tachometer at the same time. Additionally the ability to use previous teams raspberry pi to record audio and a workmap accurately.

## Project Demonstration & Images

Minimally Functional Prototype link - https://youtu.be/p_Y5p9GWvbA

Ride Replay Kit - https://youtube.com/watch?v=LAPSdsN-WzQ&feature=shared

Final Trail Recording - https://www.youtube.com/shorts/GgyuamzpSRI

Exercise Bike Test - https://www.youtube.com/shorts/0spRPyzmJK8

## About Us

### Team 5
Team 5 is a six-person Fall 2023 to Spring 2024 Capstone Design team comprised of 5 Electrical Engineers and 1 Computer Engineers. The Team includes: Utsav Singa, Caleb Rozenboom, Jayden Marcom, Jesse Brewster, Caleb Turney, and Benjamin Ebel

#### Utsav Sigha
* Electrical Engineering Major
* Video System
* Video Software/Hardware

#### Caleb Rozenboom
* Electrical Engineering Major
* Resistance System
* Hardware

#### Jayden Marcom
* Electrical Engineering Major
* Work System
* Hardware

#### Jesse Brewster
* Electrical Engineering Major
* Audio System
* Audio Software/Hardware

#### Caleb Turney
* Electrical Engineering Major
* Immersion System
* Immersion Software and Hardware

#### Ben Ebel
* Computer Engineering Major
* GUI System
* Software/Coding in Python and C

### Faculty Supervisor

Professor Jesse Roberts of the Electrical and Computer Engineering Department of Tennessee Technological University.

### Stakeholders

The consumers of this project are mountain biking enthusiasts, exercise bicycle enthusiasts, and any person interested in an escape to a faraway place without the time or finances to do so. 

### Recognitions
* Jesse Roberts​
* Conard Murray​
* Jeff Randolph ​
* Jeffrey Austen​
* Sterling Sloan

## Repo Organization

This GitHub is comprised of 3 main files: Documentation, Reports, and Software.

### Reports

In the reports section of this repository information about the individual expectations for the reports and how they should be housed is provided.

### Documentation

In the documentation section information regarding the documentation that is required and how it should be organized is given.

### Software

In the software directory of the repo information regarding how each team is expected to document software can be found.
