#include "Solution.h"


Solution::Solution(int i, int j)
{
    Mat sol(i,j,CV_8UC3, Scalar(255, 255, 255));
    this->solution = sol;
}
void Solution::create() 
{
    Vec3b gen;
    for (int i = 0; i < solution.rows;i++)
    {
        for (int j = 0; j < solution.cols;j++) 
        {
            
            gen[0] = rand() % 255;
            gen[1] = rand() % 255;
            gen[2] = rand() % 255;
            solution.at<Vec3b>(i, j) = gen;
        }
    }
}
void Solution::mutate()
{
    int mrate = rand() % 10;
    for (int i = 0; i < solution.rows; i++)
    {
        for (int j = 0; j < solution.cols; j++)
        {
            if (rand() % 10 < mrate)
                solution.at<Vec3b>(i,j)[2] = rand() % 256;
                solution.at<Vec3b>(i,j)[1] = rand() % 256;
                solution.at<Vec3b>(i,j)[0] = rand() % 256;
        }
    }
}

void Solution::crossGen(Vec3b g)
{
    solution.push_back(g);
}

void Solution::setSolution(Mat s)
{
    solution = s;
}

Mat Solution::individual()
{
    return solution;
}