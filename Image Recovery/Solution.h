//
// Created by n4ssser on 9/10/21.
//
#include <vector>
#include "Gen.h"
#ifndef IMAGE_RECOVERY_SOLUTION_H
#define IMAGE_RECOVERY_SOLUTION_H


class Solution {
private:
    std::vector<Gen> solution;
public:
    int lenght;
    Gen getGen(int i);
    explicit Solution(int lenght);
    void create();
    void crossGen(Gen g);
    std::vector <Gen> getSolution();
};


#endif //IMAGE_RECOVERY_SOLUTION_H
