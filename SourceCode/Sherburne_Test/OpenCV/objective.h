#pragma once
#include <string>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;


class objective{
public:
	objective(void);
	~objective(void);
	
	int getxPos();
	void setxPos(int x);
	
	int getyPos();
	void setyPos(int y);
	
	Scalar getHSVmin();
	Scalar getHSVmax();
	
	void setHSVmin(Scalar min);
	void setHSVmax(Scalar max);
	
private:
	
	int xPos, yPos;
	string type;
	
	Scalar HSVmin, HSVmax;
};