//
// Created by vince on 2022-11-05.
//

#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : first(new int[size]), last(first + size) {
}
int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size) {
}

int_buffer::~int_buffer() {
    std::cout << "delete";
    delete [] first;
}
