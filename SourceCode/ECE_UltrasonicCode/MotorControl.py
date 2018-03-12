import smbus
import math
import time
import socket
import threading
from smbus import SMBus
from time import sleep
#import RPIO 
#RPIO.setup(16, RPIO.OUT)
#RPIO.setup(20, RPIO.OUT)
#RPIO.setup(21, RPIO.OUT)
#RPIO.output(16, True)
#RPIO.output(20, False)
#RPIO.output(21, True)

from RPIO import PWM
i2cbus = SMBus(1)
servo1 = PWM.Servo()
servo1.__init__(1, 20000, 10)

move = 0
valh = 0
MainMotor1 = 8 
MainMotor2 = 7
tail = 4
speed1 = 1150
speed2 = 1150
speed3 = 0
servo1.set_servo(MainMotor1, speed1)
servo1.set_servo(MainMotor2, speed2)
#servo1.set_servo(tail, speed3)

def process():
    global speed1
    global speed2
    global valh
    while (True):
        i2cbus.write_byte(0x70, 0x51)
        sleep(0.12)
        val = i2cbus.read_word_data(0x70, 0xe1)
        height = (((val & 0x00ff) << 8 ) | ((val & 0xff00) >> 8)) - 32767 
        time.sleep(0.5)
        
        #if height > 500: 
            #speed1 = speed1 - 10
            #speed2 = speed2 - 10
            #servo1.set_servo(MainMotor1, speed1)
            #servo1.set_servo(MainMotor2, speed2)

        if move == 1:
            if val > valh:
                speed1 = speed1 - 10
                speed2 = speed2 - 10
                servo1.set_servo(MainMotor1, speed1)
                servo1.set_servo(MainMotor2, speed2)
            
            if val < valh:
                speed1 = speed1 + 10
                speed2 = speed2 + 10
                servo1.set_servo(MainMotor1, speed1)
                servo1.set_servo(MainMotor2, speed2)


thread = threading.Thread(target=process)
thread.daemon = True
thread.start()


while (True):
    command = raw_input("Enter command:")

    if command == "1 up":
        speed1 = speed1 + 10
        servo1.set_servo(MainMotor1, speed1)

    if command == "1 down":
        speed1 = speed1 - 10
        servo1.set_servo(MainMotor1, speed1)

    if command == "2 up":
        speed2 = speed2 + 10
        servo1.set_servo(MainMotor2, speed2)

    if command == "2 down":
        speed2 = speed2 - 10
        servo1.set_servo(MainMotor2, speed2)

    if command == "tail up":
        speed3 = speed3 + 1000
        
    #    if speed3 > 0:
 #           RPIO.output(20, False)
  #          RPIO.output(21, True)
        
  #      servo1.set_servo(tail,abs(speed3))

    if command == "tail down":
        speed3 = speed3 - 1000
        
     #   if speed3 < 0:
   #         RPIO.output(20, True)
    #        RPIO.output(21, False)
            
   #     servo1.set_servo(tail, abs(speed3))

    if command == "both up":
        speed1 = speed1 + 10
        speed2 = speed2 + 10
        servo1.set_servo(MainMotor1, speed1)
        servo1.set_servo(MainMotor2, speed2)

    if command == "both down":
        speed1 = speed1 - 10
        speed2 = speed2 - 10
        servo1.set_servo(MainMotor1, speed1)
        servo1.set_servo(MainMotor2, speed2)

    
    if command == "shutdown":
        speed1 = 1150
        speed2 = 1150
        speed3 = 0
        servo1.set_servo(MainMotor1, speed1)
        servo1.set_servo(MainMotor2, speed2)
        servo1.set_servo(tail, speed3)
    
    if command == "spin":
        speed1 = 1230
        speed2 = 1230
        servo1.set_servo(MainMotor1, speed1)
        servo1.set_servo(MainMotor2, speed2)

    if command == "hold":
        move = 1
        valh = i2cbus.read_word_data(0x70, 0xe1)

    if command == "move":
        move = 0

