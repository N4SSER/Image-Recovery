
#include <opencv2/opencv.hpp>
#include <iostream> 
#include "ImgHandler.h"
int rows, cols;
int population_len;
int mat_len;
int mutation_rate = 2;
int indx;
bool found = false;
uchar** target;
uchar*** genes, *** n_genes;
int* mat_pool;

using namespace cv;
using namespace std;

struct Individual
{
public:
    float fit;
    int rows, cols;
    int index;

    void fitness_func()
    {
        int cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (genes[index][i][j] == target[i][j])
                    cnt++;
            }
        }
        fit = 1000 * cnt / (rows * cols);
        fit = (fit * fit) / 1000;
    }

    void init(int rw, int cl)
    {
        rows = rw;
        cols = cl;
        index = indx;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                genes[indx][i][j] = rand() % 256;
        indx++;
    }

    Mat individual(Mat img)
    {
        for (int i = 0; i < img.rows; i++)
        {
   
            for (int j = 0; j < img.cols; j++)
            {
                img.at<uchar>(i,j) = genes[index][i][j];
            }
        }
        return img;
    }

    void mutate()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (rand() % 100 < mutation_rate)
                    n_genes[index][i][j] = rand() % 256;
            }
        }
    }
};
Individual* population;
bool s_rule(Individual a, Individual b)
{
    return a.fit > b.fit;
}

void crossover(int place, Individual parent_1, Individual parent_2)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((genes[parent_1.index][i][j] == target[i][j]) || (genes[parent_2.index][i][j] == target[i][j]))
            {
                if (rand() % 10 == 0)
                    n_genes[place][i][j] = target[i][j];
                else
                    goto branch;
            }
            else
            {
            branch:
                if (rand() % 2 == 0)
                    n_genes[place][i][j] = genes[parent_1.index][i][j];
                else
                    n_genes[place][i][j] = genes[parent_2.index][i][j];
            }
        }
    }
}
int main(){
   
    srand(time(NULL));
    ImgHandler imgh;
    Mat ref;
    int x, y;
    Mat mat_cut = imgh.erase(imread("pattern.jpg", 0),100,100,0,0);
    Mat best;
    ref = imread("pattern.jpg",0); //El trozo recortado
    best = ref;
    rows = ref.rows;
    cols = ref.cols;
    namedWindow("Best individual of the generation ",WINDOW_AUTOSIZE);
    target = new uchar * [rows];
    for (int i = 0; i < rows; i++)
    {
        target[i] = new uchar[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        uchar* lin = ref.ptr(i);
        for (int j = 0; j < cols; j++)
        {
            target[i][j] = (uchar)lin[j];
        }
    }
    cin >> population_len;
    mat_pool = new int[population_len * (population_len + 1) / 2];

    genes = new uchar * *[population_len + 10];
    n_genes = new uchar * *[population_len + 10];
    for (int i = 0; i < population_len + 10; i++)
    {
        genes[i] = new uchar * [rows];
        n_genes[i] = new uchar * [rows];
        for (int j = 0; j < rows; j++)
        {
            genes[i][j] = new uchar[cols];
            n_genes[i][j] = new uchar[cols];
        }         
    }   
    population = new Individual[population_len];
    for (int i = 0; i < population_len; i++)
    {
        population[i].init(rows, cols);
        population[i].fitness_func();
    }
    int generations=0;
    while (true)
    {
        generations++;
        for (int i = 0; i < population_len; i++) {
            population[i].fitness_func();
       }
        sort(population, population + population_len, s_rule);
        cout << population[0].fit << endl;
        if (population[0].fit > 999)
        {
            cout << generations << endl;
            break;
        }
  
        imshow("Best individual of the generation ", imgh.place(mat_cut, population[0].individual(best), 0, 0));
        waitKey(1);
        

        mat_len = 0;
     
        for (int i = 0; i < population_len; i++)
        {
            for (int j = 0; j < population_len - i; j++)
            {
                mat_pool[mat_len] = i;
                mat_len += 1;
            }
        }
        for (int i = 0; i < population_len; i++)
        {
            int a = rand() % mat_len, b = rand() % mat_len;
            crossover(i, population[mat_pool[a]], population[mat_pool[b]]);

        }
        for (int i = 0; i < population_len; i++)
            population[i].mutate();
        swap(genes, n_genes);
    }
    delete n_genes;
    delete genes;
    return 0;
}