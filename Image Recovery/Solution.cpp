//
// Created by n4ssser on 9/10/21.
//
#include <iostream>
#include "Solution.h"
Solution::Solution(int lenght) {
    this->lenght = lenght;
}
void Solution::create() {
    for(int i  = 0; i<lenght;i++){
        srandom((unsigned int)time(nullptr));
        Gen g(random() % 255,random() % 255,random() % 255);
        solution.push_back(g);
    }
}

Gen Solution::getGen(int i) {
    return solution[i];
}

void Solution::crossGen(Gen g) {
    solution.push_back(g);
}

std::vector<Gen> Solution::getSolution() {
    return solution;
}
