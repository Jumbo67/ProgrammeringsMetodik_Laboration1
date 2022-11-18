//
// Created by vince on 2022-11-05.
//

#ifndef C___INT_BUFFER_H
#define C___INT_BUFFER_H

#include <cstdlib>
#include <iostream>


class int_buffer {

public :
    int_buffer() = delete;
    /**
     * Constructs buffer of size given by
     * @param size - Size of buffer
     */
    explicit int_buffer ( size_t size ) ; // size_t is defined in cstdlib
    int_buffer ( const int * source, size_t size);
    int_buffer ( const int_buffer & rhs ) ; // copy construct
    int_buffer ( int_buffer && rhs ) ; // move construct
    int_buffer & operator =( const int_buffer &rhs ) ; // copy assign
    int_buffer & operator =( int_buffer && rhs ) ; // move assign

    int & operator []( size_t index ) ;
    const int & operator []( size_t index ) const ;
    size_t size () const ;
    int * begin () ;
    int * end () ;
    const int * begin () const ;
    const int * end () const ;
    ~ int_buffer () ;

private:
    int* first;
    int* last;
    void swap(int_buffer& target);

};


#endif //C___INT_BUFFER_H
