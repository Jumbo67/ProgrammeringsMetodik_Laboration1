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

}
const int * int_sorted::begin () const {
    return buffer.begin();
}
const int * int_sorted::end () const {
    return buffer.end();
}
int_sorted int_sorted::merge ( const int_sorted &merge_with ) const {

}