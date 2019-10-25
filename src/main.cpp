#include "bubbleSort.h"
#include "mergeSort.h"
#include "test_performance.h"


int main() {
    /*
    std::vector <int> tester;
    std::vector <int> order;

    std::cout << "random array: " << std::endl;
        for (int i = 0; i < 20; i++) {
            tester.push_back((((i % 5) * 3) % (i+1))+i);
            std::cout << tester[i] <<", "<<i<< std::endl;
        }
        insertionSort(tester,order);
        std::cout << "\n\nsorted array: " << std::endl;
        for (int i = 0; i < 20; i++) {
            std::cout << tester[i] <<", "<<order[i]<< std::endl;
        }*/

    try {
        performanceTest(bubbleSort);
        performanceTest(mergeSort);
    }
    catch (const char* msg){
        std::cerr<< msg << std::endl;
    }
		return 0;
}

