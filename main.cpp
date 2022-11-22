//
// Created by vince on 2022-11-04.
//
#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"
#include "algorithm"
#include "random"

void f(int_buffer buffer);
void selection_sort(int_buffer& sortValues);
void loadValues(int_buffer& buffer);

int main() {

    int_buffer test(2);
    loadValues(test);

    int_sorted sorted = int_sorted(test.begin(), test.size());

    for (auto test : sorted) {
        std::cout << test << "\n";
    }

    return 1;
}


void f(int_buffer buf) {
    int value = 1;
    for (int* i = buf.begin(); i != buf.end(); i++) {
        *i = value++;
    }
    for (const int* i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << "\n";
    }
}

void selection_sort(int_buffer& sortValues) {
    for (int* begin = sortValues.begin(); begin != sortValues.end(); begin++)
    {
        int* min = std::min_element(begin, sortValues.end());
        std::iter_swap(min, begin);
    }
}

void loadValues(int_buffer& buffer) {
    srand(time(NULL));

    for (int* i = buffer.begin(); i < buffer.end(); ++i) {
        *i = rand();
    }
}

/**
*
 *
 *   size_t sizeOfBuffer = valuesToSort.size();
    int index;
    for (int i = 0; i <= sizeOfBuffer; ++i) {
        index = i;
        for (int j = i + 1; j <= sizeOfBuffer; ++j) {
            if (valuesToSort[j] < valuesToSort[index]) {
                index = j;
            }
        }
        int temp = valuesToSort[i];
        valuesToSort[i] = valuesToSort[index];
        valuesToSort[index] = temp;
    }

*/