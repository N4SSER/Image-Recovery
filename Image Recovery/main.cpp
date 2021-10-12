#include <iostream>
#include "Solution.h"
#include <list>
using namespace std;
list<vector<Gen>> nPop;
vector<vector<Gen>> population;
float fitness_func(vector<Gen> sol,int l,vector<Gen> ref){
    float fit = 0;
    for(int i =0; i<l;i++){
        fit+=(abs(sol[i].r-ref[i].r)/255 + abs(sol[i].g-ref[i].g)/255+abs(sol[i].b-ref[i].b)/255)/3 ;
    }
    return fit;
}
void initPopulation(int lP,int lS){
    for (int i = 0; i<lP;i++){
        Solution s(lS);
        s.create();
        population.push_back(s.getSolution());
    }
}

vector<Gen> crossover(vector<Gen> parent1,vector<Gen> parent2){
    int crossPoint = parent1.size()/2 ;
    vector<Gen> offspring;
    int cross=crossPoint;
    for(int i = 0; i<parent1.size();i++){
        if (i==cross){
            for(int c = i; c<crossPoint+i;c++){
                offspring.push_back(parent2[i]);
            }
            cross+=crossPoint;
            i+=crossPoint;
        }
        else{
            offspring.push_back(parent1[i]);
        }
    }
    return offspring;
}
int main() {
    //initPopulation(10000,10000);
    //Solution ref(10000);
    //ref.create();
    //for(auto & i : population){
   //     cout<<fitness_func(i, i.size(),ref.getSolution())<<endl;
   // }
    return 0;
}
