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
    int_sorted temp(&value, 1);
    *this = this->merge(temp);
}
bool int_sorted::isSorted() {
    size_t size = this->size();
    const int* index = begin();
    if (size == 0) return true;

    int prev_val = *this->begin();

    while (size) {
        if (*index < prev_val)
            return false;
        prev_val = *index;

        ++index;
        --size;
    }

    return true;

return true;
}
const int * int_sorted::begin () const {
    return buffer.begin();
}
const int * int_sorted::end () const {
    return buffer.end();
}

void int_sorted::selection_sort() {

    size_t sizeOfBuffer = this->size();
    int index;
    for (int i = 0; i <= sizeOfBuffer; ++i) {
        index = i;
        for (int j = i + 1; j <= sizeOfBuffer; ++j) {
            if (buffer[j] < buffer[index]) {
                index = j;
            }
        }
        int temp = buffer[i];
        buffer[i] = buffer[index];
        buffer[index] = temp;
    }
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