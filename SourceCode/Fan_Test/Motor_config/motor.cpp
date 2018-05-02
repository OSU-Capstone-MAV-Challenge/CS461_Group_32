#include <iostream>
#include <wiringPi.h>
//http://wiringpi.com/download-and-install/
#include <softPwm.h>
//http://wiringpi.com/reference/software-pwm-library/
#include <string>
#include <pthread>

using namespace std;

//example for one motor
#define Motor1Pin1    0
#define Motor1Pin2    1
#define Motor1Enable  2



void setup(){
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
		printf("setup wiringPi failed !");
		return 1;
	}
	//setting GPIOS as output
    pinMode(Motor1Pin1, OUTPUT);//pinMode (int pin, int mode) mode: INPUT, OUTPUT, PWM_OUTPUT or GPIO_CLOCK.
	pinMode(Motor1Pin2, OUTPUT);
	pinMode(Motor1Enable, OUTPUT);
}
void take_off(){
    //setting motors to take off the vehicle
    digitalWrite(MotorEnable, HIGH);
    digitalWrite(MotorPin1, HIGH);
    digitalWrite(MotorPin2, LOW);
    //pwmSetRange (unsigned int range) ; This sets the range register in the PWM generator. The default is 1024.
    //pwmSetClock (int divisor) ; This sets the divisor for the PWM clock.
    //pwmWrite(int pin, int value);

}

int main()
{
    setup();
    take_off();

    string command;
    while(1){
            cout << "Move forward -f, Move backward -b, Move up -u, Move down -d, Turn right -r, Turn left -l";
            cout << "Input your command: ";
            getline(cin, command);
            if(command =="f"){
            //setting motors to move helicopter forward
            continue;
            }
            else if(command =="b"){
            //setting motors to move helicopter backward
            continue;
            }
            else if(command =="u"){
            //setting motors to move helicopter up
            continue;
            }
            else if(command =="d"){
            //setting motors to move helicopter down
            continue;
            }
            else if(command =="r"){
            //setting motors to turn helicopter right
            continue;
            }
            else if(commadn =="l"){
            //setting motors to turn helicopter left
            continue;
            }
            else{
            continue;
            }
 }
}
