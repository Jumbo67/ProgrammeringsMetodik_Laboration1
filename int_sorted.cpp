//
// Created by vince on 2022-11-18.
//

#include "int_sorted.h"

int_sorted::int_sorted ( const int * source , size_t size ) : buffer(source, size) {
    entryPoint = buffer.begin();
}
size_t int_sorted::size () const {
    return buffer.size();
}
void int_sorted::insert ( int value ) {
    *(entryPoint++) = value;
}
const int * int_sorted::begin () const {
    return buffer.begin();
}
const int * int_sorted::end () const {
    return buffer.end();
}
int_sorted int_sorted::merge ( const int_sorted &merge_with ) const {

    int_buffer buf(this->size() + merge_with.size());
    int_sorted sorted(buf.begin(), buf.size());

    const int* a = this->begin();
    const int* b = merge_with.begin();

    while (a != this->end() && b != merge_with.end()) {

        if (*a <= *b) {
            sorted.insert(*a);
            ++a;
        } else {
            sorted.insert(*b);
            ++b;
        }
    }

    while (a != this->end()) {
        sorted.insert(*a);
        a++;
    }
    while (b != merge_with.end()) {
        sorted.insert(*b);
        b++;
    }

    return sorted;

}