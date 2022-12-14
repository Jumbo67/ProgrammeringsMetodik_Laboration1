//
// Created by vince on 2022-11-18.
//

#include "int_sorted.h"
// Merge sort
int_sorted sort ( const int * begin , const int * end ) {
    if ( begin == end ) {
        return int_sorted(nullptr, 0);
    }
    if ( begin == end - 1 ) {
        return int_sorted(begin, 1);
    }

    ptrdiff_t half = ( end - begin ) /2; //pointer diff type
    const int * mid = begin + half ;
    return sort(begin,mid).merge(sort (mid, end));
}


int_sorted::int_sorted ( const int * source , size_t size ) : buffer(nullptr, 0) {
    if ( size == 1) {
        buffer = int_buffer(source, size);
    } else if (size > 1)
        buffer = sort(source, source + size).buffer;
}

size_t int_sorted::size () const {
    return buffer.size();
}
void int_sorted::insert ( int value ) {
    int_sorted temp(&value, 1);
    *this = this->merge(temp);
}
bool int_sorted::isSorted() {
    size_t size = this->size();
    if (size == 0) return true;

    const int* index = begin()+1;

    --size;

    int prev_val = *this->begin();

    while (size) {
        if (*index < prev_val)
            return false;
        prev_val = *index;

        ++index;
        --size;
    }

    return true;
}
const int * int_sorted::begin () const {
    return buffer.begin();
}
const int * int_sorted::end () const {
    return buffer.end();
}

int_sorted int_sorted::merge ( const int_sorted &merge_with ) const {

    int_buffer buffer = int_buffer(this->size() + merge_with.size());

    const int* a = this->begin();
    const int* b = merge_with.begin();

    size_t insertPoint = 0;

    while (a != this->end() && b != merge_with.end()) {
        if (*a < *b) {
            buffer[insertPoint++] = *a;
            ++a;
        } else {
            buffer[insertPoint++] = *b;
            ++b;
        }
    }
    while (a != this->end()) {
        buffer[insertPoint++] = *a;
        ++a;
    }

    while (b != merge_with.end()) {
        buffer[insertPoint++] = *b;
        ++b;
    }

    int_sorted sortedBuffer(nullptr, 0);

    sortedBuffer.buffer = buffer;

    return sortedBuffer;

}

