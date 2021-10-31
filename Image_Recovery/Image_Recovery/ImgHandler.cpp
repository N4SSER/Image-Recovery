#include "ImgHandler.h"
#include <iostream>

Rect ImgHandler::cut_ref(int x, int y, int width, int heigth)
{
	Rect croppedimg = Rect(x, y, width, heigth);
	return croppedimg;
}

Mat ImgHandler::place(Mat m1, Mat m2, int x, int y)
{

	for (int i = x; i < m2.rows + x;i++)
	{
		for (int j = y;j < m2.cols + y;j++)
		{
			m1.at<uchar>(i, j) = m2.at<uchar>(i-x, j-y);
		}

	}
	return m1;
}

Mat ImgHandler::erase(Mat m, int w, int h, int x, int y)
{
	for (int i = x; i < w+x ;i++)
	{
		for (int j = y;j< h+y ;j++) 
		{
		
			m.at<uchar>(i, j) = 255;
			
		}
		
	}
	return m;
}
