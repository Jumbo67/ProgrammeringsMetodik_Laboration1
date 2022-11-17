//
// Created by vince on 2022-11-04.
//
#include <iostream>
#include "int_buffer.h"

int main() {
    int_buffer test(10);

    int_buffer test2 = test;


    test2 = std::move(test);


    return 1;
}

