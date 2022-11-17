//
// Created by vince on 2022-11-05.
//

#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : first(new int[size]), last(first + size) {
}
int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size) {
}
// Copy Ctor
int_buffer::int_buffer ( const int_buffer & rhs ) {

}
// Move assignment
int_buffer & int_buffer::operator =( int_buffer && rhs ) {
    swap(rhs);
    rhs.first = nullptr;
    rhs.last = nullptr;
}

int_buffer::~int_buffer() {
    std::cout << "delete" << "\n";
    delete [] first;
}

void int_buffer::swap(int_buffer& target) {
    first = target.first;
    last = target.last;
}

