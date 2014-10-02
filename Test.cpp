#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include "TargetWeight.h"

using namespace cv;
using namespace std;

int main()
{
	String fname("000005_stage2.png");
	Mat img = imread(fname, 0);
	TargetWeight tw(img);
	int rows, cols; 
	rows = img.rows;
	cols = img.cols;
	cout << "Image's height: " << rows << ", and its width: " << cols << endl;

	// ---------------------------

	Rect roi(200, 200, 150, 70);
	cout << tw.CompBgRatio(roi) << endl;

	// ---------------------------
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", img);
	waitKey();
}