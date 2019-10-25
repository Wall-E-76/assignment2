//
// Created by wall-e on 24/10/2019.
//
#include "../src/mergeSort.h"
#include "/home/wall-e/CLionProjects/assignment2/unity/src/unity.h"

void setUp(void){
}

void tearDown(void){
}

void test_mergeSort(void){
    int size = 100;
    std::vector <int> actual;
    std::vector <int> original;
    int elt;
    for (int i = 0; i < size; i++) {
        elt = rand() % size - size / 2;
        original.push_back(elt);
        actual.push_back(elt);
    }
    int expectedSize = actual.size();
    mergeSort(actual);
    TEST_ASSERT_EQUAL_INT(expectedSize, actual.size());
    for (int i = 0; i < size-1; i++){
        TEST_ASSERT_GREATER_THAN(actual[i], actual[i+1]+1);
    }
    int i = 0;
    int newSize = actual.size();
    bool hasChanged =true;
    while (hasChanged){
        hasChanged = false;
        int j =0;
        while (j < newSize && !hasChanged){
            if (actual[0]==original[j]){
                hasChanged= true;
                actual.erase(actual.begin());
                original.erase(original.begin() + j);
            }
            j++;
        }
        newSize = actual.size();
    }
    TEST_ASSERT_EQUAL_INT(0, original.size());
    TEST_ASSERT_EQUAL_INT(0, actual.size());
}

void test_mergeSortWithOrder(void){
    int size = 100;
    std::vector <int> actual;
    std::vector <int> original;
    std::vector <int> order;
    int elt;
    for (int i = 0; i < size; i++) {
        elt = rand() % size - size / 2;
        original.push_back(elt);
        actual.push_back(elt);
    }
    int expectedSize = actual.size();
    mergeSort(actual, order);
    TEST_ASSERT_EQUAL_INT(expectedSize, actual.size());
    for (int i = 0; i < size-1; i++){
        TEST_ASSERT_GREATER_THAN(actual[i], actual[i+1]+1);
    }
    for (int i = 0; i < size; i++){
        TEST_ASSERT_TRUE(actual[i] == original[order[i]]);
    }
    int i = 0;
    int newSize = actual.size();
    bool hasChanged =true;
    while (hasChanged){
        hasChanged = false;
        int j =0;
        while (j < newSize && !hasChanged){
            if (actual[0]==original[j]){
                hasChanged= true;
                actual.erase(actual.begin());
                original.erase(original.begin() + j);
            }
            j++;
        }
        newSize = actual.size();
    }
    TEST_ASSERT_EQUAL_INT(0, original.size());
    TEST_ASSERT_EQUAL_INT(0, actual.size());


}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_mergeSort);
    RUN_TEST(test_mergeSortWithOrder);
    return UNITY_END();
}