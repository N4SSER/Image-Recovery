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

Vec3b Solution::getGen(int i,int j)
{
    return solution.at<Vec3b>(i, j);
}

void Solution::crossGen(Vec3b g)
{
    solution.push_back(g);
}

void Solution::addGen(float r, float g, float b)
{
    Vec3b gen(r, g, b);
    solution.push_back(gen);
}

Mat Solution::individual()
{
    return solution;
}