#include "TargetWeight.h"


TargetWeight::TargetWeight()
{
}

TargetWeight::TargetWeight(Mat & background)
{
	mBgMask = background;
}

TargetWeight::~TargetWeight()
{
}

double TargetWeight::Eval(Rect roi)
{
	return CompBgRatio(roi) * CompGMM();
}


double TargetWeight::CompBgRatio(Rect roi)
{
	Mat tIm(mBgMask, roi);
	int counter = 0;
	
	cout << tIm.cols << "," << tIm.rows << endl;
	/*namedWindow("image", CV_WINDOW_AUTOSIZE);
	waitKey();
	imshow("image", tIm);*/
	double minval, maxval;
	minMaxLoc(tIm, &minval, &maxval);
	cout << minval << ", " << maxval << endl;
	int thres = 80;
	for (int i = 0; i < tIm.rows; i++)
	{
		for (int j = 0; j < tIm.cols; j++)
		{
			/*cout << i << "," << j << ": ";
			cout << (int)tIm.at<unsigned char>(i, j) << "\t";*/
			if ((int)tIm.at<unsigned char>(i, j) < thres) // filter the background
			{
				counter++;
			}
		}
	}

	return 1 - (double)(counter) / (tIm.rows * tIm.cols);
}

double TargetWeight::CompGMM()
{
	return 0;
}

Mat TargetWeight::CompBgMask(Mat im)
{
	return im;
}

