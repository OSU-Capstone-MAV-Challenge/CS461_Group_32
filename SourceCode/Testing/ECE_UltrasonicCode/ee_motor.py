from RPIO import PWM
servo1 = PWM.Servo()
servo1.__init__(1, 20000, 10)

MainMotor1 = 3
MainMotor2 = 7
tail = 4
speed1 = 1150
speed2 = 1150
speed3 = 1380
servo1.set_servo(MainMotor1, speed1)
servo1.set_servo(MainMotor2, speed2)
servo1.set_servo(tail, speed3)


loop = 1

while (loop != 0):
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
        speed3 = speed3 + 10
        servo1.set_servo(tail, speed3)

    if command == "tail down":
        speed3 = speed3 - 10
        servo1.set_servo(tail, speed3)

    if command == "shutdown":
        speed1 = 1150
        speed2 = 1150
        speed3 = 1380
        servo1.set_servo(MainMotor1, speed1)
        servo1.set_servo(MainMotor2, speed2)
        servo1.set_servo(tail, speed3)


   

