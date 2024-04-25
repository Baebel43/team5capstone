# Imports
import time
import serial

# Test array
work = [b'350',b'450',b'550',b'600',b'625']
#work = [b'300']

control = serial.Serial('/dev/ttyS0',9600,timeout=0.01)
control.reset_input_buffer()

    # Iterate through array
while True:
    for item in work:
        #time.sleep(1)   
        control.write(item)
