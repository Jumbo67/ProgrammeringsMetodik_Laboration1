//
// Created by vince on 2022-11-18.
//

#ifndef C___INT_SORTED_H
#define C___INT_SORTED_H

#include "int_buffer.h"

class int_sorted {
public :
    int_sorted ( const int * source , size_t size ) ;
    size_t size () const ;
    void insert ( int value ) ;
    bool isSorted();
    const int * begin () const ;
    const int * end () const ;
    int_sorted merge ( const int_sorted &merge_with ) const ;

private:
    int_buffer buffer;

};

int_sorted sort ( const int * begin , const int * end );


#endif //C___INT_SORTED_H
