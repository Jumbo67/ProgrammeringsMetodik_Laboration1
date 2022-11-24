//
// Created by vince on 2022-11-04.
//
#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"
#include "algorithm"
#include "chrono"

void f(int_buffer buffer);
void selectionSort(int_buffer& buffer);
void loadValues(int_buffer& buffer);

int main() {


    srand(time(NULL));
    size_t bufferSize = 40000;
    int_buffer buffer(bufferSize);
    loadValues(buffer);

    std::chrono::duration<double> timeDuration;

    // first
   auto start = std::chrono::high_resolution_clock::now();
   int_sorted sorted = int_sorted(buffer.begin(), bufferSize);
   auto end = std::chrono::high_resolution_clock::now();

    timeDuration = end - start;
    std::cout << "Merge sort time: " << timeDuration.count() << "\n";
    loadValues(buffer);

    // second
   start = std::chrono::high_resolution_clock::now();
   std::sort(buffer.begin(), buffer.end());
   end = std::chrono::high_resolution_clock::now();

   timeDuration = end - start;

   std::cout << "std::sort time: " << timeDuration.count() << "\n";

    loadValues(buffer);
    // third
   start = std::chrono::high_resolution_clock::now();
    selectionSort(buffer);

   end = std::chrono::high_resolution_clock::now();

    timeDuration = end - start;

    std::cout << "selection sort time: " << timeDuration.count() << "\n";

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

void selectionSort(int_buffer& buffer) {
    int min_index;
    size_t size = buffer.size();

    for (int i = 0; i < size - 1; ++i) {
        min_index = i;
        for (int j = i+1; j < size; ++j) {
            if (buffer[min_index] > buffer[j]) {
                min_index = j;
            }
        }
        int tmp = buffer[min_index];
        buffer[min_index] = buffer[i];
        buffer[i] = tmp;
    }
}

void loadValues(int_buffer& buffer) {
    srand(time(NULL));
    for (int* i = buffer.begin(); i < buffer.end(); ++i) {
        *i = rand() % 10000;
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