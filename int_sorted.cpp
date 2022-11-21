//
// Created by vince on 2022-11-18.
//

#include "int_sorted.h"

int_sorted::int_sorted ( const int * source , size_t size ) : buffer(source, size) {
}
size_t int_sorted::size () const {
    return buffer.size();
}
void int_sorted::insert ( int value ) {
    int_sorted temp = int_sorted(&value, 1);
    this->buffer = this->merge(temp).buffer;
}
bool int_sorted::isSorted() {
 const int* pointer = this->begin();

}
const int * int_sorted::begin () const {
    return buffer.begin();
}
const int * int_sorted::end () const {
    return buffer.end();
}
int_sorted int_sorted::merge ( const int_sorted &merge_with ) const {

    int_buffer tmpbuf = int_buffer(this->size() + merge_with.size());

    const int* a = this->begin();
    const int* b = merge_with.begin();

    size_t insertPoint = 0;

    while (a != this->end() && b != merge_with.end()) {

        if (*a < *b) {
            tmpbuf[insertPoint++] = *a;
            ++a;
        } else {
            tmpbuf[insertPoint++] = *b;
            ++b;
        }

    }

    while (a != this->end()) {
        tmpbuf[insertPoint++] = *a;
        ++a;
    }

    while (b != merge_with.end()) {
        tmpbuf[insertPoint++] = *b;
        ++b;
    }

    int_sorted sortedBuffer = int_sorted(tmpbuf.begin(), tmpbuf.size());

    return sortedBuffer;

}