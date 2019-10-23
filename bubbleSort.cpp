#include "bubbleSort.h"

void bubbleSort(std::vector <int>& toSort) {

    bool ch;
    int size = toSort.size();
    int temp;

    if (toSort.size() < 1) {
        throw "input array is too small, needs to be at least 1 items long";
    }
    do {
        ch = false;
        for (int i = 1; i < size - 1; i++) {
            if (toSort[i - 1] > toSort[i]) {
                temp = toSort[i - 1];
                toSort[i - 1] = toSort[i];
                toSort[i] = temp;
                ch = true;
            }
        }
        size--;
    } while (ch);
}

void bubbleSort(std::vector <int>& toSort, std::vector <int>& order) {

	bool ch;
	int size = toSort.size();
	int temp;

	if (!order.empty()) {
		throw "order vector is not an empty vector";
	}

	if (toSort.size() < 1) {
		throw "input array is too small, needs to be at least 1 items long";
	}

	for (int i = 0; i < size; i++) {
		order.push_back(i);
	}

	do {
		ch = 0;
		for (int i = 1; i < size - 1; i++) {
			if (toSort[i - 1] > toSort[i]) {
				temp = toSort[i - 1];
				toSort[i - 1] = toSort[i];
				toSort[i] = temp;
				ch = 1;
				temp = order[i - 1];
				order[i - 1] = order[i];
				order[i] = temp;
			}
		}
		size--;
	} while (ch == 1);
}