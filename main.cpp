//
// Created by vince on 2022-11-04.
//
#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buffer);
int_sorted sort ( const int * begin , const int * end );

int main() {

    int_buffer testBuf = int_buffer(10);


    int_sorted testSorted = int_sorted(testBuf.begin(), 10);

    for (auto data: testSorted) {

        std::cout << data << "\n";

    }

    return 1;
}

void f(int_buffer buf) {
    int value = 1;
    for (int* i = buf.begin(); i != buf.end(); i++) {
        *i = value++;
    }

    for (const int* i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << "\n";
    }
}
int_sorted sort ( const int * begin , const int * end ) {
    if ( begin == end ) return int_sorted(nullptr,0) ;
    if ( begin == end -1 ) return int_sorted (begin,1);

    ptrdiff_t half = (end - begin)/2; // pointer diff type
    const int * mid = begin + half;
    return sort(begin,mid).merge( sort(mid,end));
}

