//
// Created by wall-e on 23/10/2019.
//
#pragma once
#include <stdlib.h>
#include <vector>
#include <iostream>

void mergeSort(std::vector <int>& toSort);
void mergeSort(std::vector <int>& toSort, std::vector <int>& order);
void mergeSort(std::vector <int>& toSort, int l, int r);
void mergeSort(std::vector <int>& toSort, int l, int r,std::vector <int>& order);
void merge(std::vector <int>& toSort, int l, int mid, int r);
void merge(std::vector <int>& toSort, int l, int mid, int r, std::vector <int>& order);
