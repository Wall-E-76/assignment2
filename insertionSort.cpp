//
// Created by wall-e on 23/10/2019.
//

#include "insertionSort.h"

void insertionSort(std::vector <int>& toSort)
{

    if (toSort.size() < 1) {
        throw "input array is too small, needs to be at least 1 items long";
    }
    int i, key, j;
    for (i = 1; i < toSort.size(); i++)
    {
        key = toSort[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && toSort[j] > key)
        {
            toSort[j + 1] = toSort[j];
            j = j - 1;
        }
        toSort[j + 1] = key;
    }
}

void insertionSort(std::vector <int>& toSort, std::vector <int>& order)
{

    if (toSort.size() < 1) {
        throw "input array is too small, needs to be at least 1 items long";
    }
    if (!order.empty()) {
        throw "order vector is not an empty vector";
    }
    for (int i = 0; i < toSort.size(); i++) order.push_back(i);

    int i, key, j, keyO;
    for (i = 1; i < toSort.size(); i++)
    {
        key = toSort[i];
        keyO = order[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && toSort[j] > key)
        {
            toSort[j + 1] = toSort[j];
            order[j+1] = order[j];
            j = j - 1;
        }
        toSort[j + 1] = key;
        order[j+1] = keyO;
    }
}