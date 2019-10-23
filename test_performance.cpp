#include <iomanip>
#include "test_performance.h"
#define PERCENT 5


double norm_one(double array[], int size) {
    double norm = 0.0;
    for (int i = 0; i <size; i++) {
        norm += fabs(array[i]);
    }
    return norm / size;
}

double norm_infinite(double array[], int size) {
    double norm = array[0];
    for (int i = 0; i < size; i++) {
        if (norm < fabs(array[i]))
            norm = fabs(array[i]);
    }
    return norm;
}

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
        } while (a==b && size>1);
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

void time_one_step(int size, int i, int j, double (&norms)[104][6],  std::vector <int>(*func)(int), void (*sortMethod)(std::vector <int>&)){
    const int reps = 10;
    double time[reps];
    for (int rep=0; rep<reps; rep++){
        std::vector<int> result= func(size);
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        sortMethod(result);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        time[rep] = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
    }
    norms[i][j] = norm_infinite(time, reps);
    norms[i][j+1] = norm_one(time, reps);
}

void performanceTest (void (*sortMethod)(std::vector <int>&)){

    double norms[104][6];

    for (int i=0;i<100; i++){
        int j=0;
        time_one_step(i+1,i,j,norms, random_light_array, sortMethod);
		j += 2;
		time_one_step(i+1,i, j, norms, random_array, sortMethod);
		j += 2;
		time_one_step(i+1, i, j, norms, inverted_array, sortMethod);
    }

	for (int i = 3; i <= 3; i++) {
		int j = 0;
		time_one_step(pow(10,i),(97+i), j, norms, random_light_array, sortMethod);
		j += 2;
		time_one_step(pow(10, i), (97 + i), j, norms, random_array, sortMethod);
		j += 2;
		time_one_step(pow(10, i), (97 + i), j, norms, inverted_array, sortMethod);
		j = 0;
		time_one_step(pow(10, i)*2, (97 + i+1), j, norms, random_light_array, sortMethod);
		j += 2;
		time_one_step(pow(10, i)*2, (97 + i+1), j, norms, random_array, sortMethod);
		j += 2;
		time_one_step(pow(10, i)*2, (97 + i+1), j, norms, inverted_array, sortMethod);
	}

	std::cout <<" " << std::setw(20) <<"Almost"<< std::setw(20) << "Random"<< std::setw(20) << "Opposite" << std::endl;
	std::cout <<" " << std::setw(12) << "INF" << std::setw(10) << "1"<< std::setw(10) << "INF" << std::setw(10) <<"1" << std::setw(10) << "INF" << std::setw(10) << "1" << std::endl;


	for (int i = 0; i < 104; i++) {
		std::cout <<std::setw(4)<< i+1 << ": ";
		for (int j = 0; j < 6; j++) {
			std::cout << std::setw(8) << norms[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}





