#include "joystick.h"
void printButton(int);
void printAxis(int);

int main(int argc, char** argv)
{
    Joystick joystick(0);
    if (!joystick.isFound())
    {
        std::cout << "open failed.\n";
        return 1;
    }

    while (true)
    {
        usleep(1000);

        JoystickEvent event;
        
        if (joystick.sample(&event)){
            if(event.ButtonUse()) {
                printButton(static_cast<int>(event.number));
                std::cout << " is " << ( static_cast<int>(event.value) == 0 ? "Released" : "pressed") << '\n'; 
            }
            else if (event.AxisUse()){
                printAxis(static_cast<int>(event.number));
                std::cout << " is at position " << static_cast<int>(event.value) << '\n';            
		}
        }
    }
}

void printButton(int n){
    switch (n){
        case 0: std::cout << "A Button";
                break;
        case 1: std::cout << "B Button";
                break;
        case 2: std::cout << "X Button";
                break;
        case 3: std::cout << "Y Button";
                break;
        case 4: std::cout << "LeftBrumper";
                break;
        case 5: std::cout << "RightBrumper";
                break;
        case 6: std::cout << "View Button";
                break;
        case 7: std::cout << "Menu Button";
                break;
        case 8: std::cout << "Xbox Button";
                break;
        default: std::cout << "Others";
                 break;
    }
}


void printAxis(int n){
    switch (n){
        case 0: std::cout << "LeftStick       Left-Right+       ";
                break;
        case 1: std::cout << "LeftStick       Up-Down+     ";
                break;
        case 2: std::cout << "LeftTrigger     -to+      ";
                break;
        case 3: std::cout << "RightStick      Left-Right+       ";
                break;
        case 4: std::cout << "RightStick      Up-Down+  ";
                break;
        case 5: std::cout << "RightTrigger    -to+      ";
                break;
        case 6: std::cout << "DirectionPad    Left-Right+       ";
                break;
        case 7: std::cout << "DirectionPad    Up-Down+     ";
                break;
        default: std::cout << "Others";
                 break;
    }
}



