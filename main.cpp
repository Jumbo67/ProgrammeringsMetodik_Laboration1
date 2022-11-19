//
// Created by vince on 2022-11-04.
//
#include <iostream>
#include "int_buffer.h"

void f(int_buffer buffer);

int main() {

    f(int_buffer(10));

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
