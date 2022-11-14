//
// Created by vince on 2022-11-05.
//

#include "int_buffer.h"


int_buffer::int_buffer(size_t size) {
    buffer = new int[size];
}
int_buffer::int_buffer(const int *source, size_t size) {
}

int_buffer::~int_buffer() {
    delete buffer;
}