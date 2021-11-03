
/**
 * @file Main.cpp
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Funcion main 
 * @brief Contiene la funcion main 
 * @date 11/3/2021
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImgHandler.h"
int rows, cols;
int c_x, c_y;
int population_len;
int mat_len;
int mutation_rate = 2;
int indx;
bool found = false;
Vec3b** target;
Vec3b*** genes, *** n_genes;
int* mat_pool;

using namespace cv;
using namespace std;
/** @struct Individual
 *  @brief Esta es una estructura que posee las caracterisiticas de los individuos ademas posee diversas funcionalidades
 * @authors  Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 */
struct Individual
{
public:
    float fit;
    int rows, cols;
    int index;
    /** 
 * @brief Este metodo contiene la funcionalidad de encontrar el fitness de cada individuo.
 * @authors  Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 *
 */
    void fitness_func()
    {
        int cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (genes[index][i][j][0] == target[i][j][0] || genes[index][i][j][1] == target[i][j][1] || genes[index][i][j][2] == target[i][j][2]  )
                    cnt++;
            }
        }
        fit = 1000 * cnt / (rows * cols);
        fit = (fit * fit) / 1000;
    }
    /**
* @brief Este metodo hace un init de los genes es decir coloca aleatoriamente los genes de cada individuo 
* @authors  Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*
*/
    void init(int rw, int cl)
    {
        rows = rw;
        cols = cl;
        index = indx;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) 
            {
                genes[indx][i][j][0] = rand() % 256;
                genes[indx][i][j][1] = rand() % 256;
                genes[indx][i][j][2] = rand() % 256;
            }
                
        indx++;
    }
    /**
* @brief Este metodo posee la informacion matricial de los individuos para que OpenCV puede interpretar estos 
* individuo como colores de los pixeles de la imagen
* @authors  Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*
*/
    Mat individual(Mat img)
    {
        Mat m=img;
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                m.at<Vec3b>(i,j)[0] = genes[index][i][j][0];
                m.at<Vec3b>(i, j)[1] = genes[index][i][j][1];
                m.at<Vec3b>(i, j)[2] = genes[index][i][j][2];
               
            }
        }
        return m;
    }
    /**
* @brief Este metodo hace la mutaciones de los genes, este posee metodo posee una baja posibilidad 
* @authors  Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*
*/
    void mutate()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (rand() % 100 < mutation_rate)
                    n_genes[index][i][j][0] = rand() % 256;
                    n_genes[index][i][j][1] = rand() % 256;
                    n_genes[index][i][j][2] = rand() % 256;
            }
        }
    }
};
Individual* population;
/**
* @brief Metodo que determina si un individuo tiene un mayor fitness que otro
* @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*
*/
bool s_rule(Individual a, Individual b)
{
    return a.fit > b.fit;
}

/**
* @brief Metodo que contiene la logica de crossover que se hace entre los individuos
* @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
*
*/
void crossover(int place, Individual parent_1, Individual parent_2)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int c = 0; c < 3;c++) 
            {
                if ((genes[parent_1.index][i][j][c] == target[i][j][c]) ||
                    (genes[parent_2.index][i][j][c] == target[i][j][c] ))
                {
                    if (rand() % 10 == 0)
                    {
                        n_genes[place][i][j][c] = target[i][j][c];
                       
                    }

                    else
                        goto branch;
                }
                else
                {
                branch:
                    if (rand() % 2 == 0)
                    {
                        n_genes[place][i][j][c] = genes[parent_1.index][i][j][c];
                     
                    }

                    else
                    {
                        n_genes[place][i][j][c] = genes[parent_2.index][i][j][c];
                     
                    }

                }
            }
            
        }
    }
}
int main(){
   
    srand(time(NULL));
    ImgHandler imgh;
    Mat ref;
    cout << "Enter the path of the image: ";
    string path;
    cin >> path;
    cout << "Enter the x axis of the point to cut on the image : ";
    cin >> c_x;
    cout << "Enter the y axis of the point to cut  on the image : ";
    cin >> c_y;
    Mat img = imgh.erase(imread(path), 120, 120, c_x, c_y); 
    imshow("Best individual of the generation", img);
    waitKey(0);
    Mat best;
    ref = imgh.cut_ref(imread(path), c_x-120, c_y+120, 120, 120);
    best = ref;
    rows = ref.rows;
    cols = ref.cols;
    namedWindow("Best individual of the generation",WINDOW_AUTOSIZE);
    target = new Vec3b * [rows];
    for (int i = 0; i < rows; i++)
    {
        target[i] = new Vec3b[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            target[i][j][0] = ref.at<Vec3b>(i,j)[0];
            target[i][j][1] = ref.at<Vec3b>(i, j)[1];
            target[i][j][2] = ref.at<Vec3b>(i, j)[2];
        }
    }
    population_len=130;
    mat_pool = new int[population_len * (population_len + 1) / 2];

    genes = new Vec3b * *[population_len + 10];
    n_genes = new Vec3b * *[population_len + 10];
    for (int i = 0; i < population_len + 10; i++)
    {
        genes[i] = new Vec3b * [rows];
        n_genes[i] = new Vec3b * [rows];
        for (int j = 0; j < rows; j++)
        {
            genes[i][j] = new Vec3b[cols];
            n_genes[i][j] = new Vec3b[cols];
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
  
        imshow("Best individual of the generation",  imgh.place(img,population[0].individual(best),c_x,c_y));
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