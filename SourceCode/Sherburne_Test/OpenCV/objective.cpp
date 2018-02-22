#include "objective.h"

objective::objective(void){
}

objective::~objective(void){
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
