#include "joystick.h"

Joystick::~Joystick(){  close(fd);}

Joystick::Joystick(){  openPath("/dev/input/js0");}

Joystick::Joystick(int joystickNumber){
  std::stringstream str;    /*typedef basic_stringstream<char> stringstream*/
  str << "/dev/input/js" << joystickNumber;
  openPath(str.str());
}

Joystick::Joystick(std::string devicePath){  
    openPath(devicePath);
}

Joystick::Joystick(std::string devicePath, bool blocking){  
    openPath(devicePath, blocking);
}

bool Joystick::isFound(){  return fd >= 0;}

bool Joystick::sample(JoystickEvent* event){
  int bytes = read(fd, event, sizeof(*event)); 
  if (bytes == -1)  return false;
  return bytes == sizeof(*event);
}
/*
requires #inlcude <fcntl.h>
*/
void Joystick::openPath(std::string devicePath, bool blocking){
  fd = open(devicePath.c_str(), blocking ? O_RDONLY : O_RDONLY | O_NONBLOCK);
}

/*
cout << "   type=  " << use.type <<< "   number= " << use.number << "   value= " << use.value << endl;
std::ostream& operator<<(std::ostream& os, const JoystickEvent& use){
  os << "   type=   "  << static_cast<int>(use.type)
     << "   number= "    << static_cast<int>(use.number)
     << "   value=  " << static_cast<int>(use.value);
  return os;
}

*/

