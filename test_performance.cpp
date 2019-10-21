#include <vector>
#include <cmath>
#include "stdlib.h"
#include "libEx1.h"
#include <chrono>
#define PERCENT 5

std::vector <int> random_array(int size){
    std::vector <int> ans;
    for (int i=0; i<size; i++){
        ans.push_back(rand()%size -size/2);
    }
    return ans;
}


std::vector <int> random_light_array(int size){
    std::vector <int> ans;
    for (int i=1; i<=size; i++){
        ans.push_back(i);
    }

    for (int i=0; i<ceil((PERCENT/100.)*size);i++){
        int a= rand()%size;
        int b;
        do {
            b= rand()%size;
        } while (a==b);
        int temp;
        temp = ans[a];
        ans[a] = ans[b];
        ans[b] = temp;
    }
    return ans;
}

std::vector <int> inverted_array(int size){
    std::vector <int> ans;
    for (int i=size; i>0; i--){
        ans.push_back(i);
    }
    return ans;
}

void time_one_step(int i, int j, double (&norms)[104][6],  std::vector <int>(*func)(int)){
    int reps = 10;
    double time [reps];
    for (int rep=0; rep<reps; rep++){
        std::vector<int> result= func(i);
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        bubbleSort(result);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        time[rep] = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
    }
    norms[i][j] = norme_one(time);
    norms[i][j+1] = norme_inifinite(time);
}

void performanceTest (){


    double norms[104][6];

    for (int i=1;i<100; i++){
        for (int j=0; j<6; j+2){
            time_one_step(i,j,norms, random_light_array);
        }
    }

}





