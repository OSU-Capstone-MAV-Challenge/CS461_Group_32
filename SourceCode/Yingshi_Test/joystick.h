#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
#include <unistd.h>


#define JS_EVENT_BUTTON 0x01 // 0000,0001 = 1   button pressed/released
#define JS_EVENT_AXIS   0x02 // 0000,0010 = 2   joystick moved
#define JS_EVENT_INIT   0x80 // 1000,0000 = 128 initial state of device

class JoystickEvent
{
public:
  static const short MIN_AXES_VALUE = -32768;/*2 bytes -32768 to 32767*/
  static const short MAX_AXES_VALUE = 32767;/*2 bytes -32768 to 32767*/
  unsigned int time;    /*4 bytes 0 to 4294967295*/ 
  short value;          /*2 bytes -32768 to 32767*/
  unsigned char type;   /*1 byte  0 to 255*/
  unsigned char number; /*1 byte  0 to 255*/
  
  bool ButtonUse()  {    return (type & JS_EVENT_BUTTON) != 0;  }
  bool AxisUse()  {    return (type & JS_EVENT_AXIS) != 0;  }
  bool isInitialState()  {    return (type & JS_EVENT_INIT) != 0;}
};
  //friend std::ostream& operator<<(std::ostream& os, const JoystickEvent& use);};

/*
std::ostream& operator<<(std::ostream& os, const ClassName& use){};
== cout << use << endl;
*/
std::ostream& operator<<(std::ostream& os, const JoystickEvent& use);

class Joystick
{
private:
  int fd;
  void openPath(std::string devicePath, bool blocking=false);
  
public:
  ~Joystick();
  Joystick();
  Joystick(int joystickNumber);/*To use when there are more than one joystick*/
  //Joystick(Joystick const&) = delete;
  //Joystick(Joystick &&) = default;
  Joystick(std::string devicePath);
  Joystick(std::string devicePath, bool blocking);
  bool isFound();
  bool sample(JoystickEvent* event);
};

#endif
