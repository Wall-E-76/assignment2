#pragma once
#include <stdlib.h>
#include <vector>
#include <iostream>

/*static std::vector<int> ordered;

std::vector <int> bubbleSort(std::vector <int> toSort, bool flag = 0, std::vector <int>& order=ordered);*/


void bubbleSort(std::vector <int>& toSort, std::vector <int>& order);

void bubbleSort(std::vector <int>& toSort);
void mergeSort(std::vector <int>& toSort);


