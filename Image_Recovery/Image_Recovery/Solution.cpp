#include "Solution.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include "Gen.h"
Solution::Solution(int lenght)
{
    this->length = lenght;
}
void Solution::create() 
{

    for (int i = 0; i < length;i++) {
        
        float r = rand() % 255;
        float g= rand() % 255;
        float b= rand() % 255;
        Gen gen(r,g, b);
        solution.push_back(gen);
    }
}

Gen Solution::getGen(int i)
{
    return solution[i];
}

void Solution::crossGen(Gen g)
{
    solution.push_back(g);
}

void Solution::addGen(float r, float g, float b)
{
    Gen gen(r, g, b);
    solution.push_back(gen);
}

std::vector<Gen> Solution::individual()
{
    return solution;
}