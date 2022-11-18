//
// Created by vince on 2022-11-05.
//

#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : first(new int[size]), last(first + size) {
}
int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size) {
    *first = *source;
}
// Copy Ctor
int_buffer::int_buffer ( const int_buffer & rhs ) : int_buffer(rhs.first, rhs.last) {
    std::cout << "Copy ctor" << "\n";
}

int_buffer::int_buffer ( int_buffer && rhs ): first(nullptr), last(nullptr) {
    std::cout << "Move ctor" << "\n";
    swap(rhs);
}

// Move assignment
int_buffer &int_buffer::operator =( int_buffer && rhs ) {
    std::cout << "Move assign" << "\n";
    swap(rhs);
    return *this;
}

int & int_buffer::operator []( size_t index )  {
    return *(first + index);
}
const int & int_buffer::operator []( size_t index ) const {
    return *(first + index);
}

int_buffer::int_buffer (int* first, int* last) : int_buffer(std::distance(first, last)) {
    auto target = this->first;
    std::copy(first, last, target);
}

int_buffer::~int_buffer() {
    std::cout << "delete" << "\n";
    delete [] first;
}

size_t int_buffer::size () const {
    return std::distance(first, last);
}
void int_buffer::swap(int_buffer& target) {
  std::swap(first, target.first);
  std::swap(last, target.last);
}
int * int_buffer::begin (){
    return first;
}
int * int_buffer::end () {
    return last;
}
const int * int_buffer::begin () const {
    return first;
}
const int * int_buffer::end () const {
    return last;
}

