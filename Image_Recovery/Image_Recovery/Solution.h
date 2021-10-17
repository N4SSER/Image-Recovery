#pragma once
#include <vector>
#include "Gen.h"
class Solution {
private:
    std::vector<Gen> solution;
public:
    int length;
    Gen getGen(int i);
    explicit Solution(int lenght);
    void create();
    void crossGen(Gen g);
    void addGen(float r, float g, float b);
    std::vector <Gen> individual();
};


