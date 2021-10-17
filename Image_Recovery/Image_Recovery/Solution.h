#pragma once
#include <vector>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class Solution {
private:
    Mat solution;
public:
    int length;
    Vec3b getGen(int i, int j);
    Solution(int i, int j);
    void create();
    void crossGen(Vec3b gen);
    void addGen(float r, float g, float b);
    Mat individual();
};


