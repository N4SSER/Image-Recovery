#pragma once
#include <vector>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class Solution {
private:
    Mat solution;

public:

    float fit;

    int length;
    Solution(int i, int j);
    void create();
    void mutate();
    void crossGen(Vec3b gen);
    void setSolution(Mat s);
    Mat individual();
};


