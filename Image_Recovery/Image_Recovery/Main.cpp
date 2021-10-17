
#include <opencv2/highgui/highgui.hpp>
#include "iostream"
using namespace cv;
using namespace std;
#include "Solution.h"
#include "Gen.h"
using namespace std;
vector<Solution> population;
float fitness_func(vector<Gen> sol, int l, vector<Gen> ref)
{
    float fit = 0;
    for (int i = 0; i < l;i++)
    {
        fit += (abs(sol[i].r - ref[i].r) / static_cast<float>(255) + abs(sol[i].g - ref[i].g) / static_cast<float>(255) + abs(sol[i].b - ref[i].b) / static_cast<float>(255)) / static_cast<float>(3);
    }
    return fit;
   
}
void initPopulation(int lenPopulation, int lenIndividual)
{
    for (int i = 0; i < lenPopulation;i++) {
        Solution s(lenIndividual);
        s.create();
        population.push_back(s);
    }
}

Solution crossover(vector<Gen> parent1, vector<Gen> parent2, const int crossPoint)
{
    Solution offspring(parent2.size());
    int cross = crossPoint;
    for (int i = 0; i < parent1.size();i++) {
        if (i == cross) {
            while (i != cross + crossPoint) {
                if (i > parent1.size()) {
                    break;
                }
                offspring.crossGen(parent2[i]);
                i++;
            }
            i--;
            cross += 2 * crossPoint;
        }
        else {
            offspring.crossGen(parent1[i]);
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
            i.individual()[rand() % i.individual().size()] = Gen(rand() % 255, rand() % 255, rand() % 255);
        }
    }
}
void test(vector<Solution> populaton , vector<Gen> ref ) 
{
    for(auto& p : population)
    {
    
        cout << fitness_func(p.individual(), p.length, ref) << endl;
    }

}
int main() 
{
    srand(time(NULL));
    Mat img = imread("patt3.jpg");
    initPopulation(10,img.rows*img.cols);
    Solution ref(img.rows * img.cols);
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            int b = img.at<Vec3b>(i, j)[0];
            int g = img.at<Vec3b>(i, j)[1];
            int r = img.at<Vec3b>(i, j)[2];
            ref.addGen(r, g, b);
           
            
        }
    }

    Mat image(img.rows, img.cols, CV_8UC3,
        Scalar(255, 255, 255));
   Vec3b value;
   Solution s(img.rows * img.cols);
   s.create();
   vector<Gen> ss =population[9].individual();
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            value = image.at<Vec3b>(row, col);
            value[0]=ref.individual()[row+col].b;
            value[1] = ref.individual()[row + col].g;
            value[2] = ref.individual()[row + col].r;
            image.at<Vec3b>(row, col) = value;
        }
    }

    imshow("TEST", image);
    waitKey(0);
    test(population, ref.individual());
   
	return 0;
}