#pragma once
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class ImgHandler
{
public:
	Rect cut_ref(int x, int y, int width, int heigth);
	Mat place(Mat m1, Mat m2,int x, int y);
	Mat erase(Mat m, int w, int h, int x, int y);
};
