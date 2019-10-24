//
// Created by wall-e on 23/10/2019.
//

#include "mergeSort.h"

void mergeSort(std::vector <int>& toSort) {
    if (toSort.size() < 1) {
        throw "input array is too small, needs to be at least 1 items long";
    }
    mergeSort(toSort, 0, toSort.size() - 1);
}

void mergeSort(std::vector <int>& toSort, std::vector <int>& order) {
    if (toSort.size() < 1) {
        throw "input array is too small, needs to be at least 1 items long";
    }
    if (!order.empty()) {
        throw "order vector is not an empty vector";
    }
    for (int i = 0; i < toSort.size(); i++) order.push_back(i);
    mergeSort(toSort, 0, toSort.size()-1, order);
}

void mergeSort(std::vector <int>& toSort, int l, int r) {

    if (l < r) {
        int mid = ((r - l) / 2) + l;
        mergeSort(toSort, l, mid);
        mergeSort(toSort, mid + 1, r);
        merge(toSort, l, mid, r);
    }
}

void mergeSort(std::vector <int>& toSort, int l, int r,std::vector <int>& order) {

    if (l < r) {
        int mid = ((r - l) / 2) + l;
        mergeSort(toSort, l, mid, order);
        mergeSort(toSort, mid + 1, r, order);
        merge(toSort, l, mid, r, order);
    }
}

void merge(std::vector <int>& toSort, int l, int mid, int r) {
    int i, j, k;
    const int n1 = mid - l + 1;
    const int n2 = r - mid;

    std::vector<int> L;
    std::vector<int> R;

    for (i = 0; i < n1; i++)
        L.push_back(toSort[l + i]);
    for (j = 0; j < n2; j++)
        R.push_back(toSort[mid + j+1]);

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            toSort[k] = L[i];
            i++;
        }
        else
        {
            toSort[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        toSort[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        toSort[k] = R[j];
        j++;
        k++;
    }
}

void merge(std::vector <int>& toSort, int l, int mid, int r, std::vector <int>& order) {
    int i, j, k;
    const int n1 = mid - l + 1;
    const int n2 = r - mid;

    std::vector<int> L;
    std::vector<int> R;
    std::vector<int> Lo;
    std::vector<int> Ro;

    for (i = 0; i < n1; i++) {
        L.push_back(toSort[l + i]);
        Lo.push_back(order[l + i]);
    }
    for (j = 0; j < n2; j++) {
        R.push_back(toSort[mid + j + 1]);
        Ro.push_back(order[mid + j + 1]);
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            toSort[k] = L[i];
            order[k] = Lo[i];
            i++;
        }
        else
        {
            toSort[k] = R[j];
            order[k] = Ro[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        toSort[k] = L[i];
        order[k] = Lo[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        toSort[k] = R[j];
        order[k] = Ro[j];
        j++;
        k++;
    }
}




