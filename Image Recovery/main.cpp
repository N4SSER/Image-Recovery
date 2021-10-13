#include <iostream>
#include "Solution.h"
using namespace std;
vector<Solution> population;
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
        population.push_back(s);
    }
}

Solution crossover(vector<Gen> parent1,vector<Gen> parent2,const int crossPoint){
    Solution offspring(parent2.size());
    int cross=crossPoint;
    for(int i = 0; i<parent1.size();i++){
        if(i==cross){
            while (i!= cross+crossPoint){
                if(i>parent1.size()){
                    break;
                }
                offspring.crossGen(parent2[i]);
                i++;
            }
            i--;
            cross+=2*crossPoint;
        }
        else{
            offspring.crossGen(parent1[i]);
        }
    }
    return offspring;
}
void mutate(){
    int mValue;
    for(auto& i : population){
        srandom((unsigned int)time(nullptr));
        mValue = random()%1000;
        if(mValue==1){
            i.getSolution()[random() %i.getSolution().size()] = Gen(random()%255,random()%255,random()%255);
        }
    }
}
int main() {
    return 0;
}
