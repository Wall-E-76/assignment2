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
    TEST_ASSERT_EQUAL_HEX8(3, 3);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_mergeSort);
    return UNITY_END();
}