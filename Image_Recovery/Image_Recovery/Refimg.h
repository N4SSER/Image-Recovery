#pragma once
#include <opencv2/highgui/highgui.hpp>
#include "iostream"
using namespace cv;
class Refimg
{
public:
	Rect CutRef(int x, int y, int width, int heigth);
};

