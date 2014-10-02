#pragma once

#include <opencv2/opencv.hpp> 

using namespace cv;
using namespace std;

class TargetWeight
{
public:
	TargetWeight();
	TargetWeight(Mat & background);
	~TargetWeight();

public:
	/* Evaluate the probability of roi */
	double Eval(Rect roi); 

	/* Background subtraction */
	Mat CompBgMask(Mat im);


//private:
public:
	/* Compute the pdf of trained GMM */
	double CompGMM();

	/* Compute the probability of background in roi */
	double CompBgRatio(Rect roi);

private:
	Mat mBgMask;


};

