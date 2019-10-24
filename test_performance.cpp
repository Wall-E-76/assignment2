#include <iomanip>
#include "test_performance.h"
#define PERCENT 5 //percent of mixing based on size, for our lightly sorted array
#define USERANGE 0 //flag variable to indicate whether or not we are using a defined RANGE, 0 is OFF
#define RANGE 1  //number of ints possible (from 0 to RANGE-1)
#define RANGEOFFSET 0 // to shift the contiguous range
#define SUBSIZE 1 //for sorted_subs(), the size of the pre-sorted subranges 


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

std::vector <int> index_array(int size) {  //NEW, creates a sorted array of either values 0 to size or 0 to RANGE-1,,,, both of length size
	std::vector <int> ans;
	if (USERANGE == 0) {
		for (int i = 0; i < size; i++) {
			ans.push_back(i);
		}
	}
	else if (USERANGE == 1) {
		int num = size / RANGE; //length of subrange of same values
		if (size % RANGE > 0 ) num++; //we want the ceiling, a rounding up division, because we want to have a possibly smaller subrange last rather than going over our RANGE limit 
		int counter = 0; //will count each loop and reset once we've reached our desired repitions of the same number
		int val = 0; //the actual value we will put in the array, from 0 to RANGE-1
		
		for (int i = 0; i < size; i++) {
			if (counter == num) {
				val++;
				counter = 0;
			}
			ans.push_back(val);
			counter++;
		}
	}
	return ans;
}

std::vector <int> random_array(int size){ //MODIFIED contents
    std::vector <int> ans;
	if (USERANGE == 0) {
		for (int i = 0; i < size; i++) {
			ans.push_back(rand() % size - size / 2);
		}
	}
	else if (USERANGE == 1) {
		for (int i = 0; i < size; i++) {
			ans.push_back((rand() % RANGE )+RANGEOFFSET);
		}
	}
    return ans;
}

std::vector <int> sorted_subs(int size) {  //NEW, creates array with unique pre-sorted sub arrays (each of length SUBSIZE)
	std::vector <int> ans;
	std::vector <int> order = index_array(size);
	int num = size / SUBSIZE;
	int extra = size % SUBSIZE;

	for (int i = 0; i < num; i++) {
		int max; int min = 0;
		for (int j = SUBSIZE; j >0; j--) {
			max= order.size() - j+1 -min; //number of values that can be selected 
			int rando = (rand() % (max))+min; //new random index above the minimum
			ans.push_back(order[rando]); 
			order.erase(order.begin()+rando); //remove this index so it can not be selected again
			min = rando; //new minimum set at this index so next value in the array is above it
		}
	}
	for (int i = 0; i < extra; i++) {
		ans.push_back(order[i]); //remaining values filled in order (this sub array is tagged on at the end and is less than SUBSIZE)
	}
	return ans;
}

std::vector <int> random_light_array(int size){ //MODIFIED contents
    std::vector <int> ans = index_array(size);

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

std::vector <int> inverted_array(int size){ //posibbly make this part of the index_Array(), then set global BOOL var?
    std::vector <int> ans;
    for (int i=size-1; i>=0; i--){
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





