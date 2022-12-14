//
// Created by vince on 2022-11-05.
//

#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : first(new int[size]()), last(first + size) {
}
int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size) {
std::copy(source, source+size, this->first);
}
// Copy Ctor
int_buffer::int_buffer ( const int_buffer & rhs ) : int_buffer(rhs.first, rhs.size()) {
}

int_buffer::int_buffer ( int_buffer && rhs ) : first(nullptr), last(nullptr){
    swap(rhs);
}

int_buffer & int_buffer::operator =( const int_buffer &rhs ) {
    int_buffer copy(rhs);
    swap(copy);
    return *this;
}
// Move assignment
int_buffer &int_buffer::operator =( int_buffer && rhs ) {
    swap(rhs);
    return *this;
}

int & int_buffer::operator []( size_t index )  {
    return *(first + index);
}
const int & int_buffer::operator []( size_t index ) const {
    return *(first + index);
}

int_buffer::~int_buffer() {
    delete [] first;
}

size_t int_buffer::size () const {
    return std::distance(first, last);
}

void int_buffer::swap(int_buffer& target) {
  std::swap(this->first, target.first);
  std::swap(this->last, target.last);
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
