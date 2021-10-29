
#include <opencv2/highgui/highgui.hpp>
#include "iostream" 
#include "Solution.h"
int frows, fcols;
int plen,ppn;
int mrate = 2;
int c_index;
bool found = false;
int* mpool;
using namespace cv;
using namespace std;
vector<Solution> population;
vector<Solution> ppl;



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
    return fit;
}


int Partition(vector<Solution>& v, int start, int end)
{

    int pivot = end;
    int j = start;
    for (int i = start;i < end;++i) 
    {
        if (v[i].fit < v[pivot].fit) 
        {
            swap(v[i], v[j]);
            ++j;
        }
    }
    swap(v[j], v[pivot]);
    return j;

}

vector<Solution> sort(vector<Solution>& v, int start, int end)
{

    if (start < end)
    {
        int p = Partition(v, start, end);
        sort(v, start, p - 1);
        sort(v, p + 1, end);
    }
    return v;

}


void initPopulation(int lenPopulation, int i, int j)
{
    for (int c = 0; c < lenPopulation;c++)
    {
        Solution s(i,j);
        s.create();
        population.push_back(s);
    }
}

void crossover(int indx,Solution parent1, Solution parent2,Mat best)
{
    Solution offspring(best.rows, best.cols);
    for (int i = 0; i < best.rows; i++)
    {
        for (int j = 0; j < best.cols; j++)
        {
            if ((parent1.individual().at<Vec3b>(i, j) == best.at<Vec3b>(i, j)) ||(parent2.individual().at<Vec3b>(i, j) == best.at<Vec3b>(i, j)))
            {
                if (rand() % 10 == 0)
                    offspring.individual().at<Vec3b>(i, j) = best.at<Vec3b>(i, j);
                else
                    goto branch;
            }
            else
            {
            branch:
                if (rand() % 2 == 0)
                   offspring.individual().at<Vec3b>(i, j) = parent1.individual().at<Vec3b>(i, j);
                else
                    offspring.individual().at<Vec3b>(i, j) = parent2.individual().at<Vec3b>(i, j);
            }
        }
    }
    population.push_back(offspring);
}


int main() 
{
   srand(time(NULL));
   Mat target = imread("pattern.jpg");
   ppn = 10;
   initPopulation(ppn, target.rows, target.cols);
   mpool = new int[ppn * (ppn + 1) / 2];
   int gen=60000;
   while (gen>0)
   {
       for (auto& p : population)
       {
           p.fit = (fitness_func(p.individual(), target));
       }

       ppl=sort(population, 0, 0);
       population.clear();
       cout << ppl[0].fit << endl;
       imshow("Best",ppl[0].individual());
       waitKey(1);
       plen = 0;
       for (int i = 0; i < ppn; i++)
       {
           for (int j = 0; j < ppn - i; j++)
           {
               mpool[plen] = i;
               plen += 1;
           }
       }
       for (int i = 0; i < ppn; i++)
       {
           int a = rand() % plen, b = rand() % plen;
           crossover(i, ppl[mpool[a]], ppl[mpool[b]], target);
       }
       for (int i = 0; i < ppn; i++) {
           population[i].mutate();
       }
       ppl.clear();
       gen--;
         
   }
    
	return 0;
}