import os
import time
import serial
import numpy as np

control = serial.Serial('/dev/ttyS0',9600,timeout=0.01)
control.reset_input_buffer()

u = 4*np.pi*10**-7
V = 1.287*10**-5
Br = 14800
circ = 13.5*2*np.pi
m = Br*V/u
M = m/V
d_array = np.array([])
ac_array = np.array([])
work_array= np.array([])
altitude_array = np.array([])
i = 0
x = 0
#j=0

#file="WorkMapTest.txt"
#data = np.loadtxt("WorkMapTest.txt", dtype= float, delimiter = ",")

data = np.loadtxt("fake_data.txt", dtype= float, delimiter = ",")

for i in data:
    d_array = np.append(d_array,(((3*u/2*np.pi)*(M**2)*(V**2)*circ)/i)**.25)
#for i in data:
    #altitude_array = np.append(altitude_array, ([i+1]*7.888017)-i*7.888017)
for x in d_array:
    ac_array = np.append(ac_array, x/.1068)

#for j in altitude_array:
    #work_array = np.append(work_array, ((j*177)*9.81))


print("Original Data: ", data)
print("D_Array Data: ", d_array)
print("AC_Array Data: ", ac_array)
#print("Altitude_Array Data: ", altitude_array)
#print("Work_Array Data: ", work_array)
while True:
    for item in ac_array:
        if item > 900:
            print("Too large")
            time.sleep(5) 
        else:
            itme = b'item'
            time.sleep(5)   
            control.write(item)

