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
			setHSVmin(Scalar(160,255,255));
			setHSVmax(Scalar(197,255,255));
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
	if(borderToggle == 1 && name == "Border"){
		return Scalar(BorderH_MIN,BorderS_MIN,BorderV_MIN);
	}else if(DelivToggle == 1 && name == "Delivery"){
		return Scalar(DelivH_MIN,DelivS_MIN,DelivV_MIN);
	}else if(BlackToggle == 1 && name == "Black"){
		return Scalar(BlH_MIN,BlS_MIN,BlV_MIN);
	}else
	return HSVmin;
}


Scalar objective::getHSVmax(){
	if(borderToggle == 1 && name == "Border"){
		return Scalar(BorderH_MAX,BorderS_MAX,BorderV_MAX);
	}else if(DelivToggle == 1 && name == "Delivery"){
		return Scalar(DelivH_MAX,DelivS_MAX,DelivV_MAX);
	}else if(BlackToggle == 1 && name == "Black"){
		return Scalar(BlH_MAX,BlS_MAX,BlV_MAX);
	}else
	return HSVmax;
}
	
void objective::setHSVmin(Scalar min){
	objective::HSVmin = min;
}


void objective::setHSVmax(Scalar max){
	objective::HSVmax = max;
}
