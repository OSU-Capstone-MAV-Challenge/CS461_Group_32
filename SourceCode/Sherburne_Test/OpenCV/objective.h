#pragma once
#include <string>
using namespace std;


class objective{
public:
	objective(void);
	~objective(void);
	
	int getxPos();
	void setxPos(int x);
	
	int getyPos();
	void setyPos(int y);
	
private:
	
	int xPos, yPos;
	string type;
	
};