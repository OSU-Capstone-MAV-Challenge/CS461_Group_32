all: 
	g++ -w -ggdb -pthread -std=c++11 -I. example.cpp objective.cpp -o Vision `pkg-config --cflags --libs opencv`


clean: 
	rm -fr Vision
