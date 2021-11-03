#include "ImgHandler.h"

Mat ImgHandler::cut_ref(Mat m, int x, int y, int width, int heigth)
{
	Rect ROI(x, y, width, heigth);
	return m(ROI);
}

Mat ImgHandler::place(Mat m1, Mat m2, int x, int y)
{

	for (int i = x; i < m2.rows + x;i++)
	{
		for (int j = y;j < m2.cols + y;j++)
		{
			m1.at<Vec3b>(i, j) = m2.at<Vec3b>(i-x, j-y);
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
			m.at<Vec3b>(i, j)[0] = 255;
			m.at<Vec3b>(i, j)[1] = 255;
			m.at<Vec3b>(i, j)[2] = 255;	
		}
		
	}
	return m;
}