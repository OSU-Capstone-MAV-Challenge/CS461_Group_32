//objectTrackingTutorial.cpp

//Written by  Kyle Hounslow 2013

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software")
//, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//IN THE SOFTWARE.

#include <sstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <objective.h>
#include <vector>
#include <thread>
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
int Cali = 0;
int setter = 1;
using namespace std;


using namespace cv;
//initial min and max HSV filter values.
//these will be changed using trackbars
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string trackbarWindowName = "Trackbars";
void on_trackbar( int, void* )
{//This function gets called whenever a
	// trackbar position is changed
}


string intToString(int number){


	std::stringstream ss;
	ss << number;
	return ss.str();
}


void BorderHSVFunct(int, void*){
		BorderH_MIN = H_MIN;
		BorderH_MAX = H_MAX;
		BorderS_MIN = S_MIN;
		BorderS_MAX = S_MAX;
		BorderV_MIN = V_MIN;
		BorderV_MAX = V_MAX;
		H_MIN = 0;
		H_MAX = 256;
		S_MIN = 0; 
		S_MAX = 256;
		V_MIN = 0; 
		V_MAX = 256;
}

void DelivHSVFunct(int, void*){
		DelivH_MIN = H_MIN;
		DelivH_MAX = H_MAX;
		DelivS_MIN = S_MIN;
		DelivS_MAX = S_MAX;
		DelivV_MIN = V_MIN;
		DelivV_MAX = V_MAX;
		H_MIN = 0;
		H_MAX = 256;
		S_MIN = 0; 
		S_MAX = 256;
		V_MIN = 0; 
		V_MAX = 256;
}
void BlHSVFunct(int, void*){
		BlH_MIN = H_MIN;
		BlH_MAX = H_MAX;
		BlS_MIN = S_MIN;
		BlS_MAX = S_MAX;
		BlV_MIN = V_MIN;
		BlV_MAX = V_MAX;
		H_MIN = 0;
		H_MAX = 256;
		S_MIN = 0; 
		S_MAX = 256;
		V_MIN = 0; 
		V_MAX = 256;
}


void createTrackbars(){
	//create window for trackbars
	namedWindow(trackbarWindowName,0);
	//create memory to store trackbar name on window
	//char TrackbarName[50];
	//sprintf( TrackbarName, "H_MIN", H_MIN);
	//sprintf( TrackbarName, "H_MAX", H_MAX);
	//sprintf( TrackbarName, "S_MIN", S_MIN);
	//sprintf( TrackbarName, "S_MAX", S_MAX);
	//sprintf( TrackbarName, "V_MIN", V_MIN);
	//sprintf( TrackbarName, "V_MAX", V_MAX);
	//create trackbars and insert them into window
	//3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
	//the max value the trackbar can move (eg. H_HIGH), 
	//and the function that is called whenever the trackbar is moved(eg. on_trackbar)
	//                                  ---->    ---->     ---->      
	
	createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, MAX, on_trackbar );
	createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, MAX, on_trackbar );
	createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, MAX, on_trackbar );
	createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, MAX, on_trackbar );
	createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, MAX, on_trackbar );
	createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, MAX, on_trackbar );
	
	
	createTrackbar( "Set Border", trackbarWindowName, &Bordertoggle, setter, BorderHSVFunct);
	createTrackbar( "Set Red Target", trackbarWindowName, &Delivtoggle, setter, DelivHSVFunct);
	createTrackbar( "Set Black Target", trackbarWindowName, &Blacktoggle, setter, BlHSVFunct);
	createTrackbar( "Hide Calibration", trackbarWindowName, &Cali, setter, on_trackbar);
	
}

void drawObject(vector<objective> Targets,Mat &frame){
	for(int i = 0; i < Targets.size(); i++){
		cv::circle(frame,cv::Point(Targets.at(i).getxPos(),Targets.at(i).getyPos()),10,cv::Scalar(0,0,255));
		cv::putText(frame,intToString(Targets.at(i).getxPos())+ " , " + intToString(Targets.at(i).getyPos()),cv::Point(Targets.at(i).getxPos(),Targets.at(i).getyPos()+20),1,1,Scalar(0,255,0));
		cv::putText(frame, Targets.at(i).getType(), cv::Point(Targets.at(i).getxPos(),Targets.at(i).getyPos()-20),1,2,Targets.at(i).getColor());
	}
	
}


void morphOps(Mat &thresh){
	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle
	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
	//dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));
	erode(thresh,thresh,erodeElement);
	erode(thresh,thresh,erodeElement);
	dilate(thresh,thresh,dilateElement);
	dilate(thresh,thresh,dilateElement);
}


void trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed){
	
	vector <objective> borders;
	Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if(numObjects<MAX_NUM_OBJECTS){
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
				if(area>MIN_OBJECT_AREA){
					
					objective border;
					
					border.setxPos(moment.m10/area);
					border.setyPos(moment.m01/area);

					borders.push_back(border);

					objectFound = true;

				}else objectFound = false;


			}
			//let user know you found an object
			if(objectFound ==true){
				//draw object location on screen
				drawObject(borders,cameraFeed);}
		}else putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
	}
}


void trackFilteredObject(objective Targets, Mat threshold,Mat HSV, Mat &cameraFeed){
	
	vector <objective> objects;

	Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if(numObjects<MAX_NUM_OBJECTS){
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
				if(area>MIN_OBJECT_AREA){
					
					objective object;
					
					object.setxPos(moment.m10/area);
					object.setyPos(moment.m01/area);
					object.setType(Targets.getType());
					object.setColor(Targets.getColor());

					objects.push_back(object);

					objectFound = true;

				}else objectFound = false;


			}
			//let user know you found an object
			if(objectFound ==true){
				//draw object location on screen
				drawObject(objects,cameraFeed);}

		}else putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
	}
}


/*
void Calculations(){
	
	
}
*/



//*********************************************************************



int main(int argc, char* argv[])
{
	//if we would like to calibrate our filter values, set to true.
	bool calibrationMode = false;
	bool webcammode = true;
	
//s	std::thread Robotic (Calculations);
	
	
	//Matrix to store each frame of the webcam feed
	Mat cameraFeed;
	Mat threshold;
	Mat HSV;
	UMat HM(threshold.rows, (threshold.cols+cameraFeed.cols), CV_8U);
	string address;

	
	createTrackbars();
	
	//video capture object to acquire webcam feed
	VideoCapture capture;
	if(webcammode){
			//open capture object at location zero (default location for webcam)
			capture.open(0);
	}
	else{
	cout << "Please input the Remote IP address: ";
	cin >> address;
	capture.open("http://" + address + ":8080/?action=stream");
	}	
	
	//set height and width of capture frame
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
	//start an infinite loop where webcam feed is copied to cameraFeed matrix
	//all of our operations will be performed within this loop
	while(1){
		//store image to matrix
		capture.read(cameraFeed);
		//convert frame from BGR to HSV colorspace
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		if(Cali == 0){
		//if in calibration mode, we track objects based on the HSV slider values.
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		inRange(HSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);
		morphOps(threshold);
		imshow(windowName2,threshold);
		trackFilteredObject(threshold,HSV,cameraFeed);
		}else if(Cali == 1 && calibrationMode == false){
			destroyWindow(trackbarWindowName);
			destroyWindow(windowName2);
			calibrationMode = true;
		}
		
			objective border("Border");	// dropoff;
			objective delivery("Delivery");
			
			//Uncomment + duplicate for more objects.
			
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		if(Bordertoggle == 1){	
		inRange(HSV,Scalar(BorderH_MIN,BorderS_MIN,BorderV_MIN),Scalar(BorderH_MAX,BorderS_MAX,BorderV_MAX),threshold);
		}else{
		inRange(HSV,border.getHSVmin(),border.getHSVmax(),threshold);
		}
		morphOps(threshold);
		trackFilteredObject(border, threshold,HSV,cameraFeed);	
		
		
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		if(Delivtoggle == 1){	
		inRange(HSV,Scalar(DelivH_MIN,DelivS_MIN,DelivV_MIN),Scalar(DelivH_MAX,DelivS_MAX,DelivV_MAX),threshold);
		}else{
		inRange(HSV,delivery.getHSVmin(),delivery.getHSVmax(),threshold);
		}
		morphOps(threshold);
		trackFilteredObject(delivery, threshold,HSV,cameraFeed);	
		/*
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		if(Blacktoggle == 1){	
		inRange(HSV,Scalar(BlH_MIN,BlS_MIN,BlV_MIN),Scalar(BlH_MAX,BlS_MAX,BlV_MAX),threshold);
		}else{
		inRange(HSV,border.getHSVmin(),border.getHSVmax(),threshold);
		}
		morphOps(threshold);
		trackFilteredObject(threshold,HSV,cameraFeed);	
		*/
			
		imshow(windowName,cameraFeed);

		//delay 30ms so that screen can refresh.
		//image will not appear without this waitKey() command
		waitKey(30);
	}
	
	return 0;
}




