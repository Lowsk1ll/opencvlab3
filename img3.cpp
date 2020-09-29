#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;
	


int main(int argc, char** argv)
{
 VideoCapture cap(0);
 while(1){
 	Mat img, img1, img2, img3, img4;
 	cap >> img;
 	
 	cvtColor(img,img1,COLOR_BGR2HSV);
 	blur(img, img2, Size(5,5));
 	inRange(img1, Scalar(25,100,20), Scalar(35,255,255), img3);
 	Canny(img,img4,100,100);


 // Check for failure
 if (img.empty()) 
	break;

 imshow("img1", img);

 imshow("img2", img2); 
 
 imshow("img3", img3);
 
 imshow("img4", img4);
 char c = (char)waitKey(25);
	if(c==27)
	break; 
}

	cap.release();
	destroyAllWindows();

 return 0;
}
