#pragma once
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "libEx1.h"
#include <chrono>


double norm_one(double array[], int size);

double norm_infinite(double array[], int size);

std::vector <int> random_array(int size);

std::vector <int> random_light_array(int size);

std::vector <int> inverted_array(int size);

void time_one_step(int size, int i, int j, double(&norms)[104][6], std::vector <int>(*func)(int));

void performanceTest();
