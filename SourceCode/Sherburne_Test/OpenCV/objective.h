#pragma once
#include <string>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int H_MIN = 0, S_MIN = 0, V_MIN = 0; 
int H_MAX = 256, S_MAX = 256, V_MAX = 256;
int BorderH_MIN = 0, BorderS_MIN = 0, BorderV_MIN = 0; 
int BorderH_MAX = 256, BorderS_MAX = 256, BorderV_MAX = 256;
int DelivH_MIN = 0, DelivS_MIN = 0, DelivV_MIN = 0; 
int DelivH_MAX = 256, DelivS_MAX = 256, DelivV_MAX = 256;
int BlH_MIN = 0, BlS_MIN = 0, BlV_MIN = 0; 
int BlH_MAX = 256, BlS_MAX = 256, BlV_MAX = 256;
int MAX = 256;
int Bordertoggle = 0;
int Delivtoggle = 0;
int Blacktoggle = 0;

class objective{
public:
	objective(void);
	~objective(void);
	
	objective(string name);
	
	int getxPos();
	void setxPos(int x);
	
	int getyPos();
	void setyPos(int y);
	
	Scalar getHSVmin();
	Scalar getHSVmax();
	
	void setHSVmin(Scalar min);
	void setHSVmax(Scalar max);
		
	string getType(){return type;}
	void setType(string t){type = t;}
	Scalar getColor(){return Color;}
	void setColor(Scalar c){
		Color = c;
	}
	
	
private:
	
	int xPos, yPos;
	string type;
	Scalar HSVmin, HSVmax;
	Scalar Color;
};