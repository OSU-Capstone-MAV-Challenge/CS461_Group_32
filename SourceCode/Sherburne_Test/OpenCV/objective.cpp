#include "objective.h"

objective::objective(void){
}

objective::~objective(void){
}

objective::objective(string name){ //Duplicate this for more objects
	setType(name);
	if( name == "Border" ){
			setHSVmin(Scalar(12,150,111));
			setHSVmax(Scalar(186,255,255));
			setColor(Scalar(0,250,250));
	}
	if( name == "Delivery" ){
			setHSVmin(Scalar(5,11,159));
			setHSVmax(Scalar(27,68,207));
			setColor(Scalar(0,0,250));
	}
	if( name == "L.Z." ){
			setHSVmin(Scalar(0,0,242));
			setHSVmax(Scalar(75,255,255));
			setColor(Scalar(250,250,0));
	}
	
	
}


int objective::getxPos(){
	 return objective::xPos;
}

void objective::setxPos(int x){
	objective::xPos = x;	
}


int objective::getyPos(){
	 return objective::yPos;
}

void objective::setyPos(int y){
	objective::yPos = y;
}

Scalar objective::getHSVmin(){
	return HSVmin;
}


Scalar objective::getHSVmax(){
	return HSVmax;
}
	
void objective::setHSVmin(Scalar min){
	objective::HSVmin = min;
}


void objective::setHSVmax(Scalar max){
	objective::HSVmax = max;
}
