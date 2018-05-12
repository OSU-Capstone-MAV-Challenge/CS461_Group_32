# Project Part

Get input from xbox controller.

## Getting Started

1.      Connect xbox controller to laptop/desktop with usb.
2.      buttonView.txt is a file record the button number and the actual button on xbox controller.
 
### Prerequisites

xbox controller model 1708
ubuntu 16 or above
c++ compiler    (Codes are in c++)
package:        jstest-gtk
cmake

### Installing

Download following files into the same folder:
joystick.h
joystick.cpp
main.cpp
makefile

## Running the tests

Simply type make in the terminal.
$make

## Reference

* [ButtonView](https://support.xbox.com/en-US/xbox-one/accessories/xbox-one-wireless-controller) - get to know your xbox controller
* [Joystick API Documentation](https://www.kernel.org/doc/Documentation/input/joystick-api.txt)
* [GitHub](https://github.com/drewnoakes/joystick/blob/master/joystick.hh) - joystick.h
