#include "Refimg.h"
#include "iostream"
#include <opencv2/highgui/highgui.hpp>
Rect Refimg::CutRef(int x, int y, int witdh, int hiegtgh) 
{
	Rect croppedimg = Rect(x, y, witdh, hiegtgh);
	return croppedimg;
}
