CC = g++
exe_file = run
$(exe_file):main.o joystick.o 
	$(CC) -g main.o joystick.o -o  $(exe_file)
main.o : main.cpp
	$(CC) -c main.cpp
joystick.o  : joystick.cpp
	$(CC) -c joystick.cpp

	
clean:
	rm -f *.out *.o $(exe_file)
