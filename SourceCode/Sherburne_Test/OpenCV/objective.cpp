#include "objective.h"

objective::objective(void){
}

objective::~objective(void){
}

objective::objective(string name){ //Duplicate this for more objects
	setType(name);
	if( name == "Border" ){
			setHSVmin(Scalar(14,164,121));
			setHSVmax(Scalar(186,237,180));
			setColor(Scalar(0,250,250));
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
