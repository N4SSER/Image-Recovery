
#include <opencv2/highgui/highgui.hpp>
#include "iostream"
#include "Solution.h"
using namespace cv;
using namespace std;
vector<Solution> population;
float fitness_func(Mat sol, Mat ref)
{
    float fit = 0;
    for (int i = 0; i < sol.rows;i++)
    {
        for (int j = 0; j < sol.cols;j++) 
        {
            Vec3b sGen = sol.at<Vec3b>(i, j);
            Vec3b rGen = ref.at<Vec3b>(i, j);
            fit += (abs(sGen[2] - rGen[2]) / static_cast<float>(255) + abs(sGen[1] - rGen[1]) / static_cast<float>(255) + abs(sGen[0] - rGen[0]) / static_cast<float>(255)) / static_cast<float>(3);
            
        }
       
    }
    cout<<fit<<endl;
    return fit;
   
}
void initPopulation(int lenPopulation, int i, int j)
{
    for (int c = 0; c < lenPopulation;c++) {
        Solution s(i,j);
        s.create();
        population.push_back(s);
    }
}

Solution crossover(Solution parent1, Solution parent2, const int crossPoint)
{
    Solution offspring(parent1);
    Vec3b val;
    int cross = crossPoint;
    for (int i = 0; i < parent1.individual().rows;i++)
    {
        for (int j = 0; j < parent1.individual().cols; j++)
        {
            if (i == cross) {
                while (i != cross + crossPoint) {
                    if (i > parent1.individual().rows * parent1.individual().cols) {
                        break;
                    }
                    offspring.crossGen(parent2.getGen(i, j));
                    i++;
                }
                i--;
                cross += 2 * crossPoint;
            }
            else {
                offspring.crossGen(parent2.getGen(i, j));
            }
        }
       
    }
    return offspring;
}
void mutate() 
{
    int mValue;
    for (auto& i : population) {
        mValue = rand() % 1000;
        if (mValue == 1) {
            Vec3b val(rand() % 255, rand() % 255, rand() % 255);
            i.getGen(rand() % i.individual().rows, rand() % i.individual().cols) = val;
        }
    }
}
void test(vector<Solution> populaton , Mat ref ) 
{
    for(auto& p : population)
    {
        fitness_func(p.individual(), ref);
    }

}
int main() 
{
   srand(time(NULL));
   Mat ref = imread("lena.jpg");

   Mat sol(ref.rows, ref.cols, CV_8UC3,
   Scalar(255, 255, 255));
   Vec3b value;
   Solution s(ref.rows, ref.cols);
   s.create();
    for (int row = 0; row < sol.rows; row++) {//Write image
        for (int col = 0; col < sol.cols/3; col++) {
            value = ref.at<Vec3b>(row, col);
            value[0] = rand()%255;
            value[1] = rand() % 255;
            value[2] = rand() % 255;
            ref.at<Vec3b>(row, col) = value;
        }
    }

    imshow("TEST", ref);
    initPopulation(10, ref.rows, ref.cols);
    test(population, ref);
    waitKey(0);
   
	return 0;
}